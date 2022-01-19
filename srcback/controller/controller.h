#pragma once

#include "../loginwindowservice/loginwindowservice.h"
#include "../dataservice/dataservice.h"
#include "../customdialogservice/customdialogservice.h"

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
   * @brief Provide service for custom dialog
   * @return std::shared_ptr to custom dialog service 
   */
  std::shared_ptr<CustomDialogService> getCustomDialogService() const;

  /**
   * @brief Provide service for login window
   * @return std::shared_ptr to login window service
   */
  std::shared_ptr<LoginWindowService> getLoginWindowService() const;

private:
  std::shared_ptr<DataService> dataService;
  std::shared_ptr<CustomDialogService> customDialogService;
  std::shared_ptr<LoginWindowService> loginWindowService;
};