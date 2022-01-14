#pragma once

#include "../../dataset/customdialogdataset.h"
#include "../../dataservice/dataservice.h"

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
  /** Emit, when custom dialog component is ready to display */
  void display(const QString & titleText, const QString & contentText);

private:
  std::shared_ptr<DataService> dataService;
};
