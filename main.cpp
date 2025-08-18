// #include "rust_cxx/lib.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

// Defintion for Rust-C-crate.
extern "C"
{
	int get_forty_two(void);
}

int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty(
	    "helloFromRustCCrate",
	    QString::fromStdString(std::string("Number from Rust-C-crate: " + std::to_string(get_forty_two()))));
	// engine.rootContext()->setContextProperty("helloFromRustCxxCrate",
	//                                          QString::fromStdString(std::string(rust_cxx::hello_world())));
	engine.load(QUrl("qrc:///main.qml"));
	return app.exec();
}
