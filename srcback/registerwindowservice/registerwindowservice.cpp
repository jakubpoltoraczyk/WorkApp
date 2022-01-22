#include "registerwindowservice.h"

#include <iostream>

RegisterWindowService::RegisterWindowService(std::shared_ptr<DataService> dataServiceObject)
    : dataService(dataServiceObject) {}

void RegisterWindowService::onRegisterButtonReleased(const QString &loginText,
                                                     const QString &passwordText,
                                                     const QString &passwordConfirmationText) {
  if (dataService->requestRegister(loginText, passwordText, passwordConfirmationText) ==
      DataService::OperationResult::Success) {
    emit registerAccepted();
  } else {
    emit registerCanceled();
  }
}

void RegisterWindowService::onBackButtonReleased() {
  std::cout << "Back button has been released!" << std::endl;
}
