#include "DG4202.h"

void DG4202::Channel_ON(int channel, bool enable)
{
    // Implementation to turn on or off a specific channel
    std::string command = "OUTPut" + std::to_string(channel) + ":STATe" + (enable ? " ON" : " OFF") + "\n";
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_frequency(int channel, int frequency_Hz)
{
    // Implementation to set the frequency for a specific channel
    std::string command = "SOURce" + std::to_string(channel) + ":FREQuency " + std::to_string(frequency_Hz) + "\n";
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_amplitude(int channel, double amplitude)
{
    // Implementation to set the amplitude for a specific channel
    std::string command = "SOURce" + std::to_string(channel) + ":VOLTage:AMPLitude " + std::to_string(amplitude) + "\n";
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_waveform(int channel, Waveform waveform)
{
    // Implementation to set the waveform type for a specific channel
    std::string command = "SOURce" + std::to_string(channel) + ":FUNCtion ";
    switch (waveform)
    {
        case SINE: command += "SINusoid"; break;
        case SQUARE: command += "SQUare"; break;
        case TRIANGLE: command += "RAMP"; break;
        case PULSE: command += "PULSe"; break;
    }
    command += "\n";
    printf("Command: %s", command.c_str());
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Modulate(int channel, Modulation modType, bool enable)
{
    // Enable or disable modulation for a specific channel
    std::string command = "SOURce" + std::to_string(channel) + ":MOD:STATe " + (enable ? "ON" : "OFF") + "\n";
    viPrintf(instrument, const_cast<char *>(command.c_str()));

    // Set modulation type if enabling
    if (enable)
    {
        std::string typeStr;
        switch (modType)
        {
            case AM:  typeStr = "AM";  break;
            case FM:  typeStr = "FM";  break;
            case ASK: typeStr = "ASK"; break;
            case FSK: typeStr = "FSK"; break;
            default:  typeStr = "AM";  break;
        }
        std::string typeCmd = "SOURce" + std::to_string(channel) + ":MOD:TYPe " + typeStr + "\n";
        viPrintf(instrument, const_cast<char *>(typeCmd.c_str()));
    }
}

void DG4202::Set_Mod_Frequency_Internal(int channel, Modulation modType, int frequency_Hz)
{
    // Implementation to set the modulation frequency for a specific channel
    std::string command = "MODFREQ" + std::to_string(channel) + " " + std::to_string(frequency_Hz);
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_FM_deviation(int channel, int deviation)
{
    // Implementation to set FM deviation for a specific channel
    std::string command = "FMDEV" + std::to_string(channel) + " " + std::to_string(deviation);
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_AM_depth(int channel, int depth_percent)
{
    // Implementation to set AM modulation depth for a specific channel
    std::string command = "AMDEP" + std::to_string(channel) + " " + std::to_string(depth_percent);
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_FSK_Rate(int channel, int rate)
{
    // Implementation to set FSK rate for a specific channel
    std::string command = "FSKRATE" + std::to_string(channel) + " " + std::to_string(rate);
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_FSK_Polarity(int channel, bool positive)
{
    // Implementation to set FSK polarity for a specific channel
    std::string command = "FSKPOL" + std::to_string(channel) + (positive ? ":POS" : ":NEG");
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_FSK_KeyFrequency(int channel, int frequency_Hz)
{
    // Implementation to set FSK key frequency for a specific channel
    std::string command = "FSKKEYFREQ" + std::to_string(channel) + " " + std::to_string(frequency_Hz);
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_ASK_amplitude(int channel, double amplitude)
{
    // Implementation to set ASK amplitude for a specific channel
    std::string command = "ASKAMP" + std::to_string(channel) + " " + std::to_string(amplitude);
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}

void DG4202::Set_ASK_frequency(int channel, int frequency_Hz)
{
    // Implementation to set ASK frequency for a specific channel
    std::string command = "ASKFREQ" + std::to_string(channel) + " " + std::to_string(frequency_Hz);
    viPrintf(instrument, const_cast<char *>(command.c_str()));
}