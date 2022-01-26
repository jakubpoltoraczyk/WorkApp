#include "dataservice.h"

#include <iostream>

namespace {
constexpr char DATA_DIRECTORY[] = "data";
constexpr char LOGIN_DATA_FILE[] = "logindata.json";
constexpr char CUSTOM_DIALOG_FILE[] = "customdialogdata.json";

constexpr char LOGIN_ERROR[] = "login_error";
constexpr char REGISTRATION_SUCCESS[] = "registration_success";
constexpr char REGISTRATION_ERROR[] = "registration_error";
constexpr char REGISTRATION_INVALID_DATA[] = "registration_invalid_data";

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

DataService::OperationResult DataService::requestLogin(const QString &login,
                                                       const QString &password) {
  try {
    if (loginData.at(login) != password) {
      return OperationResult::Failure;
    }
    // todo: update user dataset according to new login dataset
    return OperationResult::Success;
  } catch (const std::out_of_range &error) {
    return OperationResult::Failure;
  }
}

DataService::OperationResult DataService::requestRegister(const QString &login,
                                                          const QString &password) {
  if (loginData.find(login) != loginData.end()) {
    return OperationResult::Failure;
  }
  // todo: create user account according to new login dataset
  loginData.insert({login, password});
  return OperationResult::Success;
}

const CustomDialogDataset::DataToDisplay &
DataService::getCustomDialogData(CustomDialogDataset::Version version) {
  updateCustomDialogData(version);
  return customDialogData;
}

std::ifstream DataService::getJsonFileToRead(const std::string &fileName) const {
  auto jsonFile = dataDirectory;
  jsonFile.append(fileName);
  return jsonFile;
}

std::ofstream DataService::getJsonFileToSave(const std::string &fileName) const {
  auto jsonFile = dataDirectory;
  jsonFile.append(fileName);
  return jsonFile;
}

nlohmann::json DataService::getJsonObject(const std::string &fileName) const {
  return nlohmann::json::parse(getJsonFileToRead(fileName));
}

void DataService::updateLoginData() {
  for (const auto &singleData : jsonObjects.loginDataJson.items()) {
    loginData.insert(
        {QString::fromStdString(singleData.key()), QString::fromStdString(singleData.value())});
  }
}

void DataService::updateCustomDialogData(CustomDialogDataset::Version version) {
  using CustomDialogDataset::Version;
  switch (version) {
  case Version::LoginError:
    deserializeCustomDialogData(LOGIN_ERROR);
    break;
  case Version::RegistrationSuccess:
    deserializeCustomDialogData(REGISTRATION_SUCCESS);
    break;
  case Version::RegistrationError:
    deserializeCustomDialogData(REGISTRATION_ERROR);
    break;
  case Version::RegistrationInvalidData:
    deserializeCustomDialogData(REGISTRATION_INVALID_DATA);
    break;
  default:
    std::cout << "Unknown type of custom dialog! It will not be displayed";
  }
}

void DataService::deserializeCustomDialogData(const std::string &keyValue) {
  customDialogData.title =
      QString::fromStdString(jsonObjects.customDialogDataJson[keyValue][TITLE]);
  customDialogData.text = QString::fromStdString(jsonObjects.customDialogDataJson[keyValue][TEXT]);
  customDialogData.iconType =
      static_cast<QMessageBox::Icon>(jsonObjects.customDialogDataJson[keyValue][ICON]);

  customDialogData.buttonTypes.clear();
  for (const auto &button : jsonObjects.customDialogDataJson[keyValue][BUTTONS]) {
    customDialogData.buttonTypes.append(static_cast<QMessageBox::StandardButton>(button));
  }
}
