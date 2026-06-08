# LoRa module 1268F30-433 install

The objective of this project is to enable the SPI communication of G-Nice RF 1268F30-433 MHz module with the Raspbery Pi 5. This file is a draft, it will be rewritten soon.

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

## Standard mode
In Standard SPI mode the peripheral implements the standard three-wire serial protocol (SCLK, MOSI and MISO).

## Bidirectional mode
In bidirectional SPI mode the same SPI standard is implemented, except that a single wire is used for data (MOMI) instead of the two used in standard mode (MISO and MOSI). In this mode, the MOSI pin serves as MOMI pin.



<p align="center">
<img src="figures/rpi_pins.png", alt="drawing" width="800"/>
</p>

[source Fig](https://www.etechnophiles.com/raspberry-pi-5-gpio-pinout/)  

<p align="center">
<img src="figures/rpi_pins2.png", alt="drawing" width="700"/>
</p>






References:   
[1268F30 manuals page](https://www.nicerf.com/lora-module/sx1268-wireless-module-lora1268f30.html)



# Set up RPI-5 to use SPI

## STEP 1 - Installing OS + saving SDmicro card

OS installed:

```bash
$ cat /etc/os-release
PRETTY_NAME="Debian GNU/Linux 13 (trixie)"
NAME="Debian GNU/Linux"
VERSION_ID="13"
VERSION="13 (trixie)"
VERSION_CODENAME=trixie
DEBIAN_VERSION_FULL=13.1
ID=debian
HOME_URL="https://www.debian.org/"
SUPPORT_URL="https://www.debian.org/support"
BUG_REPORT_URL="https://bugs.debian.org/"
```


## STEP 2 - Recovering IP and MAC from a known network

Problem: I've installed the RPI with a known WiFi network, but I don't remember the IP to access it via SSH. I would also discover the MAC to be registered for another network, just in case. 

2.1 Install nmap to network scan

```bash
sudo snap install nmap
```

2.2 Scan the network from host numbers for 0 to 254  

I already know that the network prefix  is 192.168.100, and each IP is a number 192.168.100.x where x is the host identifier, so I search from x=1 to x=254, 24 bits for network and 8 bits to host idn, with following command:   


```bash
nmap -sn  192.168.100.0/24  
```

and found a line containing:  

```bash
Nmap scan report for raspberrypi.lan (192.168.100.183)
```

So I supposed it is my RPI IP, because when I disconnect it this IP disappear.


2.3 SSH access  

Password: lacom

```bash
ssh pi@192.168.100.183
```
```bash
ssh pi@192.168.100.183
pi@192.168.100.183's password: 
Linux raspberrypi 6.12.47+rpt-rpi-2712 #1 SMP PREEMPT Debian 1:6.12.47-1+rpt1 (2025-09-16) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Oct  8 14:49:32 2025 from 192.168.100.114
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
-bash: warning: setlocale: LC_CTYPE: cannot change locale (pt_BR.UTF-8): No such file or directory
pi@raspberrypi:~ $ 
```


2.4 Discovering MAC

with command: 

```bash
ip addr
```


```bash 
pi@raspberrypi:~ $ ip addr
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute 
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc fq_codel state DOWN group default qlen 1000
    link/ether 2c:cf:67:24:83:29 brd ff:ff:ff:ff:ff:ff
3: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 2c:cf:67:24:83:2a brd ff:ff:ff:ff:ff:ff
    inet 192.168.100.183/24 brd 192.168.100.255 scope global dynamic noprefixroute wlan0
       valid_lft 43043sec preferred_lft 43043sec
    inet6 fe80::795e:1bb2:2d86:c345/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
```
Then: 


|interface| MAC|
|:-:|:-:|
| eth0| 2c:cf:67:24:83:29 | 
| wlan0 | 2c:cf:67:24:83:2a | 


## STEP 3  See if SPI is enabled

We could see if the SPI is enable (could be disable by default) by using the command:

```bash
pi@raspberrypi:~ $ ls /dev/spidev*
/dev/spidev10.0
```


In the case we see an extra SPI inteface active bus/SPI controller 10, CS0, but we search for  
/dev/spidev0.0  /dev/spidev0.1 (bus/SPI controler 0 and CS0 or CS1). So we can active it using the command 

```bash 
sudo raspi-config
```
It opens an interface, where whe go to the "`3. Interface Options...`"

<p align="center">
<img src="figures/interface1.png", alt="drawing" width="700"/>
</p>


and enable automatic loading SPI kernel module : 

<p align="center">
<img src="figures/interface2.png", alt="drawing" width="700"/>
</p>

<p align="center">
<img src="figures/interface3.png", alt="drawing" width="700"/>
</p>


Thus,  after go out of the interface,  we check the SPI again:

```bash
pi@raspberrypi:~ $ ls /dev/spidev*
/dev/spidev0.0  /dev/spidev0.1  /dev/spidev10.0
```

Now bus 0, CS=0 and CS=1 are activated.


## Comunicate with 1268F30 via SPI using Radiolib

Once RPI is accessed by ssh:


### STEP 1 install prerequisites on RPI 5
1.1 RPI utils
 - git 
 - build-essentials: install g++ compiler, make, libc-dev (to talk with SPI chip)
 - cmake: manage installation  
 - liblgpio-dev: control RPI GPIOs 

```bash
sudo apt update
sudo apt install build-essential cmake git liblgpio-dev
```
1.2 Radiolib 
Before it, create a folder in Desktop for the project

```bash
cd Desktop
mkdir lora_module_1268F30_comm
cd lora_module_1268F30_comm
```

```bash
git clone https://github.com/jgromes/RadioLib.git
cd RadioLib/ 
mkdir build
cd build
cmake ..
make -j4

```
#### creates a main.cpp file 


```bash
cd 
cd Desktop/lora_module_1268F30_comm/
mkdir basicTest
cd basicTest
nano main.cpp
```
Copy and save this script on file:


PIN map 




| LoRa RF1268F30 | Raspberry Pi 5 (GPIO) |
|---|---|
| VCC | 3.3V ou 5V (dependendo do módulo) |
| GND | GND |
| SCK | GPIO11 |
| MISO | GPIO9 |
| MOSI | GPIO10 |
| NSS (CS) | GPIO8 |
| DIO1 | GPIO22 |
| RESET | GPIO27 |
| BUSY | GPIO17 |

```c++
#include <RadioLib.h>
#include <PiHal.h>
#include <iostream>

// Pin map :
// NSS (CS): GPIO 8
// DIO1:     GPIO 22
// RESET:    GPIO 27
// BUSY:     GPIO 17

// Inicialize HAL for  Raspberry Pi using SPI0 bus
PiHal* hal = new PiHal(0);

// Instantiates radio SX1268 
// Module(hal, nss, dio1, rst, busy)
SX1268 radio = new Module(hal, 8, 22, 27, 17);

int main() {
    std::cout << "[SX1268] Starting  basic code..." << std::endl;
    
    // Start the radio f=433MHz 
    int state = radio.begin(433.0);

    if (state == RADIOLIB_ERR_NONE) {
        std::cout << "Sucess! Chip SX1268 based detected " << std::endl;
    } else {
        std::cout << " Error on starting comm. Error code: " << state << std::endl;
        
        // Debug for pins
        if (state == -2) {
            std::cout << "Erro -2: Chip not found. Verify NSS (GPIO8) e SPI (9, 10, 11)." << std::endl;
        } else if (state == -5) {
            std::cout << "Erro -5: Bus Timeout. Verify  BUSY (GPIO17) pin." << std::endl;
        }
        return 1;
    }

    return 0;
}

```

### compile the program

Obs: must be on `basicTest` folder.

```bash
pi@raspberrypi:~/Desktop/lora_module_1268F30_comm/basicTest $ g++ main.cpp -o basicTest -I../RadioLib/src -I../RadioLib/src/hal/RPi -L../RadioLib/build -lRadioLib -llgpio -lpthread
```
as a result a file "basicTest" is created.

## Run the program

```bash
sudo ./basicTest
```
RESULT 1: 

the code works, eventhough there is a error using pin 8 of RPI, with a control conflict between SPI RPI5 bus and RadioLIb via PiHal

```bash

sudo ./basicTest 
[SX1268] Starting basic code...
Could not claim pin 8 for mode 1: GPIO busy
Error writing value to pin 8: GPIO busy
Error writing value to pin 8: GPIO busy
...
Sucess! Chip SX1268 based detected
pi@raspberrypi:~/Desktop/lora_module_1268F30_comm/basicTest $ 
```

Solution: change the NSS to another pin on RPI-5 for instance GPIO 5.



PIN map 


| LoRa RF1268F30 | Raspberry Pi 5 (GPIO) |
|---|---|
| VCC | 3.3V ou 5V (dependendo do módulo) |
| GND | GND |
| SCK | GPIO11 |
| MISO | GPIO9 |
| MOSI | GPIO10 |
| NSS (CS) | GPIO5 |
| DIO1 | GPIO22 |
| RESET | GPIO27 |
| BUSY | GPIO17 |

New main.cpp code saved

```c++
#include <RadioLib.h>
#include <PiHal.h>
#include <iostream>

// Pin map :
// NSS (CS): GPIO 5
// DIO1:     GPIO 22
// RESET:    GPIO 27
// BUSY:     GPIO 17

// Inicialize HAL for  Raspberry Pi using SPI0 bus
PiHal* hal = new PiHal(0);

// Instantiates radio SX1268 
// Module(hal, nss, dio1, rst, busy)
SX1268 radio = new Module(hal, 5, 22, 27, 17);

int main() {
    std::cout << "[SX1268] Starting  basic code..." << std::endl;
    
    // Start the radio f=433MHz 
    int state = radio.begin(433.0);

    if (state == RADIOLIB_ERR_NONE) {
        std::cout << "Sucess! Chip SX1268 based detected " << std::endl;
    } else {
        std::cout << " Error on starting comm. Error code: " << state << std::endl;
        
        // Debug for pins
        if (state == -2) {
            std::cout << "Erro -2: Chip not found. Verify NSS (GPIO8) e SPI (9, 10, 11)." << std::endl;
        } else if (state == -5) {
            std::cout << "Erro -5: Bus Timeout. Verify  BUSY (GPIO17) pin." << std::endl;
        }
        return 1;
    }

    return 0;
}

```
Running the test ...ok 

```bash  
pi@raspberrypi:~/Desktop/lora_module_1268F30_comm/basicTest $ sudo ./basicTest   
[SX1268] Starting  basic code...  
Sucess! Chip SX1268 based detected   
pi@raspberrypi:~/Desktop/lora_module_1268F30_comm/basicTest $ 
```



### Conclusion

This basic test has successfully run. It implements a SPI communication where the RPI5 is the controller and Gnice RF 1268F30 is the  peripheral. The code just identifies that the SPI is ok returning a SX1268 module based chip detect message. This result shows that the pin connections of RPI-5 and NiceRf 1268F30 are ok. It was necessary change the CS (NSS) pin from GPIO8 to GPIO5 on RPI5 due to a library conflict error. 
From this basic test is now possible to advance to specif tests. 