# MCU and Bootloader setup
MCU = atmega32u4
BOOTLOADER = caterina

# Hardware Features
BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes      # Mouse keys support
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes          # USB N-Key Rollover

# Pointing Device (Trackball Sensor)
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = adns5050

# Rotary Encoder Support
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes