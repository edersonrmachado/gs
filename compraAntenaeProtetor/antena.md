# Compra de antena

# Requisitos

- 1.Frequência LoRa: UHF 430 - 440 MHz  
- 2.Polarização RHCP: linear ou circular (preferência circ)
- 3.VSWR < 2
- 4.YAGI >= 9 elementos (devido ao maior ganho)
- 5.Potência >= 5 W 
- 6.Impedância: 50 ohms

## Justificativas:

- 1.**Frequencia** UHF 430 - 440MHz: escolhe-se essa faixa devido a disponibilidade de satélites LoRa para testes, por exemplo FOSSA-SATs, Norbi, Guarani SAT, etc. Devido aos poucos satélites que utilizam a banda LoRa BR  (~928MHz) e a dificuldade de disponibiliza-los para testes, incialmente escolhe-se esta faixa.  
- 2.**Polarização RHCP**: a polarização é escolhida a polarização preferencial circular devido à mesma ser menos sensível à orientação que a linear. Neste caso se o satélite possui uma antena linear tem-se 3dB de perda, maior complexidade (custo também), porém como os satélites LEO mudam de orientação constantemente, essa opção é escolhida. Right hand circular polarization RHCP é a mais comum escolha de polarização circular. 
- 3.**VSWR** <2. O VSWR mede o casamento da impedância da antena, resultando na energia transmitida e refletida da mesma. VSWR = 2 resulta em ~11% da energia refletida e 89% transmitida. Deve-se ter o cuidado da energia refletida não incindir em algum componente que possa sofrer dano devido ao seu valor.  
  
- 4.**YAGI >=10 elementos** A antena YAGI-UDA apresenta alta direcionalidade e alto ganho quando comparada a outras antenas. A alta directividade aumenta seu alcance, o que a torna elegível para o rastreamento de satélites. É necessario um sistema de rastreamento calibrado. O ganho geralmente entre 7 a 13dBi. Outras vantagens incluem a relação peso/ganho, mais leve que outras antenas com mesmo desempenho e a redução de interferência fora da direção desejada, incluindo a absorção de ruídos indesejados em outras direções. A relação frente-costas (front-to-back Ratio F/B) é menor por ser direcional. F/B de 20dB por exemplo indica que se uma antena irradia 100W para frente irradia 1W para trás. A partir de 10 elementos os ganhos adicionais por elemento diminuem bastante (verificar no livro da Balanis)

$$ F/B = 10 \ log_{10} \left ( \frac{P_{frente}}{P_{costas}}\right) $$



- 5.**Potência >5W**  A potência máxima que vamos utilizar não passa de 1.5 W, porém para ter uma margem de ganho de potencia escolhe-se 5 W como valor base(as YAGIs com 9 ou mais elementos normalmente toleram potencias maiores que 5 W)  
- **6.Impedância 50 ohms**. A estação é projetada para a impedância de linha de 50 ohms, assim a impedância da antena também possui esse valor padrão.  

 
- **8. Peso da antena**. O peso da antena é importante para não haver sobrecarga e evitar desgaste rotor. O valor máximo suportado pelo rotor é de 200kg vertocal. Porém, considerando possíveis implantações da GS com mais de uma antena, quanto menor o peso da mesma melhor.   

## Fabricantes
1. https://www.c3potecnologia.com.br/  ok
2. https://www.iftelecom.com.br/  nao tem 433MHz somente 470 pra cima
3. https://idealantenas.com.br/   datasheets das antenas https://drive.google.com/file/d/1QoH5j6rzupdMNQitgYFmrR7_JrMOkLIz/view ok  
4. https://www.algcom.com.br/produtos?seg=1    nao tem faixa 430MHz
5. https://hankell.com.br/contato/ pedido de cotação
6. https://arseletronica.com.br pedido se fazem 430 -440 MHz (406 -430MHz)
7. https://www.tsmantenas.com.br (415-450MHz) 


## Fatores avaliados


adfasdfasdfasdf 