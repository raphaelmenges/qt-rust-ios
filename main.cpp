// #include "mybridge/lib.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

extern "C"
{
	int get_forty_two(void);
}

int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty(
	    "helloFromMyCounter",
	    QString::fromStdString(std::string("Number from Rust-C-Interface: " + std::to_string(get_forty_two()))));
	// engine.rootContext()->setContextProperty("helloFromMyBrige",
	//                                          QString::fromStdString(std::string(my_bridge::hello_world())));
	engine.load(QUrl("qrc:///main.qml"));
	return app.exec();
}
