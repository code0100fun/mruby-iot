# mruby-iot

This is a demo mruby app controlling various ESP32 peripherals.

This guide is written for an ESP32 with an SSD1306 like [this](https://www.aliexpress.com/item/Lolin-ESP32-OLED-wemos-for-Arduino-ESP32-OLED-WiFi-Modules-Bluetooth-Dual-ESP-32-ESP-32S/32807531243.html) one from AliExpress.

For JTAG debugging you will need a [compatible](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/jtag-debugging/#jtag-debugging-selecting-jtag-adapter) module like [this](https://www.aliexpress.com/item/FT2232HL-USB-to-UART-Module-Dual-Channel-USB-to-FIFO-SPI-I2C-JTAG-RS232-Module-CJMCU/32956642461.html) one from AliExpress.

## Setup

### CMake
Remove existing cmake:
```
$ sudo apt-get remove cmake
```

Install cmake >= 3.10

```
$ wget https://github.com/Kitware/CMake/releases/download/v3.13.2/cmake-3.13.2.tar.gz
$ tar -xvzf cmake-3.13.2.tar.gz
$ cd cmake-3.13.2
$ ./configure
$ make
$ sudo make install
```

### Ruby

Install ruby >= 1.8. This is needed to build the mruby component.

### Xtensa toolchain

Follow these [instructions](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/linux-setup.html) for Linux.

### ESP-IDF SDK

Follow these [instructions](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#get-esp-idf) for Linux.

### Permissions
Give the current user permission to connect to the USB port for programming and monitoring.
```
$ sudo usermod -a -G dialout $USER
```
Logout and re-login for this to take effect.

### VS Code

#### Extensions

* [Microsoft C/C++ tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
* [WebFreak Native Debug](https://marketplace.visualstudio.com/items?itemName=webfreak.debug)
* [CMake Tools](https://marketplace.visualstudio.com/items?itemName=vector-of-bool.cmake-tools)

### Clone

```
$ git clone --recursive git@bitbucket.org:code0100fun/mruby-iot.git
```

If you forgot to clone with `--recursive`:

```
$ git submodule update --init --recursive
```

### Configure

```
$ make menuconfig
```

Select `Component config > TarableSSD1306`
* disable SPI interface
* set SCL = 4
* set SDA = 5
* save
* exit

This will write a `sdkconfig` file.

### Build

```
$ make
```

### Flash

```
$ make flash
```

### Monitor

```
$ make monitor
```

### Debug

TODO

## References

* https://github.com/VirgiliaBeatrice/esp32-devenv-vscode/blob/master/tutorial.md
* https://github.com/FablabTorino/AUG-Torino/wiki/Wemos-Lolin-board-(ESP32-with-128x64-SSD1306-I2C-OLED-display)
