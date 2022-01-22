#include "controller.h"

#include <QVariant>

#include <iostream>

Controller::Controller()
    : dataService(std::make_shared<DataService>()),
      windowManager(std::make_shared<WindowManager>()),
      customDialogService(std::make_shared<CustomDialogService>(dataService)),
      loginWindowService(std::make_shared<LoginWindowService>(dataService)) {
  QObject::connect(loginWindowService.get(), &LoginWindowService::loginAccepted,
                   [this]() { windowManager->hideSplashScreen(); });
  QObject::connect(loginWindowService.get(), &LoginWindowService::loginCanceled, [this]() {
    customDialogService->prepareToDisplay(CustomDialogDataset::Version::LoginError);
  });
}

void Controller::initialize() {
  windowManager->showSplashScreen();
  windowManager->createWindow(WindowManagerDataset::WindowType::LoginWindow);
}

std::shared_ptr<WindowManager> Controller::getWindowManager() const { return windowManager; }

std::shared_ptr<CustomDialogService> Controller::getCustomDialogService() const {
  return customDialogService;
}

std::shared_ptr<LoginWindowService> Controller::getLoginWindowService() const {
  return loginWindowService;
}
