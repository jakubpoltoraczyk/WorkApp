#include "dataservice.h"

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
  jsonObjects.loginDataJson = getJsonObject(LOGIN_DATA_FILE);
  jsonObjects.customDialogDataJson = getJsonObject(CUSTOM_DIALOG_FILE);

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

std::ifstream
DataService::getJsonFileToRead(const std::string &fileName) const {
  auto jsonFile = dataDirectory;
  jsonFile.append(fileName);
  return jsonFile;
}

std::ofstream
DataService::getJsonFileToSave(const std::string &fileName) const {
  auto jsonFile = dataDirectory;
  jsonFile.append(fileName);
  return jsonFile;
}

nlohmann::json DataService::getJsonObject(const std::string &fileName) const {
  return nlohmann::json::parse(getJsonFileToRead(fileName));
}

void DataService::updateLoginData() {
  for (const auto &singleData : jsonObjects.loginDataJson.items()) {
    loginData.insert({QString::fromStdString(singleData.key()),
                      QString::fromStdString(singleData.value())});
  }
}

void DataService::updateCustomDialogData(CustomDialogDataset::Version version) {
  switch (version) {
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
  customDialogData.title =
      QString::fromStdString(jsonObjects.customDialogDataJson[keyValue][TITLE]);
  customDialogData.text =
      QString::fromStdString(jsonObjects.customDialogDataJson[keyValue][TEXT]);
  customDialogData.iconType = static_cast<QMessageBox::Icon>(
      jsonObjects.customDialogDataJson[keyValue][ICON]);

  customDialogData.buttonTypes.clear();
  for (const auto &button :
       jsonObjects.customDialogDataJson[keyValue][BUTTONS]) {
    customDialogData.buttonTypes.append(
        static_cast<QMessageBox::StandardButton>(button));
  }
}
