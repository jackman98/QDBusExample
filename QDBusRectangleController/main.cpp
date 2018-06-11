#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "controller.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);
	Controller controller;
	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("controller", &controller);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
