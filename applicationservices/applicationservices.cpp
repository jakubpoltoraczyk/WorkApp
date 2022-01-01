#include "applicationservices.h"

ApplicationServices::ApplicationServices()
    : rectangleButtonService(std::make_shared<RectangleButtonService>()) {}

std::shared_ptr<RectangleButtonService>
ApplicationServices::getRectangleButtonService() const {
  return rectangleButtonService;
}
