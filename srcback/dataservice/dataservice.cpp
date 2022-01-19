#include "dataservice.h"

#include <fstream>
#include <nlohmann/json.hpp>

#include <iostream>

namespace {
constexpr char DATA_DIRECTORY[] = "data";
constexpr char LOGIN_DATA_FILE[] = "logindata.json";
constexpr char CUSTOM_DIALOG_FILE[] = "customdialogdata.json";

std::filesystem::path getDataDirectory() {
  auto mainDirectory = std::filesystem::current_path().parent_path();
  mainDirectory.append(DATA_DIRECTORY);
  return mainDirectory;
}
} // namespace

DataService::DataService() : dataDirectory(getDataDirectory()) {
  deserializeLoginData();
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

void DataService::deserializeLoginData() {
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

void DataService::updateCustomDialogData([
    [maybe_unused]] CustomDialogDataset::Version version) {
  auto customDialogDataFilePath = dataDirectory;
  customDialogDataFilePath.append(CUSTOM_DIALOG_FILE);
  std::ifstream customDialogDataFile(customDialogDataFilePath);

  nlohmann::json customDialogDataJson =
      nlohmann::json::parse(customDialogDataFile);

  std::cout << customDialogDataJson["login_error"]["text"] << std::endl;
}
