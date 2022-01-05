#include "loginwindowservice.h"

#include <iostream>

void LoginWindowService::onRegisterRequested() {
  // todo: implement appropriate slot for register operation request
}

void LoginWindowService::onLoginRequested(const QString &loginText, const QString &passwordText) {
  std::cout << "Login: " << loginText.toStdString() << std::endl;
  std::cout << "Password: " << passwordText.toStdString() << std::endl;
}

void LoginWindowService::onExitRequested() {
  // todo: find better way to safely close whole application
  exit(0);
}
