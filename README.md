# Controle de Servomotor por PWM - Raspberry Pi Pico W

Este projeto implementa o controle de um **servomotor** utilizando o **módulo PWM** do microcontrolador **RP2040** da **Raspberry Pi Pico W**, simulado no ambiente **Wokwi**. O código foi desenvolvido em **C** com o **Pico SDK** e executado no **VS Code**.

# Comportamento do LED

Controle de Intensidade:
O PWM (modulação por largura de pulso) pode ser usado para controlar a intensidade do LED. O valor que você define em pwm_set_gpio_level(SERVO_PIN, level) controlará a quantidade de tempo que o LED fica aceso em um ciclo de PWM.
Um valor mais baixo resultará em uma menor intensidade (mais escuro), enquanto um valor mais alto resultará em uma maior intensidade (mais brilhante).

# Ciclos de Luz:

Ao invés de mover o servo motor entre os ângulos de 0°, 90° e 180°, você verá o LED acender em diferentes intensidades baseadas nas posições que o código define (500 µs, 1470 µs e 2400 µs) ao longo do tempo.

# Exemplos de Comportamento

LED em 0 graus (500 µs): O LED pode estar muito fraco ou quase apagado.

LED em 90 graus (1470 µs): O LED acenderá a uma intensidade média.

LED em 180 graus (2400 µs): O LED ficará bastante brilhante.

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

2. Configure o Pico SDK conforme documentação oficial.

3. Compile e rode o código no Wokwi via VS Code.

## 🎥 Demonstração

Confira o vídeo explicativo do projeto: 🔗 Link para o vídeo : https://youtu.be/JaKKEU1qM-k?si=Z6dhIb1Xo_J0lo78

📜 Créditos
Desenvolvido por Marcelo Barbosa de Almeida, com base nas diretrizes da disciplina Unidade 4 | Capítulo 7 – C7O123E ministrada pelo Prof. Dr. Ricardo Menezes Prates.
