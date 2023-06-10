#include "../../include/scene/scene.hpp"


th::Scene::Scene(th::Window* touhouWindow) {
    this->touhouWindow = touhouWindow;
    this->name = "Scene";
}

th::Scene::Scene(th::Window* touhouWindow, std::string name) {
    this->touhouWindow = touhouWindow;
    this->name = name;
}

th::Scene::~Scene() {
    
}
