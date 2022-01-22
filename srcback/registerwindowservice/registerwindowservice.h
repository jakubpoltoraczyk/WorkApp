#pragma once

#include "../dataservice/dataservice.h"

#include <QObject>

#include <memory>

class RegisterWindowService : public QObject {
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
   * @param passwordConfirmationText Password confirmation text field content
   */
  void onRegisterButtonReleased(const QString &loginText, const QString &passwordText,
                                const QString &passwordConfirmationText);

  /** Called, when back button has been released */
  void onBackButtonReleased();

signals:
  /** Emit, when register operation has been accepted */
  void registerAccepted();

  /** Emit when register operation has been canceled */
  void registerCanceled();

private:
  std::shared_ptr<DataService> dataService;
};
