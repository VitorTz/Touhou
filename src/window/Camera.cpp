#include "../../include/window/Camera.hpp"


th::Camera::Camera() : th::Group(th::GroupId::CameraGroup) { }


void th::Camera::insert(th::GameObj* obj) {
    const int zIndex = obj->zIndex;
    if (objMap.find(zIndex) == objMap.end()) {
        objMap.insert({zIndex, {}});
    }
    objMap.at(zIndex).push_back(obj);    
}


void th::Camera::erase(th::GameObj* obj) {
    std::vector<th::GameObj*>& v = objMap.at(obj->zIndex);
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v[i] == obj) {
            v.erase(v.begin() + i);
            return;
        }
    }
}


void th::Camera::clear() {
    objMap.clear();
}



void th::Camera::draw(sf::RenderWindow& window) {
    for (auto& [index, objs] : objMap) {        
        for (th::GameObj* obj : objs) {
            obj->draw(window);   
        }
    }
}