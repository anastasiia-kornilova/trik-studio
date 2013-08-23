#include "customizer.h"
#include <qrkernel/settingsManager.h>

using namespace robotsInterpreterCore;

QString Customizer::windowTitle() const
{
	return QObject::tr("QReal:Robots") + " " + productVersion();
}

QIcon Customizer::applicationIcon() const
{
	return QIcon(":/icons/kroki.png");
}

QString Customizer::productVersion() const
{
	// TODO: other storage for it?
	return "2.4.0 (TRIK)";
}

QString Customizer::aboutText() const
{
	return "<b>" + windowTitle() + "<b><br><br><a href=\"http://robots.qreal.ru/\">http://robots.qreal.ru/</a>";
}

bool Customizer::showInterpeterButton() const
{
	return false;
}

void Customizer::customizeDocks(qReal::gui::MainWindowDockInterface *dockInterface)
{
	mDockInterface = dockInterface;
	dockInterface->logicalModelDock()->hide();
	dockInterface->tabifyDockWidget(dockInterface->graphicalModelDock(), dockInterface->propertyEditorDock());
	dockInterface->graphicalModelDock()->setWindowTitle(QObject::tr("Blocks"));
}

void Customizer::placePluginWindows(QDockWidget *watchWindow, QWidget *sensorsWidget)
{
	mDockInterface->addDockWidget(Qt::LeftDockWidgetArea, watchWindow);
	watchWindow->setFloating(false);
	QDockWidget *sensorsDock = produceDockWidget(QObject::tr("Configure sensors"), sensorsWidget);
	mDockInterface->addDockWidget(Qt::LeftDockWidgetArea, sensorsDock);
}

QDockWidget *Customizer::produceDockWidget(QString const &title, QWidget *content) const
{
	QDockWidget *dock = new QDockWidget(title);
	dock->setWidget(content);
	return dock;
}