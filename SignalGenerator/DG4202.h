/**
 ******************************************************************************
 * @file    DG4202.h
 * @author  Isaac Huang
 * @brief   This file contains the common defines and functions prototypes for the
 *          RIGOL DG4202 function generator. Based on the VISA library, SCPI commands
 *          are used to control the instrument.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DG4202_H__
#define __DG4202_H__

/* Includes ------------------------------------------------------------------*/
#include "SigGen.h"

class DG4202 : public SigGen
{
public:
    DG4202(const std::string& resourceName) : SigGen(resourceName) {}

    // Basic Functions
    void Channel_ON(int channel, bool enable = true);   // Enable or disable a channel
    void Set_frequency(int channel, int frequency_Hz);  // Set frequency
    void Set_amplitude(int channel, double amplitude);  // Set amplitude
    void Set_waveform(int channel, Waveform waveform);  // Set waveform type

    // Set Modulation (FM, AM, FSK, ASK)
    void Modulate(int channel, Modulation modType, bool enable = true); // Enable or disable modulation
    void Set_Mod_Frequency_Internal(int channel, Modulation modType, int frequency_Hz); // Set modulation frequency
    // FM Modulation Setters
    void Set_FM_deviation(int channel, int deviation);  // Set FM deviation
    // AM Modulation Setters
    void Set_AM_depth(int channel, int depth_percent);  // Set AM modulation depth
    // FSK Modulation Setters
    void Set_FSK_Rate(int channel, int frequency_Hz);   // Set FSK rate
    void Set_FSK_Polarity(int channel, bool positive);  // Set FSK polarity
    void Set_FSK_KeyFrequency(int channel, int frequency_Hz);   // Set FSK key frequency
    // ASK Modulation Setters
    void Set_ASK_amplitude(int channel, double amplitude);  // Set ASK amplitude
    void Set_ASK_frequency(int channel, int frequency_Hz);  // Set ASK frequency
};

#endif // __DG4202_H__