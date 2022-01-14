#include "customdialog.h"

CustomDialogService::CustomDialogService(
    std::shared_ptr<DataService> dataServiceObject)
    : dataService(dataServiceObject) {}

void CustomDialogService::prepareToDisplay(
    CustomDialogDataset::Version version) {
  auto customDialogData = dataService->getCustomDialogData(version);
  emit display(QString::fromStdString(customDialogData.title),
               QString::fromStdString(customDialogData.text));
}
