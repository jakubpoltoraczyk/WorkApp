#include "dataservice.h"

#include <fstream>
#include <nlohmann/json.hpp>

#include <iostream>

namespace {
constexpr char DATA_DIRECTORY[] = "data";
constexpr char LOGIN_DATA_FILE[] = "logindata.json";
constexpr char CUSTOM_DIALOG_FILE[] = "customdialogdata.json";

constexpr char EXAMPLE[] = "example";
constexpr char LOGIN_ERROR[] = "login_error";
constexpr char TITLE[] = "title";
constexpr char TEXT[] = "text";
constexpr char ICON[] = "icon";
constexpr char BUTTONS[] = "buttons";

std::filesystem::path getDataDirectory() {
  auto mainDirectory = std::filesystem::current_path().parent_path();
  mainDirectory.append(DATA_DIRECTORY);
  return mainDirectory;
}
} // namespace

DataService::DataService() : dataDirectory(getDataDirectory()) {
  updateLoginData();
}

DataService::OperationResult
DataService::requestLogin(const QString &login, const QString &password) {
  try {
    if (loginData.at(login) == password) {
      // todo: update user dataset according to new login dataset
      return OperationResult::Success;
    } else {
      return OperationResult::Failure;
    }
  } catch (const std::out_of_range &error) {
    return OperationResult::Failure;
  }
}

const CustomDialogDataset::DataToDisplay &
DataService::getCustomDialogData(CustomDialogDataset::Version version) {
  updateCustomDialogData(version);
  return customDialogData;
}

void DataService::updateLoginData() {
  auto loginDataFilePath = dataDirectory;
  loginDataFilePath.append(LOGIN_DATA_FILE);
  std::ifstream loginDataFile(loginDataFilePath);

  nlohmann::json loginDataJson = nlohmann::json::parse(loginDataFile);
  for (const auto &singleData : loginDataJson.items()) {
    loginData.insert({QString::fromStdString(singleData.key()),
                      QString::fromStdString(singleData.value())});
  }

  loginDataFile.close();
}

void DataService::updateCustomDialogData(CustomDialogDataset::Version version) {
  auto customDialogDataFilePath = dataDirectory;
  customDialogDataFilePath.append(CUSTOM_DIALOG_FILE);
  std::ifstream customDialogDataFile(customDialogDataFilePath);

  nlohmann::json customDialogDataJson =
      nlohmann::json::parse(customDialogDataFile);

  switch (std::string keyValue; version) {
  case CustomDialogDataset::Version::LoginError:
    deserializeCustomDialogData(LOGIN_ERROR);
    break;
  case CustomDialogDataset::Version::Example:
    deserializeCustomDialogData(EXAMPLE);
    break;
  default:
    std::cout << "Unknown type of custom dialog! It will not be displayed";
  }
}

void DataService::deserializeCustomDialogData(const std::string &keyValue) {
  auto customDialogDataFilePath = dataDirectory;
  customDialogDataFilePath.append(CUSTOM_DIALOG_FILE);
  std::ifstream customDialogDataFile(customDialogDataFilePath);

  nlohmann::json customDialogDataJson =
      nlohmann::json::parse(customDialogDataFile);

  customDialogData.title =
      QString::fromStdString(customDialogDataJson[keyValue][TITLE]);
  customDialogData.text =
      QString::fromStdString(customDialogDataJson[keyValue][TEXT]);
  customDialogData.iconType =
      static_cast<QMessageBox::Icon>(customDialogDataJson[keyValue][ICON]);

  customDialogData.buttonTypes.clear();
  for (const auto &button : customDialogDataJson[keyValue][BUTTONS]) {
    customDialogData.buttonTypes.append(
        static_cast<QMessageBox::StandardButton>(button));
  }

  customDialogDataFile.close();
}
