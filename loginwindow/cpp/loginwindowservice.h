#pragma once

#include <QObject>

/** Class, which provides service functionalities of login window */
class LoginWindowService: public QObject {
Q_OBJECT
public slots:
  /** Called, when register operation has been requested */
  void onRegisterRequested();

  /**
   * @brief Called, when login operation has been requested
   * @param loginText Login text field content
   * @param passwordText Password text field content
   */
  void onLoginRequested(const QString & loginText, const QString & passwordText);

  /** Called, when exit operation has been requested */
  void onExitRequested();
};
