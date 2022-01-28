#pragma once

#include "../windowservice/windowservice.h"

#include <QObject>

#include <memory>

/** Class, which provides service functionalities of login window */
class LoginWindowService : public WindowService {
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
  /** Called, when back button has been released */
  void onBackButtonReleased() override;

  /** Called, when register button has been released*/
  void onRegisterButtonReleased();

  /**
   * @brief Called, when login button has been released
   * @param loginText Login text field content
   * @param passwordText Password text field content
   */
  void onLoginButtonReleased(const QString &loginText, const QString &passwordText);

signals:
  /** Emitted, when register window should be displayed */
  void registerWindowRequested();

  /** Emitted, when login operation has been accepted */
  void loginAccepted();

  /** Emitted, when application should be closed */
  void closeApplicationRequested();
};
