#include "registerwindowservice.h"

#include <iostream>

RegisterWindowService::RegisterWindowService(std::shared_ptr<DataService> dataServiceObject)
    : dataService(dataServiceObject) {}

void RegisterWindowService::onRegisterButtonReleased(const QString &loginText,
                                                     const QString &passwordText) {
  std::cout << "Register button has been released: " << loginText.toStdString() << " --- "
            << passwordText.toStdString() << std::endl;
}

void RegisterWindowService::onBackButtonReleased() {
  std::cout << "Back button has been released!" << std::endl;
}
