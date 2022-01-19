#pragma once

#include "../dataset/customdialogdataset.h"

#include <QString>

#include <filesystem>
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
  OperationResult requestLogin(const QString &login, const QString &password);

  /**
   * @brief Provide custom dialog data to display
   * @param version Version, in which one custom dialog will be displayed
   * @return Custom dialog data to display
   */
  const CustomDialogDataset::DataToDisplay &
  getCustomDialogData(CustomDialogDataset::Version version);

private:
  /** Update login data */
  void updateLoginData();

  /**
   * @brief Update custom dialog data
   * @details It uses @see deserializeCustomDialogData method to deserialize
   * appropriate data
   * @param version Version, in which one custom dialog data will be updated
   */
  void updateCustomDialogData(CustomDialogDataset::Version version);

  /**
   * @brief Deserialize custom dialog data
   * @param keyValue Key value used to get appropriate data from JSON file
   */
  void deserializeCustomDialogData(const std::string & keyValue);

  std::filesystem::path dataDirectory;
  std::map<QString, QString> loginData;
  CustomDialogDataset::DataToDisplay customDialogData;
};
