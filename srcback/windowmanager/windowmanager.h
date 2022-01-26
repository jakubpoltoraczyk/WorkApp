#pragma once

#include "../dataset/windowmanagerdataset.h"

#include <QObject>

/** Class, which provides functionalities to manage applications windows */
class WindowManager : public QObject {
  Q_OBJECT
signals:
  /**
   * @brief Emitted, when window of specified type should be shown
   * @param windowType Type of the window, which should be displayed
   */
  void showWindow(WindowManagerDataset::WindowType windowType);

  /**
   * @brief Emitted, when window of specified type should be hidden
   * @param windowType Type of the window, which should be hidden
   */
  void hideWindow(WindowManagerDataset::WindowType windowType);

  /**
   * @brief Emitted, when new window of specified type should be created
   * @param windowType Type of the window, which should be created
   */
  void createWindow(WindowManagerDataset::WindowType windowType);

  /**
   * @brief Emitted, when existing window of specified type should be deleted
   * @param windowType Type of the window, which should be deleted
   */
  void deleteWindow(WindowManagerDataset::WindowType windowType);
};
