#include <iostream>
#include "./SignalGenerator/DG4202.h"

int main()
{
    // Create an instance of DG4202 with the resource name
    DG4202 DG4202_A("USB0::0x1AB1::0x0641::DG4E264101726::INSTR");
    
    // Read and print the instrument ID
    std::string id = DG4202_A.ReadID();
    std::cout << "Instrument ID: " << id << std::endl;

    // Perform any additional operations with the signal generator here
    // ...

    // Disconnect from the instrument
    DG4202_A.Disconnect();

    return 0;
}
