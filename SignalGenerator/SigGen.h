#ifndef __SIGGEN_H__
#define __SIGGEN_H__

#include <iostream>
#include <string>
#include <visa.h>

enum Waveform
{
    SINE,
    SQUARE,
    TRIANGLE,
    PULSE
};

enum Modulation
{
    FM,
    AM,
    FSK,
    ASK
};

class SigGen
{
protected:
    // Resource name for the signal generator
    char* resourceName;
    // Instrument Variables
    ViSession defaultRM, instrument;
    ViStatus status;
    // Buffer to hold the returned message
    char RX_buffer[256];
public:
    // Constructor, connect to the instrument according to the resource name
    SigGen(const std::string InstrumentResourceName);
    // Read the instrument ID
    std::string ReadID();
    // Disconnect from the instrument
    int Disconnect();
    // Destructor to ensure resources are cleaned up
    ~SigGen();
};

#endif // __SIGGEN_H__