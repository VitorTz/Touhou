#pragma once
#include "Group.hpp"
#include "../window/Camera.hpp"


namespace th::Ecs {

    class GroupPool {

        private:
            std::map<th::GroupId, std::unique_ptr<th::Group>> groupMap;
            std::map<th::GameObj*, std::set<th::GroupId>> groupByGameObj;
        
        public:
            GroupPool();
            void addToGroup(th::GameObj* gameObj, th::GroupId id);
            void rmvFromGroup(th::GameObj* gameObj, th::GroupId id);            
            void rmvGameObj(th::GameObj* gameObj);
            th::Group* at(th::GroupId id);
            std::set<th::GroupId>* getGroupsByGameObj(th::GameObj* gameObj);
            void clear();
            bool collideGroup(th::GameObj* gameObj, th::GroupId id);

    };



    class GameObjPool {

        private:
            std::map<std::string, std::unique_ptr<th::GameObj>> allObjs;
            
        public:
            GameObjPool() = default;
            th::GameObj* insert(
                const std::string& name,
                int zIndex,
                const std::vector<th::GroupId>& groups
            );
            th::GameObj* insert(
                const std::string& name,
                int zIndex,
                const std::vector<th::GroupId>& groups,
                std::unique_ptr<th::Component> component
            );
            th::GameObj* at(const std::string& name);
            void erase(th::GameObj* gameObj);
            void erase(const std::string& name);
            void update(float dt);
            void clear();
            std::size_t size() const;

    };

    extern std::unique_ptr<th::Ecs::GroupPool> groupPool;
    extern std::unique_ptr<th::Ecs::GameObjPool> gameObjPool;
    
} // namespace th
