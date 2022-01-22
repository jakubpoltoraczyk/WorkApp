#include "srcback/controller/controller.h"
#include "srcback/dataset/inputcomponentdataset.h"
#include "srcback/dataset/windowmanagerdataset.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace {
void registerDatasets() {
  qmlRegisterUncreatableMetaObject(InputComponentDataset::staticMetaObject, "InputComponentDataset",
                                   1, 0, "InputComponentDataset",
                                   "Couldn't create: object is uncreatable");
  qmlRegisterUncreatableMetaObject(WindowManagerDataset::staticMetaObject, "WindowManagerDataset",
                                   1, 0, "WindowManagerDataset",
                                   "Couldn't create: object is uncreatable");
  qRegisterMetaType<WindowManagerDataset::WindowType>();
}
} // namespace

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  Controller controller;

  engine.rootContext()->setContextProperty("windowManager", controller.getWindowManager().get());
  engine.rootContext()->setContextProperty("customDialogService",
                                           controller.getCustomDialogService().get());
  engine.rootContext()->setContextProperty("loginWindowService",
                                           controller.getLoginWindowService().get());
  engine.rootContext()->setContextProperty("registerWindowService",
                                           controller.getRegisterWindowService().get());

  registerDatasets();

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  controller.initialize();

  return engine.rootObjects().isEmpty() ? -1 : app.exec();
}
