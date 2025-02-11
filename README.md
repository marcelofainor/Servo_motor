# Controle de Servomotor por PWM - Raspberry Pi Pico W

Este projeto implementa o controle de um **servomotor** utilizando o **módulo PWM** do microcontrolador **RP2040** da **Raspberry Pi Pico W**, simulado no ambiente **Wokwi**. O código foi desenvolvido em **C** com o **Pico SDK** e executado no **VS Code**.

## 🛠 Configuração do Projeto

### 🔧 **Requisitos**
- **Hardware Simulado**:
  - **Microcontrolador:** Raspberry Pi Pico W
  - **Servomotor:** Micro servo padrão no Wokwi
  - **LED RGB:** Conectado à GPIO 12

- **Software Utilizado**:
  - **VS Code** com integração ao **Wokwi**
  - **Pico SDK** para desenvolvimento em C
  - **BitDogLab** para experimentos com LED RGB

### 📌 **Objetivo**
O projeto controla o ângulo do servomotor variando o **ciclo de trabalho (Duty Cycle)** do PWM. São configuradas três posições fixas e um movimento suave entre **0° e 180°**.

## 🔄 Funcionamento

1. **Configuração da GPIO 22 para PWM** com frequência de **50Hz (período de 20ms)**.
2. **Movimentação do servomotor**:
   - **180°:** PWM com **2.400µs (0,12% de Duty Cycle)**, mantendo por **5s**.
   - **90°:** PWM com **1.470µs (0,0735% de Duty Cycle)**, mantendo por **5s**.
   - **0°:** PWM com **500µs (0,025% de Duty Cycle)**, mantendo por **5s**.
3. **Rotina de movimentação periódica** entre 0° e 180°:
   - Incrementos de **±5µs** no ciclo ativo.
   - Atraso de **10ms** para suavizar o movimento.
4. **Experimento com LED RGB (GPIO 12)** no BitDogLab.

## 🚀 Como Executar

1. **Clone este repositório**:
   ```sh
   git clone https://github.com/marcelofainor/Servo_motor.git
   cd Servo_motor
