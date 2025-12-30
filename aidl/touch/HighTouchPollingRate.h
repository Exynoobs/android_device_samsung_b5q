/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/vendor/lineage/touch/BnHighTouchPollingRate.h>
#include "samsung_touch.h"
#include <fstream>

namespace aidl {
namespace vendor {
namespace lineage {
namespace touch {

class HighTouchPollingRate : public BnHighTouchPollingRate {
  public:
    HighTouchPollingRate() {
        std::ifstream file1(TSP1_CMD_LIST_NODE);
        if (file1.is_open()) {
            mHtprCmd = "";
            std::string line;
            while (getline(file1, line)) {
                if (!line.compare("set_game_mode") || !line.compare("set_scan_rate")) {
                    mHtprCmd = line;
                    break;
                }
            }
            file1.close();
        }
        std::ifstream file2(TSP2_CMD_LIST_NODE);
        if (file2.is_open()) {
            mHtprCmd = "";
            std::string line;
            while (getline(file2, line)) {
                if (!line.compare("set_game_mode") || !line.compare("set_scan_rate")) {
                    mHtprCmd = line;
                    break;
                }
            }
            file2.close();
        }
    }

    bool isSupported();

    ndk::ScopedAStatus getEnabled(bool* _aidl_return) override;
    ndk::ScopedAStatus setEnabled(bool enabled) override;

  private:
    std::string mHtprCmd;
};

}  // namespace touch
}  // namespace lineage
}  // namespace vendor
}  // namespace aidl
