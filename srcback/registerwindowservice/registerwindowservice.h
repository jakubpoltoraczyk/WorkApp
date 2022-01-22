#pragma once

#include "../dataservice/dataservice.h"

#include <QObject>

#include <memory>

class RegisterWindowService: public QObject {
Q_OBJECT
public:
  /**
   * @brief Create a default instance of class
   * @param dataService Service for dataset operation
   */
  RegisterWindowService(std::shared_ptr<DataService> dataServiceObject);

public slots:
  /**
   * @brief Called, when register button has been released
   * @param loginText Login text field content
   * @param passwordText Password text field content
   */
  void onRegisterButtonReleased(const QString &loginText, const QString &passwordText);

  /** Called, when back button has been released */
  void onBackButtonReleased();

private:
  std::shared_ptr<DataService> dataService;
};
