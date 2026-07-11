# Contributing to STM32F103 Bare-Metal Driver Library

Thank you for your interest in contributing to this project.

This project was created to provide a clean, educational, and community-driven bare-metal driver library for the STM32F103 (Blue Pill) microcontroller.

Every contribution, whether large or small, is appreciated.

---

# Project Goals

The project aims to:

- Learn bare-metal embedded programming.
- Build reusable peripheral drivers.
- Maintain clean and readable code.
- Help students and engineers understand STM32 at the register level.
- Remain permanently free for everyone.

---

# Before Contributing

Please:

- Read the LICENSE file.
- Follow the project coding style.
- Test your code whenever possible.
- Keep commits focused on a single feature or fix.

---

# Coding Guidelines

## General

- Use meaningful variable names.
- Write readable code.
- Avoid unnecessary complexity.
- Add comments where required.
- Keep functions focused on one task.

---

## Naming Convention

Functions:

```c
GPIO_Init()
GPIO_Reset()
USART_Init()
SPI_Init()
```

Structures:

```c
GPIO_Handle_t
USART_Handle_t
SPI_Handle_t
```

Variables:

```c
GPIOPort
PinNumber
BitPosition
ConfigValue
```

Macros:

```c
GPIO_MODE_OUTPUT
GPIO_SPEED_2MHZ
```

---

# Folder Structure

```
Drivers/
    Inc/
    Src/

Startup/

Linker/

examples/

Docs/
```

Please keep new files inside the appropriate folders.

---

# Driver Requirements

New drivers should:

- Use register-level programming.
- Avoid STM32 HAL.
- Avoid STM32 LL libraries.
- Avoid STM32CubeMX generated code.
- Follow the existing project architecture.

---

# Pull Requests

When submitting a Pull Request:

- Clearly describe your changes.
- Mention any tested hardware.
- Keep the Pull Request focused on one topic.
- Ensure the project builds successfully.

---

# Contributor Credit

Every contributor will receive proper credit for their work.

Contributor names must never be removed from the project history.

---

# Community

Respect other contributors.

Constructive discussions, suggestions, bug reports, and improvements are always welcome.

---

Thank you for helping improve this project.

Happy Coding!

— S.I. SYED ARSHAD
Creator of the STM32F103 Bare-Metal Driver Library
