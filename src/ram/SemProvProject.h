#pragma once

#include "ram/Node.h"
#include "ram/Operation.h"
#include "souffle/utility/StreamUtil.h"
#include <cassert>
#include <ostream>

namespace souffle::ram {

class SemProvProject : public Operation {
public:
    SemProvProject() {}

    SemProvProject* clone() const override {
        return new SemProvProject();
    }

protected:
    void print(std::ostream& os, int tabpos) const override {
	os << times(" ", tabpos);
        os << "ADD best_tuple IN best_tuple.relation() and delta_relation"<< std::endl;
    } 

    //bool equal(const Node& node) const override {
	//const auto& other = asAssert<SemProvProject>(node);
        //return true;
    //}
};

} // namespace souffle::ram
