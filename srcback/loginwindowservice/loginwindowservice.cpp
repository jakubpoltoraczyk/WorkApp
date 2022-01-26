#include "loginwindowservice.h"

#include <iostream>

LoginWindowService::LoginWindowService(
    std::shared_ptr<DataService> dataServiceObject,
    std::shared_ptr<CustomDialogService> customDialogServiceObject)
    : dataService(dataServiceObject), customDialogService(customDialogServiceObject) {}

void LoginWindowService::onRegisterButtonReleased() { emit registerWindowRequested(); }

void LoginWindowService::onLoginButtonReleased(const QString &loginText,
                                               const QString &passwordText) {
  if (dataService->requestLogin(loginText, passwordText) == DataService::OperationResult::Success) {
    emit loginAccepted();
  } else {
    customDialogService->prepareToDisplay(CustomDialogDataset::Version::LoginError);
  }
}

void LoginWindowService::onExitButtonReleased() { emit deleteWindow(); }
