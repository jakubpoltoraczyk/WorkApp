#include "loginwindowservice.h"

#include <QString>

LoginWindowService::LoginWindowService(
    std::shared_ptr<DataService> dataServiceObject,
    std::shared_ptr<CustomDialogService> customDialogServiceObject)
    : WindowService(dataServiceObject, customDialogServiceObject) {}

void LoginWindowService::onRegisterButtonReleased() { emit registerWindowRequested(); }

void LoginWindowService::onLoginButtonReleased(const QString &loginText,
                                               const QString &passwordText) {
  if (dataService->requestLogin(loginText.toStdString(), passwordText.toStdString()) ==
      DataService::OperationResult::Success) {
    emit loginAccepted();
  } else {
    customDialogService->prepareToDisplay(CustomDialogDataset::Version::LoginError);
  }
}

void LoginWindowService::onBackButtonReleased() { emit closeApplicationRequested(); }
