#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit_only.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from the device configuration.
$(call inherit-product, device/samsung/b5q/device.mk)

# Inherit from the Lineage configuration.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

PRODUCT_NAME := lineage_b5q
PRODUCT_DEVICE := b5q
PRODUCT_BRAND := samsung
PRODUCT_MODEL := SM-F731B
PRODUCT_MANUFACTURER := Samsung

PRODUCT_GMS_CLIENTID_BASE := android-samsung

PRODUCT_BUILD_PROP_OVERRIDES += \
    BuildDesc="b5qxxx-user 15 AP3A.240905.015.A2 F731BXXS5EYE5 release-keys" \
    BuildFingerprint=samsung/b5qxxx/b5q:13/TP1A.220624.014/F731BXXS5EYE5:user/release-keys \
    DeviceProduct=b5q \
    SystemName=b5q
