#pragma once

#include <map>

/** Class, which represents service for dataset operations */
class DataService {
public:
  /** Create a new instance of class */
  DataService();

  /** Contains types of each operation result */
  enum class OperationResult {Success, Failure};

  /**
   * @brief Request login operation
   * @param login User's login
   * @param password User's password
   * @return Success if login request finished successfully, otherwise Failure
   */
  OperationResult requestLogin(const std::string &login, const std::string &password);

private:
  void updateLoginDataset();

  std::map<std::string, std::string>
      loginDataset; // Map with login as a key and password as a value
};
