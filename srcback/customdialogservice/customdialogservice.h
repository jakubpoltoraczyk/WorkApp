#pragma once

#include "../dataservice/dataservice.h"
#include "../dataset/customdialogdataset.h"

#include <QObject>
#include <QString>

#include <memory>

/** Class, which represents a service of custom dialog */
class CustomDialogService : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Create new instance of class
   * @param dataServiceObject Service for dataset operations
   */
  CustomDialogService(std::shared_ptr<DataService> dataServiceObject);

public slots:
  /**
   * @brief Prepare custom dialog component to be displayed according to
   * appropriate version
   * @param version Version, in which one custom dialog will be displayed
   */
  void prepareToDisplay(CustomDialogDataset::Version version);

signals:
  /**
   * @brief Emitted, when custom dialog component is ready to display
   * @param titleText Title text to set in custom dialog
   * @param contentText Content text to set in custom dialog
   * @param iconType Icon type to set in custom dialog
   * @param buttonTypes Button types to set in custom dialog
   */
  void display(const QString &titleText, const QString &contentText, int iconType,
               QVector<int> buttonTypes);

private:
  std::shared_ptr<DataService> dataService;
};
