# stm32F4
-This repo includes BareMetal drivers for stm32F401cc prephirals according to the manual

-The repo include 3 parts : 
- Libs  (BitMath.h , Registers.h , stmTypes.h)                                
- MCAL  (Which includes prepheral Drivers)
- Core  (Which includes Core drivers) 

## Repo content 
   
  DONE        | Module   
:-------------|----------
  &#10004;    | DIO      
  &#10004;    | UART     
  &#10004;    | SPI      
  &#10006;    | I2C      
  &#10004;    | SysTick  
  &#10004;    | NVIC     
  &#10004;    | EXTI     
  &#10004;    | RCC      
  &#10004;    | DMA
  &#10006;   | TIMER
    





## API Reference

#### DIO module

```http
header -> MCAL/Inc/DIO.h
source -> MCAL/Src/DIO.c
```

| Function    |  Description                                         |
| :--------   |  :---------------------------------------------------|
| `DIO_init`  |  *Initiate certain pin to be either output or input* |
| `DIO_write` |  *make a certain pin to be either HIGH or LOW output*|
| `DIO_read`  |  *Reads a certain pin logic level either HIGH or LOW*|
| `DIO_toggel`|  *Toggels a certain pin logic*                       |

#### SPI module

```http
header -> MCAL/Inc/SPI.h
source -> MCAL/Src/SPI.c
```

| Function          |  Description                                         |
| :--------         |  :---------------------------------------------------|
| `SPI_init`        |  *Initiate  SPI to be either MASTER or SLAVE*     |
| `SPI_send`        |  *Sends a Byte over SPI*                             |
| `SPI_receive`     |  *Recieve a Byte over SPI*                           |
| `SPI_setCallBack` |  *Sets the SPI ISR functionality*                    |

#### UART module

```http
header -> MCAL/Inc/UART.h
source -> MCAL/Src/UART.c
```

| Function                   |  Description                                         |
| :--------                  |  :---------------------------------------------------|
| `UART_init`                |  *Initiate  UART and configure it's attributes*   |
| `UART_send`                |  *Sends a Byte over UART*                            |
| `UART_receive`             |  *Recieve a Byte over UART*                          |
| `UART_setReceiveCallBack`  |  *Sets the UART receive ISR functionality*           |
| `UART_setSendCallBack`     |  *Sets the SPI send ISR functionality*               |

## Author

- [@IbrahimMohamed98](https://www.github.com/IbrahimMohamed98)
