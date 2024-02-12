#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "../ecs/Ecs.hpp"
#include "../ecs/components.hpp"


namespace th {

    enum SceneId {
        LevelScene
    };

    const th::SceneId mainScene = th::SceneId::LevelScene;

    typedef std::function<void(th::SceneId)> ChangeScene;

    class Scene {

        public:
            const th::SceneId id;

        protected:
            const th::ChangeScene& changeScene;
        
        public:
            Scene(
                th::SceneId id, 
                const th::ChangeScene& changeScene
            ) : id(id), changeScene(changeScene) { }
            virtual ~Scene() = default;
            virtual void update([[maybe_unused]] float dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }

    };
    
} // namespace th


