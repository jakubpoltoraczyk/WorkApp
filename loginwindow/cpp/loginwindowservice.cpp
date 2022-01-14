#include "loginwindowservice.h"

#include <iostream>

LoginWindowService::LoginWindowService(
    std::shared_ptr<DataService> dataServicee)
    : dataService(dataServicee) {}

void LoginWindowService::onRegisterRequested() {
  // todo: implement appropriate slot for register operation request
}

void LoginWindowService::onLoginRequested(const QString &loginText,
                                          const QString &passwordText) {
  if (dataService->requestLogin(loginText.toStdString(),
                                passwordText.toStdString()) ==
      DataService::OperationResult::Success) {
    std::cout << "Success login!" << std::endl;
  } else {
    std::cout << "Failure login!" << std::endl;
  }
}

void LoginWindowService::onExitRequested() {
  // todo: find better way to safely close whole application
  exit(0);
}
