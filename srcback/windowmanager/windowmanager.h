#pragma once

#include "../dataset/windowmanagerdataset.h"

#include <QObject>

/** Class, which provides possibility to manage windows in application */
class WindowManager : public QObject {
  Q_OBJECT
signals:
  /** Hide splash screen window */
  void hideSplashScreen();

  /** Show splash screen window */
  void showSplashScreen();

  /**
   * @brief Create new window using specified window type
   * @param windowType Type of the window, which will be created
   */
  void createWindow(WindowManagerDataset::WindowType windowType);
};
