Projeto Planta Tamagotchi 🌱

Uma plantinha virtual inspirada em Tamagotchi, feita com ESP32 e display TFT IPS ST7735.
O projeto simula emoções e estados da planta através de animações, sensores e interações em tempo real.

Ideia do Projeto

A proposta é transformar uma planta em um pequeno “pet virtual”, onde ela demonstra:

reações ao ambiente
animações e expressões

Tudo exibido em um display TFT controlado por um ESP32.

Inspirado nos clássicos Tamagotchi e em projetos de pets virtuais modernos.

Hardware Utilizado

ESP32
Display TFT IPS ST7735 128x160
Sensor de umidade do solo 
Sensor de luminosidade LDR 
Cabos jumper
Protoboard

Display utilizado:

ST7735
resolução 128x160
comunicação SPI
Ligações utilizadas

TFT     ESP32

VCC  --  	3V3
GND  --  	GND
BLK	 --   3V3
SCL	 --   GPIO 18
SDA	 --   GPIO 23
RST	 --   GPIO 4
DC	 --   GPIO 2
CS	 --   GPIO 15

Bibliotecas

Instale pela Arduino IDE:

Adafruit GFX Library
Adafruit ST7735 and ST7789 Library

Sistema de Animação

As animações são feitas utilizando:

sprites RGB565
múltiplos frames
arrays em PROGMEM

Exemplo:

const uint16_t* frenteallArray[4] = {
  frenteFrente,
  frenteLado_direita,
  frenteLado_esquerda,
  frentePiscando
};

Cada frame possui um delay individual para deixar os movimentos mais naturais.

Funcionalidades Planejadas
 Exibição de sprites fullscreen
 Sistema básico de animação
 Sensor de umidade
 Sensor de luminosidade


Como Executar

Clone o repositório:
git clone https://github.com/luana-pszymus/projeto-planta-tamagotchi.git
Abra o projeto na Arduino IDE
Instale as bibliotecas necessárias
Selecione:
Placa ESP32
Porta COM correta
Faça upload para o ESP32


Observações

As imagens utilizadas no display foram convertidas para RGB565 e armazenadas em PROGMEM para economizar RAM do ESP32.
As imagens convertidas estão na no arquivo imagens.h e são importadas no código -> #include <imagens.h>


Autores

Feito por Luana Pszymus, Ana Basniak, Rafael Correa, Natali Lascoski

Licença

Projeto open-source para fins de estudo e aprendizado.
