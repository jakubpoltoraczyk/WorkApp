#include "srcback/controller/controller.h"
#include "srcback/dataset/customdialogdataset.h"
#include "srcback/dataset/inputcomponentdataset.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace {
void registerDatasets() {
  qmlRegisterUncreatableMetaObject(
      InputComponentDataset::staticMetaObject, "InputComponentDataset", 1, 0,
      "InputComponentDataset", "Couldn't create: object is uncreatable");
  qmlRegisterUncreatableMetaObject(
      CustomDialogDataset::staticMetaObject, "CustomDialogDataset", 1, 0,
      "CustomDialogDataset", "Couldn't create: object is uncreatable");
}
} // namespace

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  Controller controller;

  engine.rootContext()->setContextProperty(
      "customDialogService", controller.getCustomDialogService().get());
  engine.rootContext()->setContextProperty(
      "loginWindowService", controller.getLoginWindowService().get());

  registerDatasets();

  engine.load(QUrl(QStringLiteral("qrc:/srcgui/loginwindow/LoginWindow.qml")));

  return engine.rootObjects().isEmpty() ? -1 : app.exec();
}
