#pragma once

#include <QObject>

/** Contains dataset related to window manager */
namespace WindowManagerDataset {
Q_NAMESPACE
Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

/** Contains available types of window */
enum class WindowType { LoginWindow };
Q_ENUM_NS(WindowType)
} // namespace WindowManagerDataset
