#pragma once

#include <QObject>

/** Class, which provides service functionalities of input component */
class InputComponentService : public QObject {
  Q_OBJECT
public slots:
  /** Called, when editing has been finished */
  void onEditingFinished();
};
