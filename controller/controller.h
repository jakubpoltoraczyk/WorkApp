#pragma once

#include "../loginwindow/cpp/loginwindowservice.h"
#include "../dataservice/dataservice.h"

#include <QObject>
#include <memory>

/**
 * @brief Class, which provides general management of different services used in
 * application
 * @details It creates and contains each service used in application
 */
class Controller : public QObject {
  Q_OBJECT
public:
  /** Construct a default instace of class */
  Controller();

  /**
   * @brief Provide service for login window
   * @return std::shared_ptr to login window service
   */
  std::shared_ptr<LoginWindowService> getLoginWindowService() const;

private:
  std::shared_ptr<DataService> dataService;
  std::shared_ptr<LoginWindowService> loginWindowService;
};