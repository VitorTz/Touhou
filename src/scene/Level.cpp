#include "../../include/scene/Level.hpp"


th::Level::Level(
    const th::ChangeScene& changeScene 
) : th::Scene(th::SceneId::LevelScene, changeScene) {
    th::Ecs::gameObjPool->insert(
        "Player",
        1,
        {th::GroupId::CameraGroup},
        std::make_unique<th::Player>()
    );
}


void th::Level::update(const float dt) {
    th::Ecs::gameObjPool->update(dt);
}


void th::Level::draw(sf::RenderWindow& window) {
    th::Camera* camera = (th::Camera*) th::Ecs::groupPool->at(th::GroupId::CameraGroup);
    camera->draw(window);
}