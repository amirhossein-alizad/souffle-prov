/************************************************************************
 *
 * @file ClauseTranslator.h
 *
 ***********************************************************************/

#pragma once

#include "ast2ram/seminaive/ClauseTranslator.h"
#include <vector>

namespace souffle::ast {
class Atom;
class Clause;
}  // namespace souffle::ast

namespace souffle::ram {
class Operation;
}

namespace souffle::ast2ram {
class TranslatorContext;
}

namespace souffle::ast2ram::semprov {

class ClauseTranslator : public ast2ram::seminaive::ClauseTranslator {
public:
    ClauseTranslator(const TranslatorContext& context) : ast2ram::seminaive::ClauseTranslator(context) {}

protected:
    Own<ram::Operation> addNegatedDeltaAtom(Own<ram::Operation> op, const ast::Atom* atom) const override;
    Own<ram::Operation> addNegatedAtom(
            Own<ram::Operation> op, const ast::Clause& clause, const ast::Atom* atom) const override;
    Own<ram::Operation> createProjection(const ast::Clause& clause) const override;
    void indexAtoms(const ast::Clause& clause) override;
    Own<ram::Operation> addAtomScan(Own<ram::Operation> op, const ast::Atom* atom, const ast::Clause& clause,
            int curLevel) const override;

private:
    Own<ram::Expression> getSemprovValue(const ast::Clause& clause) const;
};

}  // namespace souffle::ast2ram::provenance
