#pragma once

#include <QObject>

#include <string>

/** Contains custom dialog dataset */
namespace CustomDialogDataset {
Q_NAMESPACE
Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

/** Enumeration related to available custom dialog version */
enum class Version { Register };

/** Contains data to display in custom dialog component */
struct DataToDisplay {
  std::string title;
  std::string text;
};

} // namespace CustomDialogDataset
