#pragma once

#include "souffle/RamTypes.h"
#include "interpreter/Relation.h"
#include <queue>
#include <vector>
#include "souffle/utility/StringUtil.h"

namespace souffle::interpreter {

template<typename T> class AnnotatedTuple {
    using RelationHandle = Own<RelationWrapper>;

public:
    AnnotatedTuple<T>(const RamDomain prov) : semprovValue(prov) {}

    RamDomain& operator[](std::size_t index) {
        if (index >= tuple.size()) {
	    tuple.resize((index+1));
	}
	return tuple[index];
    }

    RamDomain operator[](std::size_t index) const {
        return tuple[index];
    }
	
    std::vector<RamDomain> tuple;
    RamDomain semprovValue;
    T* rel;

    bool isInNewRel() {
        return isPrefix("@new_", rel->getName());
    }
    
    /*bool operator< (const AnnotatedTuple &right) {
        return this->semprovValue > right.semprovValue;
    }*/
};

//auto cmp = [](AnnotatedTuple left, AnnotatedTuple right) { return left.semprovValue < right.semprovValue; };

/*class SemprovQueueManager {

public:
    SemprovQueueManager()  {}
	
    std::priority_queue<AnnotatedTuple, std::vector<AnnotatedTuple>, std::less<std::vector<AnnotatedTuple>::value_type> > sp_pq;
};*/

} // namescpace souffle:interpreter
