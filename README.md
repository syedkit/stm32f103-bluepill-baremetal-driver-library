# STM32F103 Bare-Metal Driver Library

A lightweight, open-source bare-metal driver library for the STM32F103 (Blue Pill) microcontroller, developed entirely from scratch without using STM32 HAL, LL, or STM32CubeMX.

This project aims to provide clean, educational, and reusable peripheral drivers while helping beginners understand STM32 firmware development from the register level.

---

## Features

- Bare-metal GPIO Driver
- CMSIS-style Register Definitions
- Custom Startup File
- GNU Linker Script
- GNU Make Build System
- LED Blink Example
- Built and tested on real STM32F103 hardware

---

## Project Structure

```
STM32F103-Driver-Library/
│
├── Drivers/
│   ├── Inc/
│   └── Src/
│
├── Startup/
├── Linker/
├── examples/
│   └── led_blink/
│
├── Docs/
├── Makefile
└── README.md
```

---

## Supported Hardware

- STM32F103C8T6 (Blue Pill)

---

## Toolchain

- arm-none-eabi-gcc
- GNU Make
- ST-Link V2
- Linux (Tested on Zorin OS)

---

## Build

```bash
make
```

---

## Flash

```bash
st-flash write Build/led_blink.bin 0x08000000
```

---

## Current Drivers

| Driver | Status |
|---------|--------|
| GPIO | ✅ Implemented |
| RCC | 🚧 Planned |
| EXTI | 🚧 Planned |
| USART | 🚧 Planned |
| SPI | 🚧 Planned |
| I2C | 🚧 Planned |
| TIM | 🚧 Planned |
| ADC | 🚧 Planned |

---

## Project Goals

- Learn STM32 Bare-Metal Programming
- Develop reusable peripheral drivers
- Encourage community contributions
- Maintain clean and readable embedded C code

---

## Contributing

Community contributions are welcome.

Developers are encouraged to contribute:

- Peripheral Drivers
- Documentation
- Bug Fixes
- Example Projects
- Code Improvements

Please see `CONTRIBUTING.md` for contribution guidelines.

---

## License

This project is licensed under the MIT License.

---

## Author

**S.I. Syed Arshad**

Creator of the STM32F103 Bare-Metal Driver Library.
