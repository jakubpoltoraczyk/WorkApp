#pragma once

#include "../customdialogservice/customdialogservice.h"
#include "../dataservice/dataservice.h"

#include <QObject>

#include <memory>

/** Class, which provides service functionalities of login window */
class LoginWindowService : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Create new instance of class
   * @param dataServiceObject Service for dataset operations
   * @param customDialogServiceObject Service for custom dialog
   */
  LoginWindowService(std::shared_ptr<DataService> dataServiceObject,
                     std::shared_ptr<CustomDialogService> customDialogServiceObject);

public slots:
  /** Called, when register button has been released*/
  void onRegisterButtonReleased();

  /**
   * @brief Called, when login button has been released
   * @param loginText Login text field content
   * @param passwordText Password text field content
   */
  void onLoginButtonReleased(const QString &loginText, const QString &passwordText);

  /** Called, when exit button has been released */
  void onExitButtonReleased();

signals:
  /** Emitted, when register window should be displayed */
  void registerWindowRequested();

  /** Emitted, when login operation has been accepted */
  void loginAccepted();

  /** Emitted, when window should be deleted */
  void deleteWindow();

private:
  std::shared_ptr<DataService> dataService;
  std::shared_ptr<CustomDialogService> customDialogService;
};
