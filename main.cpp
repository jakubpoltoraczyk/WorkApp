#include "applicationservices/applicationservices.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  ApplicationServices applicationServices;

  engine.rootContext()->setContextProperty(
      "RectangleButtonService",
      applicationServices.getRectangleButtonService().get());

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return engine.rootObjects().isEmpty() ? -1 : app.exec();
}
