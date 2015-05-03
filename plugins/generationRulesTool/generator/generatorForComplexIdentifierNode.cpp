#include "generatorForComplexIdentifierNode.h"
#include "generatorForElementIdentifierNode.h"

#include "ast/identifier.h"
#include "ast/transitionEnd.h"

using namespace generationRules::generator;
using namespace simpleParser::ast;

QString GeneratorForComplexIdentifierNode::generatedResult(QSharedPointer<ComplexIdentifier> complexIdentifierNode
		, qReal::LogicalModelAssistInterface *logicalModelInterface
		, VariablesTable tableOfVariables
		, qReal::EditorManagerInterface *editorManagerInterface
		, const qReal::Id elementId
		, const QString &elementType
		, const QString &elementName)
{
	Q_UNUSED(elementType);
	Q_UNUSED(editorManagerInterface);

	auto identifierPart = qrtext::as<Identifier>(complexIdentifierNode->identifierPart());
	auto propertyPart = qrtext::as<Identifier>(complexIdentifierNode->propertyPart());

	return logicalModelInterface->propertyByRoleName(elementId, propertyPart->name()).toString();
//	if (!complexIdentifierNode->propertyPart()) {
//		// it is type node for callGeneratorFor node
//	} else {
//		auto secondPart = complexIdentifierNode->secondPartOfComplexIdentifier();

//		if (secondPart->is<Identifier>()) {
//			// it is property

//			auto asIdentifier = qrtext::as<Identifier>(secondPart);
//		} else if (secondPart->is<TransitionEnd>()) {
//			auto asTransitionEnd = qrtext::as<TransitionEnd>(secondPart);

//		}
//	}

//	// this node can be identifier or type name.
//	auto elementOrTypeNode = qrtext::as<Identifier>(complexIdentifierNode->firstPartOfComplexIdentifier());
//	auto currentElementOrTypeName = elementOrTypeNode->name();

//	// this node can be property or pair of (linkEndType, property)
//	auto secondNode = complexIdentifierNode->secondPartOfComplexIdentifier();

//	if (secondNode->is<Identifier>()) {
//		auto property = qrtext::as<Identifier>(secondNode)->name();

//		if (elementName == currentElementOrTypeName) {
//			return generatedResultForNodeWithBasicName(elementId, logicalModelInterface, property);
//		} else {
//			if (tableOfVariables.containsVariable(currentElementOrTypeName)) {
//				return generatedResultForOtherVariable(currentElementOrTypeName, logicalModelInterface, property);
//			} else {
//				return generatedResultForNodeWithUniqueType(logicalModelInterface, currentElementOrTypeName, property);
//			}
//		}
//	} else {
//		if (secondNode->is<TransitionEnd>()) {
//			auto asTransitionEnd = qrtext::as<TransitionEnd>(secondNode);
//			auto propertyNode = qrtext::as<Identifier>(asTransitionEnd->firstIdentifier());
//			auto propertyName = propertyNode->name();

//			return generatedResultForOutcomingLink(elementId, logicalModelInterface, propertyName);
//		}
//	}
}

QString GeneratorForComplexIdentifierNode::generatedResultForNodeWithBasicName(
		qReal::Id const elementId
		, qReal::LogicalModelAssistInterface *logicalModelInterface
		, const QString &property
		)
{
	return logicalModelInterface->propertyByRoleName(elementId, property).toString();
}

QString GeneratorForComplexIdentifierNode::generatedResultForNodeWithUniqueType(
		qReal::LogicalModelAssistInterface *logicalModelInterface
		, const QString &type
		, const QString &propertyName)
{
	QList<qReal::Id> listOfElementIds;

	for (const qReal::Id elementId : logicalModelInterface->children(qReal::Id::rootId())) {
		if (elementId.element() == type) {
			listOfElementIds << elementId;
		}
	}

	if (listOfElementIds.size() != 1) {
		// TODO: throw exception
		qDebug() << "Element of type " << type << "is not unique!";
		return "";
	} else {
		return logicalModelInterface->propertyByRoleName(listOfElementIds.first(), propertyName).toString();
	}
}

QString GeneratorForComplexIdentifierNode::generatedResultForOutcomingLink(
		const qReal::Id linkId
		, qReal::LogicalModelAssistInterface *logicalModelInterface
		, const QString &propertyName)
{
	qReal::Id transitionEndId = logicalModelInterface->to(linkId);
	return logicalModelInterface->propertyByRoleName(transitionEndId, propertyName).toString();
}

QString GeneratorForComplexIdentifierNode::generatedResultForOtherVariable(
		const QString &variableName
		, qReal::LogicalModelAssistInterface *logicalModelInterface
		, const QString &propertyName)
{
	return "";
}
