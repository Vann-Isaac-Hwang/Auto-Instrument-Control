#ifndef __DS2202A_H__
#define __DS2202A_H__

#include "Oscillo.h"

class DS2202A : public Oscillo
{
public:
    DS2202A(const std::string& resourceName);

    // Basic Functions
    void AutoScale(); // Auto scale the oscilloscope
    
};

#endif // __DS2202A_H__