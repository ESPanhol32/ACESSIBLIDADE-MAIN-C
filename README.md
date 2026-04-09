Sistema de Semáforo com Buzzer (ESP32)
=====================================

Descrição
---------
Este projeto apresenta a parte de acessibilidade para o semáforo utilizando o ESP32.
O sistema alterna entre os estados verde, amarelo e vermelho, com sinais sonoros diferentes.

Funcionalidades
---------------
- Controle de 3 LEDs:
  - Verde
  - Amarelo
  - Vermelho
- Emissão de som com buzzer:
  - Som lento no verde
  - Som rápido no amarelo
  - Sem som no vermelho
- Uso de temporização com FreeRTOS

Hardware Necessário
------------------
- ESP32
- 3 LEDs (verde, amarelo, vermelho)
- 3 resistores (220 ohms recomendados)
- 1 buzzer
- Jumpers e protoboard

Pinagem
-------
Buzzer       -> GPIO 18
LED Verde    -> GPIO 32
LED Amarelo  -> GPIO 33
LED Vermelho -> GPIO 25

Funcionamento
-------------
Modo Verde:
- LED verde ligado
- Buzzer liga/desliga a cada 500 ms
- Duração aproximada: 5 segundos

Modo Amarelo:
- LED amarelo ligado
- Buzzer liga/desliga a cada 200 ms
- Duração aproximada: 5 segundos

Modo Vermelho:
- LED vermelho ligado
- Buzzer desligado
- Duração: 5 segundos

Estrutura do Código
-------------------
- setup_gpio(int pin): configura o pino como saída
- app_main(): controla o ciclo do semáforo

Como Executar
-------------
1. Configurar o ambiente ESP-IDF
2. Conectar o ESP32 ao computador
3. Compilar o projeto:
   idf.py build
4. Gravar na placa:
   idf.py flash
5. Monitorar (opcional):
   idf.py monitor

Autor
-----
Lucas Espanhol
