/*
 * Custom EmptinessCheck for the priority queue used for Knuth's algorithm
 * SemProv
 */

#pragma once

#include "ram/Condition.h"
#include "ram/Node.h"
#include "cassert"
#include "sstream"

namespace souffle::ram {

class PQEmptyCheck : public Condition {
public:
    PQEmptyCheck() {}

    PQEmptyCheck* clone() const override {
        return new PQEmptyCheck();
    }
protected:
    void print(std::ostream& os) const override {
        os << "(priority_queue is empty?)";
    }

    //bool equal(const Node& node) const override {
        //const auto& other = asAssert<PQEmptyCheck>(node);
	//return true;
    //}
};

} // namespace souffle::ram
