#include "applicationservices/applicationservices.h"
#include "dataset/inputcomponentdataset.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace {
void registerDatasets() {
  qmlRegisterUncreatableMetaObject(
      InputComponentDataset::staticMetaObject, "InputComponentDataset", 1, 0,
      "InputComponentDataset", "Couldn't create: object is uncreatable");
}
} // namespace

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  ApplicationServices applicationServices;

  engine.rootContext()->setContextProperty(
      "RectangleButtonService",
      applicationServices.getRectangleButtonService().get());
  engine.rootContext()->setContextProperty(
      "InputComponentService",
      applicationServices.getInputComponentService().get());

  registerDatasets();

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return engine.rootObjects().isEmpty() ? -1 : app.exec();
}
