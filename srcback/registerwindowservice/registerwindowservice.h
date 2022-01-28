#pragma once

#include "../windowservice/windowservice.h"

#include <QObject>

#include <memory>

/** Class, which provides service functionalities of register window */
class RegisterWindowService : public WindowService {
  Q_OBJECT
public:
  /**
   * @brief Create a default instance of class
   * @param dataServiceObject Service for dataset operation
   * @param customDialogServiceObject Service for custom dialog
   */
  RegisterWindowService(std::shared_ptr<DataService> dataServiceObject,
                        std::shared_ptr<CustomDialogService> customDialogServiceObject);

public slots:
  /** Called, when back button has been released */
  void onBackButtonReleased() override;

  /**
   * @brief Called, when register button has been released
   * @param loginText Login text field content
   * @param passwordText Password text field content
   * @param passwordConfirmationText Password confirmation text field content
   */
  void onRegisterButtonReleased(const QString &loginText, const QString &passwordText,
                                const QString &passwordConfirmationText);

signals:
  /** Emitted, when register has been accepted */
  void registerAccepted();

  /** Emitted, when window should be closed */
  void closeWindowRequested();
};
