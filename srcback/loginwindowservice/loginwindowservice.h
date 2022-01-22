#pragma once

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
   */
  LoginWindowService(std::shared_ptr<DataService> dataServiceObject);

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
  /** Emit, when displaying register window has been requested */
  void registerWindowRequested();

  /** Emit, when login with specified data has been accepted */
  void loginAccepted();

  /** Emit, when login with specified data has been canceled */
  void loginCanceled();

private:
  std::shared_ptr<DataService> dataService;
};
