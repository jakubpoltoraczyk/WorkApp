#include "controller.h"

#include <iostream>

Controller::Controller()
    : dataService(std::make_shared<DataService>()),
      customDialogService(std::make_shared<CustomDialogService>(dataService)),
      loginWindowService(std::make_shared<LoginWindowService>(dataService)) {
  QObject::connect(
      loginWindowService.get(), &LoginWindowService::loginAccepted,
      []() { std::cout << "Login has been accepted!" << std::endl; });
  QObject::connect(loginWindowService.get(), &LoginWindowService::loginCanceled,
                   [this]() {
                     customDialogService->prepareToDisplay(
                         CustomDialogDataset::Version::LoginError);
                   });
}

std::shared_ptr<CustomDialogService>
Controller::getCustomDialogService() const {
  return customDialogService;
}

std::shared_ptr<LoginWindowService> Controller::getLoginWindowService() const {
  return loginWindowService;
}
