#include "applicationservices.h"

ApplicationServices::ApplicationServices()
    : rectangleButtonService(std::make_shared<RectangleButtonService>()),
      inputComponentService(std::make_shared<InputComponentService>()) {}

std::shared_ptr<RectangleButtonService>
ApplicationServices::getRectangleButtonService() const {
  return rectangleButtonService;
}

std::shared_ptr<InputComponentService>
ApplicationServices::getInputComponentService() const {
  return inputComponentService;
}
