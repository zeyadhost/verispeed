# verispeed

A 3-key macropad built around the Seeed XIAO RP2040, with three SK6812MINI-E addressable RGB LEDs.

* Keyboard Maintainer: [Zeyad Bekhet](https://github.com/zeyadhost)
* Hardware Supported: Verispeed PCB, Seeed XIAO RP2040
* Hardware Availability: https://github.com/zeyadhost/verispeed

Make example for this keyboard (after setting up your build environment):

    make verispeed:default

Flashing example for this keyboard:

    make verispeed:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (SW1) and plug in the keyboard
* **Physical reset button**: Briefly press the RESET button on the XIAO RP2040
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
