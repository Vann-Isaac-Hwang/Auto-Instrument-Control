# Auto-Instrument-Control
## Currently supported instrument:
* RIGOL DG4202 Signal Generator
* RIGOL DS2202A Oscilloscope
## To setup the program
### **Part 1: Connect to instrument**
#### 1. Install NI-VISA instrument driver.
#### 2. Install corresponding instrument's official USB driver.
#### 3. Connect instrument to your computer with USB cable.
#### 4. Open NI MAX, check if the instrument connected is available in the device list.
#### 5. Try to acquire the device ID to verify that the instrument is ready.
### **Part 2: Configure environment for programming**
### (Recommended configuration)
#### 1. Install Visual Studio Code, CMake, GCC.
#### 2. Include VISA library files in CMakeLists.txt (Refer to given file, the route may differs).
#### 3. Code accoring to the manual of instruments.