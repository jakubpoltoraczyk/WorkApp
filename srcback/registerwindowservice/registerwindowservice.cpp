#include "registerwindowservice.h"

#include <iostream>

RegisterWindowService::RegisterWindowService(
    std::shared_ptr<DataService> dataServiceObject,
    std::shared_ptr<CustomDialogService> customDialogServiceObject)
    : WindowService(dataServiceObject, customDialogServiceObject) {}

void RegisterWindowService::onRegisterButtonReleased(const QString &loginText,
                                                     const QString &passwordText,
                                                     const QString &passwordConfirmationText) {
  if (loginText.isEmpty() || passwordText.isEmpty() || passwordConfirmationText.isEmpty() ||
      passwordText != passwordConfirmationText) {
    customDialogService->prepareToDisplay(CustomDialogDataset::Version::RegistrationInvalidData);
    return;
  }
  if (dataService->requestRegister(loginText, passwordText) ==
      DataService::OperationResult::Success) {
    customDialogService->prepareToDisplay(CustomDialogDataset::Version::RegistrationSuccess);
    emit registerAccepted();
  } else {
    customDialogService->prepareToDisplay(CustomDialogDataset::Version::RegistrationError);
  }
}

void RegisterWindowService::onBackButtonReleased() { emit closeWindowRequested(); }
