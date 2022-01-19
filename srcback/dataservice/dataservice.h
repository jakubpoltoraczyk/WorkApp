#pragma once

#include "../dataset/customdialogdataset.h"

#include <QString>

#include <filesystem>
#include <fstream>
#include <map>
#include <nlohmann/json.hpp>

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
  /**
   * @brief Provide JSON file in read mode
   * @param fileName Name of the JSON file
   * @return JSON file in read mode
   */
  std::ifstream getJsonFileToRead(const std::string &fileName) const;

  /**
   * @brief Provide JSON file in write mode
   * @param fileName Name of the JSON file
   * @return JSON file in write mode
   */
  std::ofstream getJsonFileToSave(const std::string &fileName) const;

  /**
   * @brief Provide JSON object according to specified file name
   * @param fileName Name of the JSON file
   * @return JSON object
   */
  nlohmann::json getJsonObject(const std::string &fileName) const;

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
   * @param keyValue Key value used to get appropriate data from JSON object
   */
  void deserializeCustomDialogData(const std::string &keyValue);

  /** Contains JSON objects, which can be used several times during app life */
  struct JsonObjects {
    nlohmann::json loginDataJson;        ///< JSON object related to login data
    nlohmann::json customDialogDataJson; ///< JSON object related to custom dialog data
  } jsonObjects;

  std::filesystem::path dataDirectory;                 ///< Contains data directory path
  std::map<QString, QString> loginData;                ///< Contains login data (login and password)
  CustomDialogDataset::DataToDisplay customDialogData; ///< Contains custom dialog data
};
