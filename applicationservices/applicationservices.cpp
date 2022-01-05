#include "applicationservices.h"

ApplicationServices::ApplicationServices()
    : loginWindowService(std::make_shared<LoginWindowService>()) {}

std::shared_ptr<LoginWindowService> ApplicationServices::getLoginWindowService() const {
  return loginWindowService;
}
