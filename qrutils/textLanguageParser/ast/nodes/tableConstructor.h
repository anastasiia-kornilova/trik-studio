#pragma once

#include "qrutils/textLanguageParser/ast/nodes/expression.h"
#include "qrutils/textLanguageParser/ast/nodes/fieldInitialization.h"

namespace textLanguageParser {
namespace ast {

class QRUTILS_EXPORT TableConstructor : public Expression {
public:
	TableConstructor(QList<QSharedPointer<FieldInitialization>> const &initializers)
		: mInitializers(initializers)
	{
	}

	QList<QSharedPointer<FieldInitialization>> const &initializers() const
	{
		return mInitializers;
	}

	QList<QSharedPointer<Node>> children() const override
	{
		return as<ast::Node>(mInitializers);
	}

private:
	QList<QSharedPointer<FieldInitialization>> mInitializers;
};

}
}
