#include "loginwindowservice.h"

#include <iostream>

LoginWindowService::LoginWindowService(std::shared_ptr<DataService> dataServiceObject)
    : dataService(dataServiceObject) {}

void LoginWindowService::onRegisterButtonReleased() { emit registerWindowRequested(); }

void LoginWindowService::onLoginButtonReleased(const QString &loginText,
                                               const QString &passwordText) {
  if (dataService->requestLogin(loginText, passwordText) == DataService::OperationResult::Success) {
    emit loginAccepted();
  } else {
    emit loginCanceled();
  }
}

void LoginWindowService::onExitButtonReleased() {
  // todo: find better way to safely close whole application
  exit(0);
}
