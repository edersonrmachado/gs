### How to change Network in a RPI5  (already burned)

1. Use a cable connection to access the RPI via ssh


2. To scan available wi-fi 
```bash 
pi@raspberrypi:~ $ nmcli dev wifi list
IN-USE  BSSID              SSID               MODE   CHAN  RATE        SIGNAL  >
        3C:6A:D2:5D:30:E4  AgroBot            Infra  4     270 Mbit/s  100     >
        3E:6A:D2:59:30:E4  --                 Infra  4     270 Mbit/s  100     >
        3C:6A:D2:5D:30:E6  AgroBot            Infra  36    270 Mbit/s  100     >
        3E:6A:D2:6D:30:E6  --                 Infra  36    270 Mbit/s  100
```
3. To access AgroBot wi-fi net:

```bash
pi@raspberrypi:~ $ sudo nmcli dev wifi connect AgroBot password xxxxxx
Device 'wlan0' successfully activated with 'b5a796dd-7c8e-40bf-82e2-101dbc56a1be'.

```

