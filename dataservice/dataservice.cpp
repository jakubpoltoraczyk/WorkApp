#include "dataservice.h"

DataService::DataService() { updateLoginDataset(); }

DataService::OperationResult
DataService::requestLogin(const std::string &login,
                          const std::string &password) {
  try {
    if (loginDataset.at(login) == password) {
      return OperationResult::Success;
    } else {
      return OperationResult::Failure;
    }
  } catch (const std::out_of_range &error) {
    return OperationResult::Failure;
  }
}

void DataService::updateLoginDataset() {
  loginDataset.insert({"Login01", "Password01"});
  loginDataset.insert({"Login02", "Password02"});
  loginDataset.insert({"Login03", "Password03"});
}
