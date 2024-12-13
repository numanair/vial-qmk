# print96

![print96](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [numanair](https://github.com/numanair)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make print96:default

Flashing example for this keyboard:

    make print96:default:flash

or using dfu-util

    dfu-util.exe -d 1eaf:0003 -a 2 -R -D "C:\source\vial-qmk\returntoparadise_print96_vial.bin"

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

    // PB2 led
    // PA0 button

----
rows: 6
columns: 19
