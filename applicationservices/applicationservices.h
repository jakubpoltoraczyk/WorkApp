#pragma once

#include "../loginwindow/cpp/loginwindowservice.h"

#include <memory>

/** Class, which provides different services used in application */
class ApplicationServices {
public:
  /** Construct a default instace of class */
  ApplicationServices();

  /**
   * @brief Provide service for login window
   * @return std::shared_ptr to login window service 
   */
  std::shared_ptr<LoginWindowService> getLoginWindowService()const;
  
private:
  std::shared_ptr<LoginWindowService> loginWindowService;
};