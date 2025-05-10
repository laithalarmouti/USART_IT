# STM32F4 USART2 Initialization & System Exception Configuration

This project demonstrates manual configuration of **MCU Support Package (MSP)** initialization functions, **USART2 peripheral setup**, and **SysTick interrupt handler** using STM32 HAL on an STM32F4 microcontroller.

It is a low-level initialization example focusing on:

 NVIC priority grouping  
 Enabling system fault exceptions (Usage Fault, Bus Fault, Memory Fault)  
 USART2 GPIO pin muxing (TX/RX)  
 USART2 interrupt enabling and priority configuration  
 Custom `SysTick_Handler` implementation

---

##  Features

- Configures **NVIC priority grouping** to `NVIC_PRIORITYGROUP_4`
- Enables **system-level exceptions** (Usage, Bus, Memory Faults)
- Initializes **USART2 (TX on PA2, RX on PA3)**
- Configures **GPIOA pins** for USART2 alternate function
- Enables **USART2 interrupt with priority 15**
- Implements a custom `SysTick_Handler` calling HAL tick functions
- Additionally, this project includes functionality to receive characters over USART2, convert them to uppercase, and send them back via USART2. This demonstrates basic UART interrupt handling and character processing on the STM32F4.

---

##  Hardware Requirements

- STM32F4 microcontroller (tested on STM32F411RE Nucleo)
- USART2 pins:
  - **TX → PA2**
  - **RX → PA3**
- Serial monitor (TeraTerm, PuTTY, etc.) to view UART output

##  How It Works

- `HAL_MspInit()` configures interrupt priority grouping and enables exceptions.
- `HAL_UART_MspInit()` initializes USART2 clocks, GPIO pins, and interrupt priority.
- `SysTick_Handler()` increments HAL tick counter and handles system ticks.

---

##  Building & Running

1. Open the project in **STM32CubeIDE** (or your IDE of choice).
2. Build the project.
3. Flash to your STM32F4 board.
4. Connect a serial monitor to view USART2 output at the configured baud rate.
