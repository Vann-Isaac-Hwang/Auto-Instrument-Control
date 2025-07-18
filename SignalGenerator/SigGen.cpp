#include "SigGen.h"

// Constructor, connect to the instrument according to the resource name
SigGen::SigGen(const std::string InstrumentResourceName) : defaultRM(VI_NULL), instrument(VI_NULL)
{
    this->resourceName = const_cast<char*>(InstrumentResourceName.c_str());

    // Initialize VISA Session
    status = viOpenDefaultRM(&defaultRM);
    if (status < VI_SUCCESS)
    {
        // Handle error opening signal generator
        std::cerr << "Error opening signal generator: " << status << std::endl;
        throw std::runtime_error("Failed to open signal generator.");
    }

    // Open Instrument Connection
    status = viOpen(defaultRM, this->resourceName, VI_NULL, VI_NULL, &instrument);
    if (status < VI_SUCCESS)
    {
        printf("Cannot connect Instrument\n");
        viClose(defaultRM);
        throw std::runtime_error("Failed to connect to instrument.");
    }
}

std::string SigGen::ReadID()
{
    // Read Instrument ID
    viQueryf(instrument, "*IDN?\n", "%t", RX_buffer);
    return RX_buffer;
}

int SigGen::Disconnect()
{
    // Close the instrument session
    if (instrument != VI_NULL)
    {
        status = viClose(instrument);
        if (status < VI_SUCCESS)
        {
            std::cerr << "Error closing instrument: " << status << std::endl;
            return -1; // Error closing instrument
        }
        instrument = VI_NULL;
    }

    // Close the default resource manager session
    if (defaultRM != VI_NULL)
    {
        status = viClose(defaultRM);
        if (status < VI_SUCCESS)
        {
            std::cerr << "Error closing default resource manager: " << status << std::endl;
            return -1; // Error closing resource manager
        }
        defaultRM = VI_NULL;
    }

    return 0; // Success
}

SigGen::~SigGen()
{
    Disconnect();
}