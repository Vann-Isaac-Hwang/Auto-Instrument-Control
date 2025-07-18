cmake_minimum_required(VERSION 3.10.0)
project(AutoInstrumentControl VERSION 0.1.0 LANGUAGES C CXX)

add_executable(AutoInstrumentControl main.cpp 
    ./SignalGenerator/SigGen.cpp 
    ./SignalGenerator/DG4202.cpp)

include_directories("C:/Program Files/IVI Foundation/VISA/Win64/Include")

target_link_libraries(AutoInstrumentControl PRIVATE "C:/Program Files/IVI Foundation/VISA/Win64/Lib_x64/msc/visa64.lib")
target_link_libraries(AutoInstrumentControl PRIVATE "C:/Program Files/IVI Foundation/VISA/Win64/Lib_x64/msc/visa32.lib")
target_link_libraries(AutoInstrumentControl PRIVATE "C:/Program Files/IVI Foundation/VISA/Win64/Lib_x64/msc/nivisa64.lib")
