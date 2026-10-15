/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <fstream>

#include "GloveMode.h"

namespace aidl {
namespace vendor {
namespace lineage {
namespace touch {

bool GloveMode::isSupported() {
    std::ifstream file1(TSP1_CMD_LIST_NODE);
    if (file1.is_open()) {
        std::string line;
        while (getline(file1, line)) {
            if (!line.compare("glove_mode")) return true;
        }
        file1.close();
    }
    std::ifstream file2(TSP2_CMD_LIST_NODE);
    if (file2.is_open()) {
        std::string line;
        while (getline(file2, line)) {
            if (!line.compare("glove_mode")) return true;
        }
        file2.close();
    }
    return false;
}

ndk::ScopedAStatus GloveMode::getEnabled(bool* _aidl_return) {
    *_aidl_return = mEnabled;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus GloveMode::setEnabled(bool enabled) {
    std::ofstream file1(TSP1_CMD_NODE);
    file1 << "glove_mode," << (enabled ? "1" : "0");
    file1.close();
    std::ofstream file2(TSP2_CMD_NODE);
    file2 << "glove_mode," << (enabled ? "1" : "0");
    file2.close();
    mEnabled = enabled;

    return ndk::ScopedAStatus::ok();
}

}  // namespace touch
}  // namespace lineage
}  // namespace vendor
}  // namespace aidl
