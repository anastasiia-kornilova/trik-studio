/* Copyright 2007-2015 QReal Research Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#pragma once

#include <QtWidgets/QGraphicsView>
#include <QtGui/QKeyEvent>

#include "qrutils/utilsDeclSpec.h"

namespace graphicsUtils {

class QRUTILS_EXPORT AbstractView : public QGraphicsView
{
	Q_OBJECT
public:
	AbstractView(QWidget *parent = nullptr);

public slots:
	void zoomIn();
	void zoomOut();

signals:
	/// Emitted when user pressed delete button when this view was in focus.
	void deleteItem();

	/// Emitted when scene zoom changes.
	void zoomChanged();

	/// Emitted when current visible scene rectangle changes.
	void contentsRectChanged();

protected:
	void keyPressEvent(QKeyEvent *event) override;
	void wheelEvent(QWheelEvent *event) override;
	void scrollContentsBy(int dx, int dy) override;
	void setScaleLimits(qreal minAbsScale, qreal maxAbsScale);

private:
	void scaleTo(qreal newScale);

	qreal mMinAbsScale { 0.2 };
	qreal mMaxAbsScale { 10.0 };
	qreal mCurrentAbsScale { 1.0 };
};

}
