/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <fstream>

#include "HighTouchPollingRate.h"

namespace aidl {
namespace vendor {
namespace lineage {
namespace touch {

bool HighTouchPollingRate::isSupported() {
    return !mHtprCmd.empty();
}

ndk::ScopedAStatus HighTouchPollingRate::getEnabled(bool* _aidl_return) {
    std::ifstream file1(TSP1_CMD_RESULT_NODE);
    if (file1.is_open()) {
        std::string line;
        getline(file1, line);
        *_aidl_return = !line.compare(mHtprCmd + ",1:OK");
        file1.close();
    }
    std::ifstream file2(TSP2_CMD_RESULT_NODE);
    if (file2.is_open()) {
        std::string line;
        getline(file2, line);
        *_aidl_return = !line.compare(mHtprCmd + ",1:OK");
        file2.close();
    }
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus HighTouchPollingRate::setEnabled(bool enabled) {
    std::ofstream file1(TSP1_CMD_NODE);
    file1 << (mHtprCmd + ",") << (enabled ? "1" : "0");
    file1.close();
    std::ofstream file2(TSP2_CMD_NODE);
    file2 << (mHtprCmd + ",") << (enabled ? "1" : "0");
    file2.close();

    return ndk::ScopedAStatus::ok();
}

}  // namespace touch
}  // namespace lineage
}  // namespace vendor
}  // namespace aidl
