#pragma once

#include "../customdialogservice/customdialogservice.h"
#include "../dataservice/dataservice.h"

#include <QObject>

#include <memory>

/** Class, which provides common service functionalities of application window */
class WindowService : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Create a default instance of class
   * @param dataService Service for dataset operation
   * @param customDialogServiceObject Service for custom dialog
   */
  WindowService(std::shared_ptr<DataService> dataServiceObject,
                std::shared_ptr<CustomDialogService> customDialogServiceObject)
      : dataService(dataServiceObject), customDialogService(customDialogServiceObject){};

  /** Default virtual class destructor */
  virtual ~WindowService() = default;

public slots:
  /** Called, when back button has been released */
  virtual void onBackButtonReleased() = 0;

protected:
  std::shared_ptr<DataService> dataService;
  std::shared_ptr<CustomDialogService> customDialogService;
};
