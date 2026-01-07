#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# AAPT
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxxhdpi

# Boot animation
TARGET_SCREEN_HEIGHT := 2340
TARGET_SCREEN_WIDTH := 1080

# Displayconfig
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/display/device_state_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/devicestate/device_state_configuration.xml \
    $(LOCAL_PATH)/configs/display/display_id_4630946592180194435.xml:$(TARGET_COPY_OUT_VENDOR)/etc/displayconfig/display_id_4630946592180194435.xml \
    $(LOCAL_PATH)/configs/display/display_id_4630947181303254916.xml:$(TARGET_COPY_OUT_VENDOR)/etc/displayconfig/display_id_4630947181303254916.xml \
    $(LOCAL_PATH)/configs/display/display_layout_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/displayconfig/display_layout_configuration.xml

# Init
PRODUCT_PACKAGES += \
    init.b5q.rc
# Power
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/powerhint.json:$(TARGET_COPY_OUT_VENDOR)/etc/powerhint.json

# Namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Overlays
PRODUCT_PACKAGES += \
    FrameworksResB5q \
    LineageResB5q \
    SystemUIResB5q \
    WifiResTargetB5q

# Touch features
PRODUCT_PACKAGES += \
    vendor.lineage.touch-service.samsung-b5q

# WiFi firmware symlinks
PRODUCT_PACKAGES += \
    firmware_wlanmdsp.otaupdate_symlink \
    firmware_wlan_mac.bin_symlink \
    firmware_WCNSS_qcom_cfg.ini_symlink

# Inherit from the common OEM chipset makefile.
$(call inherit-product, device/samsung/sm8550-common/common.mk)

# Inherit from the proprietary files makefile.
$(call inherit-product, vendor/samsung/b5q/b5q-vendor.mk)
