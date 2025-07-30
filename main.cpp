#include "mybridge/lib.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("helloFromRust",
	                                         QString::fromStdString(std::string(my_bridge::hello_world())));
	engine.load(QUrl("qrc:///main.qml"));
	return app.exec();
}
