# LoRa module 1268F30-433 install

The objective of this project is to enable the SPI communication of G-Nice RF 1268F30-433 MHz module with the Raspbery Pi 5, as seen in the Fig.1:



<p align="center">
<img src="figures/fig2.png", alt="drawing" width="450"/>
</p>

<p align="center"><em>Fig. 1. aaaa </em></p>

## Connections
In accordance with the 1268F30 manual the SPI has an internal regulator to 3V3 operation:

<p align="center">
<img src="figures/internal_diagram.png", alt="drawing" width="450"/>
</p>

The RPI 5 has 2 common ways to refer to the pins:
- Board numbering: use the physical positions of the header
- BCM numbering: 


## Master modes
Signal name abbreviations:

- SCLK
serial clock

- CE
chip enable (often called chip select)

- MOSI
master out slave in

- MISO
master in slave out

- MOMI
master out master in

#### Standard mode
In Standard SPI mode the peripheral implements the standard three-wire serial protocol (SCLK, MOSI and MISO).

#### Bidirectional mode
In bidirectional SPI mode the same SPI standard is implemented, except that a single wire is used for data (MOMI) instead of the two used in standard mode (MISO and MOSI). In this mode, the MOSI pin serves as MOMI pin.



<p align="center">
<img src="figures/rpi_pins.png", alt="drawing" width="800"/>
</p>

[source Fig](https://www.etechnophiles.com/raspberry-pi-5-gpio-pinout/)  

<p align="center">
<img src="figures/rpi_pins2.png", alt="drawing" width="800"/>
</p>






References:   
[1268F30 manuals page](https://www.nicerf.com/lora-module/'sx1268-wireless-module-lora1268f30.html)

