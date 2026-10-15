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

static const char* const kTspCmdListNodes[] = {TSP1_CMD_LIST_NODE, TSP2_CMD_LIST_NODE};
static const char* const kTspCmdNodes[] = {TSP1_CMD_NODE, TSP2_CMD_NODE};

HighTouchPollingRate::HighTouchPollingRate() {
    for (int i = 0; i < 2; i++) {
        std::ifstream file(kTspCmdListNodes[i]);
        std::string line;
        bool hasGameMode = false, hasScanRate = false;
        while (getline(file, line)) {
            if (!line.compare("set_game_mode")) hasGameMode = true;
            if (!line.compare("set_scan_rate")) hasScanRate = true;
        }
        mTspSupported[i] = hasGameMode && hasScanRate;
    }
}

bool HighTouchPollingRate::isSupported() {
    return mTspSupported[0] || mTspSupported[1];
}

ndk::ScopedAStatus HighTouchPollingRate::getEnabled(bool* _aidl_return) {
    *_aidl_return = mEnabled;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus HighTouchPollingRate::setEnabled(bool enabled) {
    for (int i = 0; i < 2; i++) {
        if (!mTspSupported[i]) continue;
        std::ofstream file(kTspCmdNodes[i]);
        file << "set_game_mode," << (enabled ? "1" : "0");
        file.close();
        // Game mode only raises the report rate once a scan rate has been set.
        if (enabled) {
            file.open(kTspCmdNodes[i]);
            file << "set_scan_rate,1";
            file.close();
        }
    }
    mEnabled = enabled;

    return ndk::ScopedAStatus::ok();
}

}  // namespace touch
}  // namespace lineage
}  // namespace vendor
}  // namespace aidl
