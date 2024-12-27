# print96

![print96](image todo)

print96 is a 3D-printed handwired keyboard with a 96% ANSI layout. The case uses threaded inserts and replaceable feet for fine-tuning the tilt angle. RGB indicators provide a subtle modern flair.  

* Keyboard Maintainer: [numanair](https://github.com/numanair)
* Recommended Hardware: WeAct Blue Pill Plus (STM32F103C8T6)
* Bootloader: stm32duino

Make (compile) example for this keyboard (after setting up your build environment). Run from vial-qmk main directory:

    make returntoparadise/print96:vial

Flashing example for this keyboard:

    make returntoparadise/print96:vial:flash

or using dfu-util

    dfu-util.exe -d 1eaf:0003 -a 2 -R -D "C:\source\vial-qmk\returntoparadise_print96_vial.bin"

Note: dfu-util usually shows an error on Windows around 97%. The error can be safely ignored, but the keyboard must be manually reset to leave the bootloader.  

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Physical reset button**: Briefly press the button on the underside of the keyboard. The button is marked with either: NRST, R or a red dot. The MCU should stay in the bootloader until reset with the button or dfu-util.  
* **Temporarily when plugged-in**: The MCU will enter the bootloader briefly upon being plugged in.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available (untested).  

## Hardware reference  

The Blue Pill Plus has an LED on `PB2`.  
The additional button on `PA0` is unavailable unless the matrix is changed.  

Keyboard Firmware Builder is helpful for illustrating the matrix. The `KBF-print96.json` file can be loaded into [kbfirmware.com](https://kbfirmware.com/).  

rows: 6  
columns: 19  
