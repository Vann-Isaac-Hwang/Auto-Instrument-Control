#ifndef __OSCILLO_H__
#define __OSCILLO_H__

#include <iostream>
#include <string>
#include <visa.h>

class Oscillo
{
protected:
    // Resource name for the oscilloscope
    char* resourceName;
    // Instrument Variables
    ViSession defaultRM, instrument;
    ViStatus status;
    // Buffer to hold the returned message
    char RX_buffer[256];
public:
    // Constructor, connect to the instrument according to the resource name
    Oscillo(const std::string InstrumentResourceName);
    // Read the instrument ID
    std::string ReadID();
    // Disconnect from the instrument
    int Disconnect();
    // Destructor to ensure resources are cleaned up
    ~Oscillo();
};

#endif // __OSCILLO_H__