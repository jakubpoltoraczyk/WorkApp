#include "dataservice.h"

#include <iostream>

namespace {
/** JSON file names */
constexpr char DATA_DIRECTORY[] = "data";
constexpr char LOGIN_DATA_FILE[] = "logindata.json";
constexpr char CUSTOM_DIALOG_FILE[] = "customdialogdata.json";

/** Names related to JSON file fields */
constexpr char TITLE[] = "title";
constexpr char TEXT[] = "text";
constexpr char ICON[] = "icon";
constexpr char BUTTONS[] = "buttons";

/** Map, which links custom dialog version with its string representation in JSON file */
const std::unordered_map<CustomDialogDataset::Version, std::string> CUSTOM_DIALOG_VERSIONS{
    {CustomDialogDataset::Version::LoginError, "login_error"},
    {CustomDialogDataset::Version::RegistrationSuccess, "registration_success"},
    {CustomDialogDataset::Version::RegistrationError, "registration_error"},
    {CustomDialogDataset::Version::RegistrationInvalidData, "registration_invalid_data"}};

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

DataService::OperationResult DataService::requestLogin(const std::string &login,
                                                       const std::string &password) {
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

DataService::OperationResult DataService::requestRegister(const std::string &login,
                                                          const std::string &password) {
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
    loginData.insert({singleData.key(), singleData.value()});
  }
}

void DataService::updateCustomDialogData(CustomDialogDataset::Version version) {
  const std::string keyValue = CUSTOM_DIALOG_VERSIONS.at(version);

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
