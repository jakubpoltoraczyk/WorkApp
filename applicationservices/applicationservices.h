#pragma once

#include "../rectanglebutton/cpp/rectanglebuttonservice.h"

#include <memory>

/** Class, which provides different services used in application */
class ApplicationServices {
public:
  /** Construct a default instace of class */
  ApplicationServices();

  /**
   * @brief Provide a service for rectangle button
   * @return std::shared_ptr to created rectangle button service 
   */
  std::shared_ptr<RectangleButtonService> getRectangleButtonService() const;
  
private:
  std::shared_ptr<RectangleButtonService> rectangleButtonService;
};