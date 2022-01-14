#include "controller.h"

#include <iostream>

Controller::Controller()
    : dataService(std::make_shared<DataService>()),
      loginWindowService(std::make_shared<LoginWindowService>(dataService)) {
  QObject::connect(
      loginWindowService.get(), &LoginWindowService::loginAccepted,
      []() { std::cout << "Login has been accepted!" << std::endl; });
  QObject::connect(
      loginWindowService.get(), &LoginWindowService::loginCanceled,
      []() { std::cout << "Login has been canceled!" << std::endl; });
}

std::shared_ptr<LoginWindowService> Controller::getLoginWindowService() const {
  return loginWindowService;
}
