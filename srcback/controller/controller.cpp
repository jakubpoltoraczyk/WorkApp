#include "controller.h"

#include <QVariant>

#include <iostream>

Controller::Controller()
    : dataService(std::make_shared<DataService>()),
      windowManager(std::make_shared<WindowManager>()),
      customDialogService(std::make_shared<CustomDialogService>(dataService)),
      loginWindowService(std::make_shared<LoginWindowService>(dataService, customDialogService)),
      registerWindowService(
          std::make_shared<RegisterWindowService>(dataService, customDialogService)) {
  QObject::connect(loginWindowService.get(), &LoginWindowService::registerWindowRequested,
                   [this]() {
                     windowManager->createWindow(WindowManagerDataset::WindowType::RegisterWindow);
                     windowManager->hideWindow(WindowManagerDataset::WindowType::LoginWindow);
                   });
  QObject::connect(loginWindowService.get(), &LoginWindowService::loginAccepted, [this]() {
    windowManager->deleteWindow(WindowManagerDataset::WindowType::LoginWindow);
  });
  QObject::connect(loginWindowService.get(), &LoginWindowService::closeApplicationRequested, [this]() {
    windowManager->deleteWindow(WindowManagerDataset::WindowType::LoginWindow);
    exit(0);
  });
  QObject::connect(registerWindowService.get(), &RegisterWindowService::registerAccepted, [this]() {
    windowManager->deleteWindow(WindowManagerDataset::WindowType::RegisterWindow);
    windowManager->showWindow(WindowManagerDataset::WindowType::LoginWindow);
  });
  QObject::connect(registerWindowService.get(), &RegisterWindowService::closeWindowRequested, [this]() {
    windowManager->deleteWindow(WindowManagerDataset::WindowType::RegisterWindow);
    windowManager->showWindow(WindowManagerDataset::WindowType::LoginWindow);
  });
}

void Controller::initialize() {
  windowManager->createWindow(WindowManagerDataset::WindowType::LoginWindow);
}

std::shared_ptr<WindowManager> Controller::getWindowManager() const { return windowManager; }

std::shared_ptr<CustomDialogService> Controller::getCustomDialogService() const {
  return customDialogService;
}

std::shared_ptr<LoginWindowService> Controller::getLoginWindowService() const {
  return loginWindowService;
}

std::shared_ptr<RegisterWindowService> Controller::getRegisterWindowService() const {
  return registerWindowService;
}
