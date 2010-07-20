#pragma once

#include <QWidget>
#include <QList>
#include <QRectF>
#include <QPointF>
#include <QPainter>
#include "elementTitleHelpers.h"
#include "elementRepoInterface.h"
#include "sdfRendererInterface.h"
#include "../kernel/ids.h"

namespace UML{

	typedef QPair<QPair<qReal::Id, qReal::Id>, QPair<bool, qReal::Id> > PossibleEdge;
	typedef QPair<QPair<QString, QString>, QPair<bool, QString> > StringPossibleEdge;
	typedef QPair<bool, qReal::Id> PossibleEdgeType;

/** @brief line port description */
	struct StatLine
	{
		QLineF line;
		bool prop_x1;
		bool prop_y1;
		bool prop_x2;
		bool prop_y2;

		StatLine() : line(QLineF(0, 0, 0, 0)), prop_x1(false), prop_y1(false),
			prop_x2(false), prop_y2(false) {}

		operator QLineF () const
		{
			return line;
		}

		void operator = (QLineF const &l)
		{
			line = l;
			prop_x1 = false;
			prop_x2 = false;
			prop_y1 = false;
			prop_y2 = false;
		}
	};

	/** @class ElementImpl
	 *	@brief base class for generated stuff in plugins
	 *	TODO: split into NodeElementImpl and EdgeElementImpl
	 * */
	class ElementImpl {
		public:
			virtual void init(QRectF &contents, QList<QPointF> &pointPorts,
					QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
					QList<ElementTitleInterface*> &titles,
					SdfRendererInterface *renderer, SdfRendererInterface *portRenderer) = 0;
			virtual void init(ElementTitleFactoryInterface &factory,
								QList<ElementTitleInterface*> &titles) = 0;
			virtual void paint(QPainter *painter, QRectF &contents) = 0;
			virtual void updateData(ElementRepoInterface *repo) const = 0;
			virtual bool isNode() = 0;
			virtual bool hasPorts() = 0;
			virtual Qt::PenStyle getPenStyle() = 0;
			virtual void drawStartArrow(QPainter *painter) const = 0;
			virtual void drawEndArrow(QPainter *painter) const = 0;

			/*Container properties*/
			virtual bool isContainer() = 0;
			virtual bool isSortContainer() = 0;
			virtual int sizeOfForestalling() = 0;
			virtual int sizeOfChildrenForestalling() = 0;
			virtual bool isChildrenMovable() = 0;
			virtual bool isMinimizingToChildren() = 0;
			virtual bool isClass() = 0;
			virtual bool isMaximizingChildren() = 0;

			virtual bool isPort() = 0;
			virtual bool isHavePin() = 0;

			virtual QList<double> getBorders() = 0;

			virtual QStringList bonusContextMenuFields() = 0;
	};
}
