#pragma once

#include <QMessageBox>
#include <QObject>
#include <QVector>

/** Contains custom dialog dataset */
namespace CustomDialogDataset {
/** Enumeration related to available custom dialog version */
enum class Version { LoginError, RegistrationSuccess, RegistrationError, RegistrationInvalidData };

/** Contains data to display in custom dialog component */
struct DataToDisplay {
  QString title;              ///< Title text to display in custom dialog component
  QString text;               ///< Content text to display in custom dialog component
  QMessageBox::Icon iconType; ///< Icon to display in custom dialog component
  QVector<QMessageBox::StandardButton>
      buttonTypes; ///< Button types to display in custom dialog component
};
} // namespace CustomDialogDataset
