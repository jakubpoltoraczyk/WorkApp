#include "controller.h"

Controller::Controller()
    : dataService(std::make_shared<DataService>()),
      loginWindowService(std::make_shared<LoginWindowService>(dataService)) {}

std::shared_ptr<LoginWindowService> Controller::getLoginWindowService() const {
  return loginWindowService;
}
