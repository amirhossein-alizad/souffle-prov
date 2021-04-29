#pragma once

#include "souffle/RamTypes.h"
#include "interpreter/Relation.h"
#include <queue>
#include <vector>
#include "souffle/utility/StringUtil.h"
#include "ast2ram/utility/Utils.h"

namespace souffle::interpreter {

class OrderingTuple {
public:
    OrderingTuple(const RamDomain prov) : semprovValue(prov) {}

    RamDomain semprovValue;

    //virtual void insert();

    virtual const std::string& getName() const = 0; // { 
	    //std::cout << "In virtual getName()" << std::endl;
	    //return "OrderingTupleVirtual getName()"; 
    //};

    virtual bool customInsert() = 0;
};

struct OTComparator {
    bool operator() (const Own<OrderingTuple>& lhs, const Own<OrderingTuple>& rhs) {
        return (unsigned int) lhs->semprovValue < (unsigned int) rhs->semprovValue;
    } 
};

template<typename T> class AnnotatedTuple : public OrderingTuple {
    using RelationHandle = Own<RelationWrapper>;

public:
    AnnotatedTuple<T>(const RamDomain prov) : OrderingTuple(prov) {}

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
    //RamDomain semprovValue;
    T* rel;

    //void insert() override {
    //    rel->insert(&tuple[0]);	    
    //}

    bool isInNewRel() {
        return isPrefix("@new_", rel->getName());
    
    }

    bool customInsert() {
        // create the new full tuple
	tuple.push_back(semprovValue);
	this->rel->insert(&this->tuple[0]);
        // TODO insert in delta relation
	//std::cout << souffle::ast2ram::getDeltaRelationName(rel->getName()) << std::endl;
	return true;
    }

    const std::string& getName() const override {
	std::cout << "In getName()" << std::endl;
	std::cout << rel->getName() << std::endl;
        return rel->getName();
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
