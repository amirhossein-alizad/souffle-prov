/************************************************************************
 *
 * @file ConstraintTranslator.h
 *
 ***********************************************************************/

#pragma once

#include "ast2ram/seminaive/ConstraintTranslator.h"
#include "souffle/utility/ContainerUtil.h"

namespace souffle::ast {
class Literal;
class Negation;
}  // namespace souffle::ast

namespace souffle::ram {
class Condition;
}

namespace souffle::ast2ram {
class TranslatorContext;
class ValueIndex;
}  // namespace souffle::ast2ram

namespace souffle::ast2ram::semprov {

class ConstraintTranslator : public ast2ram::seminaive::ConstraintTranslator {
public:
    ConstraintTranslator(const TranslatorContext& context, const ValueIndex& index)
            : ast2ram::seminaive::ConstraintTranslator(context, index) {}

    Own<ram::Condition> translateConstraint(const ast::Literal* lit) override;

    /** -- Visitors -- */
    Own<ram::Condition> visit_(type_identity<ast::Negation>, const ast::Negation& neg) override;
};

}  // namespace souffle::ast2ram::provenance
