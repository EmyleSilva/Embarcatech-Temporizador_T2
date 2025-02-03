#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

/**
 * Definição de entradas e saidas conectadas às GPIOs
 */
#define led_g 11
#define led_b 12 
#define led_r 13
#define BUTTON_A 5

/**
 * Definição de tempo de Debounce em ms
 */
#define DEBOUNCE_MS 200

/**
 * Variáveis globais
 */

int counter = 0;
bool leds_active = false;
const uint8_t pins[] = {led_g, led_b, led_r}; 

int leds_states[4][3] = {
    {1, 1, 1},
    {0, 1, 1},
    {0, 0, 1},
    {0, 0, 0}
};
/**
 * Função para inicializar os leds 
 */
void init_leds()
{
    gpio_init(led_r);
    gpio_set_dir(led_r, GPIO_OUT);

    gpio_init(led_g);
    gpio_set_dir(led_g, GPIO_OUT);
    
    gpio_init(led_b);
    gpio_set_dir(led_b, GPIO_OUT);
}

void init_button()
{
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
}

void turn_on_leds()
{
    for (int i = 0; i < 3; i++)
        gpio_put(pins[i], leds_states[counter][i]);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data)
{
    if (counter < 3)
    {
        turn_on_leds();
        counter++;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }else {
        turn_on_leds();
        leds_active = false;
        counter = 0;
    }
}

int main()
{
    stdio_init_all();
    init_leds();
    init_button();

    while (true) {

        if (!gpio_get(BUTTON_A) && leds_active == false)
        {
            sleep_ms(50);

            if (!gpio_get(BUTTON_A))
            {
                turn_on_leds();
                counter++;
                
                leds_active = true;

                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        sleep_ms(10);
    }

    return 0;
}
