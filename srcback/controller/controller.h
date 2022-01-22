#pragma once

#include "../customdialogservice/customdialogservice.h"
#include "../dataservice/dataservice.h"
#include "../loginwindowservice/loginwindowservice.h"
#include "../windowmanager/windowmanager.h"

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

  /** Initialize GUI */
  void initialize();

  /**
   * @brief Provide window manager object
   * @return std::shared_ptr to window manager object
   */
  std::shared_ptr<WindowManager> getWindowManager() const;

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
  std::shared_ptr<WindowManager> windowManager;
  std::shared_ptr<CustomDialogService> customDialogService;
  std::shared_ptr<LoginWindowService> loginWindowService;
};