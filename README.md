# STM32F401CC Bare-Metal Peripheral Drivers

A layered, register-level **bare-metal Embedded C** driver suite for the **STM32F401CC** (ARM Cortex-M4), implemented directly from the STM32F4 reference manual without STM32 HAL dependencies.

---

## Architecture & Directory Structure

```text
stm32F4/
├── Libs/              # Common bit manipulation, fixed-width types, and register maps
│   ├── BitMath.h
│   ├── Registers.h
│   └── stmTypes.h
├── Core/              # ARM Cortex-M4 core peripheral drivers
│   ├── Inc/           # NVIC.h, SysTick.h
│   └── Src/           # NVIC.c, SysTick.c
└── MCAL/              # Microcontroller Abstraction Layer peripheral drivers
    ├── Inc/           # RCC.h, DIO.h, EXTI.h, SPI.h, UART.h, DMA.h
    └── Src/           # RCC.c, DIO.c, EXTI.c, SPI.c, UART.c, DMA.c
```

---

## Driver Implementation Status

| Layer | Module | Status |
| :--- | :--- | :--- |
| **Core** | `NVIC` (Nested Vectored Interrupt Controller) | Implemented |
| **Core** | `SysTick` (System Timer) | Implemented |
| **MCAL** | `RCC` (Reset & Clock Control) | Implemented |
| **MCAL** | `DIO` (GPIO / Digital I/O) | Implemented |
| **MCAL** | `EXTI` (External Interrupts) | Implemented |
| **MCAL** | `UART` (Serial Communication) | Implemented |
| **MCAL** | `SPI` (Serial Peripheral Interface) | Implemented |
| **MCAL** | `DMA` (Direct Memory Access) | Implemented |
| **MCAL** | `I2C`, `TIMER`, `ADC` | Planned |

---

## API Reference

### Core Drivers

#### NVIC — `Core/Inc/NVIC.h` · `Core/Src/NVIC.c`
| Function | Description |
| :--- | :--- |
| `NVIC_init` | Initializes NVIC and configures interrupt priority grouping |
| `NVIC_enableInterrupt` | Enables a specific Cortex-M4 / peripheral exception |
| `NVIC_disableInterrupt` | Disables a specific exception |
| `NVIC_setPinding` | Sets the pending flag for an exception |
| `NVIC_clearPinding` | Clears the pending flag for an exception |
| `NVIC_isActiveInterrupt` | Checks whether an exception is currently active |
| `NVIC_setPriority` | Assigns priority level to an exception |

#### SysTick — `Core/Inc/SysTick.h` · `Core/Src/SysTick.c`
| Function | Description |
| :--- | :--- |
| `SysTick_init` | Initializes SysTick clock source (`AHB` or `AHB/8`) and interrupt mode |
| `SysTick_delayMs` | Blocking millisecond delay using the SysTick counter |
| `SysTick_setCallBack` | Registers a user callback function for the SysTick ISR |

---

### MCAL Peripheral Drivers

#### RCC — `MCAL/Inc/RCC.h` · `MCAL/Src/RCC.c`
| Function | Description |
| :--- | :--- |
| `RCC_initSystemClock` | Initializes and selects the system clock source |
| `RCC_prephiralEnableClock` | Enables clock gating for a target peripheral |
| `RCC_prephiralDisableClock` | Disables clock gating for a target peripheral |

#### DIO — `MCAL/Inc/DIO.h` · `MCAL/Src/DIO.c`
| Function | Description |
| :--- | :--- |
| `DIO_init` | Configures a GPIO pin as input or output |
| `DIO_write` | Drives a GPIO output pin HIGH or LOW |
| `DIO_read` | Reads the logic level of an input pin |
| `DIO_toggel` | Toggles the output state of a GPIO pin |

#### EXTI — `MCAL/Inc/EXTI.h` · `MCAL/Src/EXTI.c`
| Function | Description |
| :--- | :--- |
| `EXTI_init` | Initializes and configures an external interrupt line |
| `EXTI_disableLine` | Disables an external interrupt line |
| `EXTI_setPinding` | Triggers/sets the pending flag for an EXTI line |

#### SPI — `MCAL/Inc/SPI.h` · `MCAL/Src/SPI.c`
| Function | Description |
| :--- | :--- |
| `SPI_init` | Initializes SPI in Master or Slave mode |
| `SPI_send` | Transmits a byte over SPI |
| `SPI_receive` | Receives a byte over SPI |
| `SPI_setCallBack` | Registers a callback function for the SPI ISR |

#### UART — `MCAL/Inc/UART.h` · `MCAL/Src/UART.c`
| Function | Description |
| :--- | :--- |
| `UART_init` | Initializes UART baud rate and frame parameters |
| `UART_send` | Transmits a byte over UART |
| `UART_receive` | Receives a byte over UART |
| `UART_setReceiveCallBack` | Registers a callback for the UART RX interrupt |
| `UART_setSendCallBack` | Registers a callback for the UART TX interrupt |

#### DMA — `MCAL/Inc/DMA.h` · `MCAL/Src/DMA.c`
| Function | Description |
| :--- | :--- |
| `DMA_transferCnfg` | Configures a memory/peripheral DMA transfer |

---

## Author
**Ibrahim Bashar** — [LinkedIn](https://www.linkedin.com/in/ibrahimbashar98/) · [GitHub](https://github.com/IbrahimMohamed98)
