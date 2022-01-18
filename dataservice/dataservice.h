#pragma once

#include "../dataset/customdialogdataset.h"

#include <QString>

#include <map>

/** Class, which represents service for dataset operations */
class DataService {
public:
  /** Create a new instance of class */
  DataService();

  /** Contains types of each operation result */
  enum class OperationResult { Success, Failure };

  /**
   * @brief Provide appropriate operations related to login request
   * @param login User's login
   * @param password User's password
   * @return Success if login request finished successfully, otherwise Failure
   */
  OperationResult requestLogin(const QString &login,
                               const QString &password);

  /**
   * @brief Provide custom dialog data to display
   * @param version Version, in which one custom dialog will be displayed
   * @return Custom dialog data to display
   */
  const CustomDialogDataset::DataToDisplay &
  getCustomDialogData(CustomDialogDataset::Version version);

private:
  void updateLoginDataset();
  void updateCustomDialogData(CustomDialogDataset::Version version);

  std::map<QString, QString>
      loginDataset; ///< Map with login as a key and password as a value

  CustomDialogDataset::DataToDisplay customDialogData;
};
