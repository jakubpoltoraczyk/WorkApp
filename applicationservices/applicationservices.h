#pragma once

#include "../rectanglebutton/cpp/rectanglebuttonservice.h"
#include "../inputcomponent/cpp/inputcomponentservice.h"

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

  /**
   * @brief Provide a service for input component
   * @return std::shared_ptr to created input component service 
   */
  std::shared_ptr<InputComponentService> getInputComponentService() const;
  
private:
  std::shared_ptr<RectangleButtonService> rectangleButtonService;
  std::shared_ptr<InputComponentService> inputComponentService;
};