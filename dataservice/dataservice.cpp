#include "dataservice.h"

DataService::DataService() { updateLoginDataset(); }

DataService::OperationResult
DataService::requestLogin(const std::string &login,
                          const std::string &password) {
  try {
    if (loginDataset.at(login) == password) {
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

void DataService::updateLoginDataset() {
  loginDataset.insert({"Login01", "Password01"});
  loginDataset.insert({"Login02", "Password02"});
  loginDataset.insert({"Login03", "Password03"});
}

void DataService::updateCustomDialogData([
    [maybe_unused]] CustomDialogDataset::Version version) {
  customDialogData.title = "Some title!";
  customDialogData.text = "Some text!";
}
