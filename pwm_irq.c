#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 12  // Pino do servo motor
#define MIN_PULSE_WIDTH 500   // 0 graus (500µs)
#define MID_PULSE_WIDTH 1470  // 90 graus (1470µs)
#define MAX_PULSE_WIDTH 2400  // 180 graus (2400µs)
#define INITIAL_DELAY_MS 5000  // Atraso inicial de 5 segundos
#define INCREMENT 5             // Incremento de 5µs
#define ADJUST_DELAY_MS 10      // Atraso de 10ms
#define WRAP_VALUE 20000        // Para um período de 20ms

void setup_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // Configura o pino como PWM
    uint sliceNum = pwm_gpio_to_slice_num(SERVO_PIN); 

    pwm_config config = pwm_get_default_config();
    
    // Configurar divisor para obter 50Hz (período de 20ms)
    pwm_config_set_clkdiv(&config, 125.f); // Ajustado para 50Hz
    
    pwm_set_wrap(sliceNum, WRAP_VALUE); // Define o wrap para 20ms

    pwm_init(sliceNum, &config, true); // Inicializa o PWM
}

void set_servo_position(uint16_t pulse_width) {
    uint sliceNum = pwm_gpio_to_slice_num(SERVO_PIN);
    
    uint16_t level = (pulse_width * WRAP_VALUE) / 20000; // Ajuste para período de 20ms
    pwm_set_gpio_level(SERVO_PIN, level);
}

void move_servo_smoothly() {
    // Movimentação de 0 a 180 graus
    for (uint16_t pulse_width = MIN_PULSE_WIDTH; pulse_width <= MAX_PULSE_WIDTH; pulse_width += INCREMENT) {
        set_servo_position(pulse_width);
        sleep_ms(ADJUST_DELAY_MS); // Espera 10ms
    }
    
    // Movimentação de 180 a 0 graus
    for (uint16_t pulse_width = MAX_PULSE_WIDTH; pulse_width >= MIN_PULSE_WIDTH; pulse_width -= INCREMENT) {
        set_servo_position(pulse_width);
        sleep_ms(ADJUST_DELAY_MS); // Espera 10ms
    }
}

int main() {
    stdio_init_all();
    setup_pwm();

    // Mover inicialmente para 0, 90 e 180 graus
    set_servo_position(MIN_PULSE_WIDTH); // 0 graus
    sleep_ms(INITIAL_DELAY_MS); // Espera 5 segundos

    set_servo_position(MID_PULSE_WIDTH); // 90 graus
    sleep_ms(INITIAL_DELAY_MS); // Espera 5 segundos

    set_servo_position(MAX_PULSE_WIDTH); // 180 graus
    sleep_ms(INITIAL_DELAY_MS); // Espera 5 segundos

    // Entrar em loop infinito para movimentação suave
    while (true) {
        move_servo_smoothly();
    }

    // Opcional: Desligar o servo motor ao final (nunca será alcançado devido ao loop infinito)
    pwm_set_gpio_level(SERVO_PIN, 0); // Define o nível do PWM como 0

    return 0; // Finaliza o programa (nunca será alcançado)
}