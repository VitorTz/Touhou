#pragma once
#include <vector>
#include <set>
#include "GameObj.hpp"


namespace th {


    enum GroupId {        
        CollideGroup,
        CameraGroup
    };

    const std::vector<th::GroupId> groupsIds = {        
        th::GroupId::CollideGroup        
    };


    class Group {

        public:
            const th::GroupId id;
        
        private:
            std::set<th::GameObj*> objs;
        
        public:
            Group(const th::GroupId id) : id(id) { }
            virtual ~Group() = default;
            virtual void insert(th::GameObj* obj) { objs.insert(obj); };            
            virtual void erase(th::GameObj* obj) { objs.erase(obj); };
            virtual void clear() { objs.clear(); };
            virtual std::set<th::GameObj*>* getAll() { return &objs; }            
            std::size_t size() const { return objs.size(); }

    };
    
} // namespace th
