#include <iostream>
#include "./SignalGenerator/DG4202.h"
#include "./Oscilloscope/DS2202A.h"

void DG4202Example()
{
    // Create an instance of DG4202 with the resource name
    DG4202 DG4202_A("USB0::0x1AB1::0x0641::DG4E264101726::INSTR");
    
    // Read and print the instrument ID
    std::string id = DG4202_A.ReadID();
    std::cout << "Instrument ID: " << id << std::endl;

    // Perform any additional operations with the signal generator here
    DG4202_A.Channel_ON(1, true);  // Enable channel 1
    DG4202_A.Set_frequency(1, 1000); // Set frequency for channel 1 to 1000 Hz
    DG4202_A.Set_amplitude(1, 2.0);   // Set amplitude for channel 1 to 5.0 V
    DG4202_A.Set_waveform(1, SINE); // Set waveform for channel 1 to SINE
    DG4202_A.Modulate(1, AM, true); // Enable AM modulation on channel 1
    DG4202_A.Set_AM_depth(1, 100); // Set AM modulation depth to 100%

    // Disconnect from the instrument
    DG4202_A.Disconnect();
}

void DS2202AExample()
{
    // Create an instance of DS2202A with the resource name
    DS2202A oscilloscope("USB0::0x1AB1::0x04B0::DS2D264601325::INSTR");
    
    // Read and print the instrument ID
    std::string id = oscilloscope.ReadID();
    std::cout << "Instrument ID: " << id << std::endl;

    // Perform auto-scaling on the oscilloscope
    oscilloscope.AutoScale();

    // Disconnect from the instrument
    oscilloscope.Disconnect();
}

int main()
{
    DS2202AExample();

    return 0;
}
