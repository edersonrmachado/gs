#include <RadioLib.h>
#include <PiHal.h>
#include <iostream>

PiHal* hal = new PiHal(0);

// NSS(GPIO5), DIO1(GPIO22), RESET(GPIO27), BUSY(GPIO17)
SX1268 radio = new Module(hal, 5, 22, 27, 17);

int main() {

    std::cout << "Initializing SX1268..." << std::endl;

    int state = radio.begin(
        434.0, // freq
        125.0, // bw
        9,  // SF
        7,  // CR
        0x12, // Sync Word
        10, // output power (dBm)
        8   // preamble len
    );

    if(state != RADIOLIB_ERR_NONE) {
        std::cout << "Initialization failed: " << state << std::endl;
        return 1;
    }

    std::cout << "Radio initialized successfully!" << std::endl;

    // Message to transmit
    std::string message = "Hello Hello Nes";

    std::cout << "Transmitting: " << message << std::endl;

    // Send message
    state = radio.transmit(message.c_str());

    if(state == RADIOLIB_ERR_NONE) {
        std::cout << "Message transmitted successfully!" << std::endl;
    } else {
        std::cout << "Transmission failed: " << state << std::endl;
    }

    return 0;
}