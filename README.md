# Temporizador de um Disparo (One Shot) - Acionamento de LEDs com Botão

Este projeto implementa um sistema de temporização para o acionamento de LEDs. O sistema é acionado por um botão (pushbutton) e controlado por um temporizador de um disparo, que alterna os estados dos LEDs em intervalos de 3 segundos.

## Descrição do Projeto

O projeto consiste em simular o acionamento de três LEDs (azul, vermelho e verde) a partir do clique em um botão. Quando o botão é pressionado, os três LEDs são ligados simultaneamente. A cada 3 segundos, um LED é desligado. O botão só pode ser acionado novamente após o último LED ser desligado.

### Componentes Utilizados

- **Microcontrolador**: Raspberry Pi Pico W
- **LEDs**: 03 LEDs (azul, vermelho e verde)
- **Resistores**: 03 resistores de 330 Ω
- **Botão**: 01 botão (pushbutton)

### Requisitos do Projeto

1. **Acionamento por Botão**:
   - Ao clicar no botão, os três LEDs são ligados simultaneamente.
   - A cada 3 segundos, um LED é desligado.

2. **Temporização**:
   - O temporizador de alarme deve ser ajustado para um atraso de 3 segundos (3.000 ms) entre cada mudança de estado.

3. **Call-back do Temporizador**:
   - A mudança de estado dos LEDs deve ser implementada em funções de call-back do temporizador (`turn_off_callback()`).

4. **Bloqueio de Acionamento**:
   - O botão só pode alterar o estado dos LEDs quando o último LED for desligado. Durante a execução das rotinas de temporização, o botão não pode iniciar uma nova chamada da função call-back.

5. **Experimento com LED RGB e Botão A**:
   - Utilizar a ferramenta BitDogLab para experimentar com o LED RGB (GPIOs 11, 12 e 13) e o Botão A (GPIO 05).

6. **Opcional**:
   - Implementar uma rotina em software para atenuação do efeito bouncing no botão (software debounce).

## Como Compilar e Executar

1. **Pré-requisitos**:
   - Ter o ambiente de desenvolvimento para o Raspberry Pi Pico configurado (compilador, SDK, etc.).
   - CMake instalado.

2. **Compilação**:
   - Clone o repositório ou baixe os arquivos do projeto.
   - Navegue até a pasta do projeto e crie uma pasta de build:
     ```bash
     mkdir build
     cd build
     ```
   - Execute o CMake para configurar o projeto:
     ```bash
     cmake ..
     ```
   - Compile o projeto:
     ```bash
     make
     ```

3. **Upload para a placa**:
   - Conecte o Raspberry Pi Pico ao computador.
   - Copie o arquivo `.uf2` gerado para a placa.

## Simulação no Wokwi
Para visualizar a simulação do projeto no Wokwi:
1. Instale e configure o simulador wokwi seguindo as instruções encontradas no link:
[Introdução ao Wokwi para VS Code](https://docs.wokwi.com/pt-BR/vscode/getting-started)
2. Abra o arquivo diagram.json no vsCode.
3. Clique em "start simulation". 