#pragma once

#include <QObject>

/** Contains input component dataset */
namespace InputComponentDataset {
Q_NAMESPACE
Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

/** Enumeration related to available input component modes */
enum class Mode { NORMAL, PASSWORD };
Q_ENUM_NS(Mode)
} // namespace InputComponentDataset
