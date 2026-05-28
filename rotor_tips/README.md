# Objetivo 

Implementar a comunicação entre RPI-5 e Rotor YAESU G5500 para o seguimento de satélites LEO.

- Utilizar a ferramenta (software) GPredict (possui uma saída para o controlador do rotor)
- O rotor completo  é composto por um rotor e controlador manual e um controlador digital. O controlador digital é conectado a uma porta do PC. O software Gpredict prediz quando o satelite vai passar, por exemplo entre 10h e 10h10.  Quando o satélite está passando envia comandos (azimuth e elevation) para mover o rotor. Ex.
  - 10h01s: azimuth=150, elevation=10
  - 10h05s: azimuth=153, elevation=13
  - 10h10s: azimuth=156, elevation=17
  - 10h15s: azimuth=159, elevation=25
...
# Atividades

- 1. Instalar ferramenta de seguimento de satélites [Gpredict](https://oz9aec.dk/gpredict/) num pc (linux)
    - montar rotor em uma bancada
    - verificar conexões rotor, se existe necessidade de compra de cabos etc
    - fazer teste basico de funcionamento com controlador manual
- 2. Pegar o TLE de um satélite LEO tiny GS [Norbi](https://tinygs.com/satellite/Norbi), carregar no Gpredict, fazer a predição da passagem do satélite.
  - Exemplo TLE Norbi:
``` 
  NORBI
        1 46494U 20068J   26148.31233646  .00027351  00000-0  53298-3 0  9990
        2 46494  97.8631 162.5392 0005430 347.4429  12.6683 15.47503216313137
```

- 3. Instalar ferramenta de seguimento de satélites [Orbitron](https://www.stoff.pl/)     
- 4. Instalar Gpredict no RPI5
  - gravar uma imagem de preferencia ubuntu (pois tbm usaremos outros softwares que necessitam ubuntu)
- 5. Verificar script python que faz a predição   

## background necessário

- Estudar o que é e como funciona o TLE
- https://www.youtube.com/watch?v=2gAYqtmNJx8 
- https://www.youtube.com/watch?v=MOABTyL1Cn8
  

