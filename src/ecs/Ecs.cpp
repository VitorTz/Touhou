#include "../../include/ecs/Ecs.hpp"


std::unique_ptr<th::Ecs::GroupPool> th::Ecs::groupPool = std::make_unique<th::Ecs::GroupPool>();

std::unique_ptr<th::Ecs::GameObjPool> th::Ecs::gameObjPool = std::make_unique<th::Ecs::GameObjPool>();


th::Ecs::GroupPool::GroupPool() {
    for (const th::GroupId id : th::groupsIds) {
        groupMap.insert({id, std::make_unique<th::Group>(id)});
    }
    groupMap.insert({th::GroupId::CameraGroup, std::make_unique<th::Camera>()});
}



void th::Ecs::GroupPool::addToGroup(th::GameObj* gameObj, const th::GroupId id) {
    groupMap.at(id)->insert(gameObj);
    if (groupByGameObj.find(gameObj) == groupByGameObj.end()) {
        groupByGameObj.insert({gameObj, {}});
    }
    groupByGameObj.at(gameObj).insert(id);
}


void th::Ecs::GroupPool::rmvFromGroup(th::GameObj* gameObj, const th::GroupId id) {
    groupMap.at(id)->erase(gameObj);
    groupByGameObj.at(gameObj).erase(id);
}


void th::Ecs::GroupPool::rmvGameObj(th::GameObj* gameObj) {
    groupByGameObj.erase(gameObj);
}


th::Group* th::Ecs::GroupPool::at(th::GroupId id) {
    return groupMap.at(id).get();
}


std::set<th::GroupId>* th::Ecs::GroupPool::getGroupsByGameObj(th::GameObj* gameObj) {
    return &groupByGameObj.at(gameObj);
}


bool th::Ecs::GroupPool::collideGroup(th::GameObj* gameObj, const th::GroupId id) {
    for (th::GameObj* other : *groupMap.at(id)->getAll()) {
        if (gameObj->transform.collideWithShrink(other->transform)) {
            return true;
        }
    }     
    return false;
}


void th::Ecs::GroupPool::clear() {
    groupByGameObj.clear();
    groupMap.clear();
}


th::GameObj* th::Ecs::GameObjPool::insert(
    const std::string& name,
    const int zIndex,
    const std::vector<th::GroupId>& groups = std::vector<th::GroupId>()
) {
    const auto& [pair, success] = allObjs.insert(
        {name, std::make_unique<th::GameObj>(name, zIndex)}
    );
    th::GameObj* gameObj = pair->second.get();
    for (const th::GroupId id : groups) {
        th::Ecs::groupPool->addToGroup(gameObj, id);
    }
    return gameObj;
}


th::GameObj* th::Ecs::GameObjPool::insert(
    const std::string& name,
    const int zIndex,
    const std::vector<th::GroupId>& groups,
    std::unique_ptr<th::Component> component
) {
    const auto& [pair, success] = allObjs.insert(
        {name, std::make_unique<th::GameObj>(name, zIndex)}
    );
    th::GameObj* gameObj = pair->second.get();    
    for (const th::GroupId id : groups) {
        th::Ecs::groupPool->addToGroup(gameObj, id);
    }
    gameObj->addComponent(std::move(component));
    return gameObj;
}


th::GameObj* th::Ecs::GameObjPool::at(const std::string& name) {
    return allObjs.at(name).get();
}


void th::Ecs::GameObjPool::erase(th::GameObj* gameObj) {
    for (const th::GroupId id : *th::Ecs::groupPool->getGroupsByGameObj(gameObj)) {
        th::Ecs::groupPool->at(id)->erase(gameObj);        
    }
    th::Ecs::groupPool->rmvGameObj(gameObj);
    allObjs.erase(gameObj->name);
}


void th::Ecs::GameObjPool::erase(const std::string& name) {
    erase(allObjs.at(name).get());
}


std::size_t th::Ecs::GameObjPool::size() const {
    return allObjs.size();
}


void th::Ecs::GameObjPool::update(const float dt) {
    for (const auto& [name, gameObj] : allObjs) {
        gameObj->update(dt);
    }
}


void th::Ecs::GameObjPool::clear() {
    allObjs.clear();
}