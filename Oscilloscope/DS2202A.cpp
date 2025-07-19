#include "DS2202A.h"

DS2202A::DS2202A(const std::string& resourceName) : Oscillo(resourceName)
{
}

void DS2202A::AutoScale()
{
    // Implementation for auto-scaling the oscilloscope
    std::string command = "AUToscale\n";
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}
