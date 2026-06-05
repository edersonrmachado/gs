# GPIO activation test

This is a basic test to activate a led via GPIO each time a packet is transmitted using LoRa Gnice RF 1268F30.



code 

```c++
```

compile: 


```bash
g++ gpio_activation_test.cpp -o gpio_activation_test -I ~/Desktop/lora_module_1268F30_comm/RadioLib/src -I ~/Desktop/lora_module_1268F30_comm/RadioLib/src/hal/RPi -L ~/Desktop/lora_module_1268F30_comm/RadioLib/build -lRadioLib -llgpio -lpthread
```

run: 
```bash
sudo ./gpio_activation_test
```