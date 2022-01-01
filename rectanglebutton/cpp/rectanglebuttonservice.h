#pragma once

#include <QObject>

/** Class, which provides a service functionalities of rectangle button */
class RectangleButtonService: public QObject {
Q_OBJECT
public slots:
  /** Called, when button has been released */
  void onReleased();
};
