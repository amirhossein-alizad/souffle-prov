/************************************************************************
 *
 * @file TranslationStrategy.h
 *
 * Implementation of the provenance evaluation strategy.
 *
 ***********************************************************************/

#pragma once

#include "ast2ram/TranslationStrategy.h"
#include "souffle/utility/ContainerUtil.h"

namespace souffle::ast2ram {
class ClauseTranslator;
class ConstraintTranslator;
class UnitTranslator;
class TranslatorContext;
class ValueIndex;
class ValueTranslator;
}  // namespace souffle::ast2ram

namespace souffle::ast2ram::semprov {

class TranslationStrategy : public ast2ram::TranslationStrategy {
public:
    std::string getName() const override {
        return "SemProvEvaluation";
    }

    ast2ram::UnitTranslator* createUnitTranslator() const override;
    ast2ram::ClauseTranslator* createClauseTranslator(const TranslatorContext& context) const override;
    ast2ram::ConstraintTranslator* createConstraintTranslator(
            const TranslatorContext& context, const ValueIndex& index) const override;
    ast2ram::ValueTranslator* createValueTranslator(
            const TranslatorContext& context, const ValueIndex& index) const override;
};

}  // namespace souffle::ast2ram::provenance
