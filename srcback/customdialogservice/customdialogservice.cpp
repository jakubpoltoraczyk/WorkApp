#include "customdialogservice.h"

#include <algorithm>

CustomDialogService::CustomDialogService(std::shared_ptr<DataService> dataServiceObject)
    : dataService(dataServiceObject) {}

void CustomDialogService::prepareToDisplay(CustomDialogDataset::Version version) {
  auto customDialogData = dataService->getCustomDialogData(version);
  const auto &originalButtonTypes = customDialogData.buttonTypes;

  QVector<int> buttonTypes;
  buttonTypes.reserve(originalButtonTypes.size());
  std::copy(originalButtonTypes.begin(), originalButtonTypes.end(),
            std::back_inserter(buttonTypes));

  emit display(customDialogData.title, customDialogData.text, customDialogData.iconType,
               std::move(buttonTypes));
}
