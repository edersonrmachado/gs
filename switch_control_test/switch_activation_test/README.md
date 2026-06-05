# SWitch activation test

This is a basic test to activate RF1 and RF2 switch channels  via GPIO.

Loop: 
Step 1: activate RF2 and send data to RTL2 
Step 2: wait 3 s
Step 3: activate RF1 and send data to RTL1 
Step 2: wait 3 s
 
 
each time a packet is transmitted using LoRa Gnice RF 1268F30.



code 

```c++
```

compile: 


```bash
g++ switch_activation_test.cpp -o switch_activation_test -I ~/Desktop/lora_module_1268F30_comm/RadioLib/src -I ~/Desktop/lora_module_1268F30_comm/RadioLib/src/hal/RPi -L ~/Desktop/lora_module_1268F30_comm/RadioLib/build -lRadioLib -llgpio -lpthread
```

run: 
```bash
sudo ./gpio_activation_test
```