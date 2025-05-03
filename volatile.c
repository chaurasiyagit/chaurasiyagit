#⚡ Bitwise Operators and Volatile in Embedded C 

📢 Volatile “Don’t optimize this variable—it might change outside the program’s control (like by hardware). Always read it from memory.”

📻 What are Hardware Registers:
Control Registers: Configure operation modes (e.g., enable/disable, interrupt settings).
Status Registers: Show current status (e.g., flags, errors).
Data Registers: Used to read or write data (e.g., transmit or receive buffers).

💡  Scenario:
You’re writing code to monitor or control the CAN transceiver (e.g., TJA1043, TLE9251, etc.) via memory-mapped registers or digital I/O pins.
These registers control or reflect:
Transceiver modes (Normal, Standby, Sleep)
📍 Typical Setup:
Suppose the CAN transceiver provides a status register at address 0x40005000 that indicates transceiver state.

volatile ensures every read is from the actual memory address.
hashtag#define CAN_TRCV_STATUS_REG (*(volatile uint8_t*)0x40005000)
Here, the transceiver updates the status register independently (outside the MCU's direct control).
