#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN = 28;
const int LED_RED = 5;
const int LED_ROXO = 8;
const int LED_AZUL = 11;
const int LED_YELLOW = 15;

int main() {
  stdio_init_all();
  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

  gpio_init(LED_AZUL);
  gpio_set_dir(LED_AZUL, GPIO_OUT);

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  gpio_init(LED_ROXO);
  gpio_set_dir(LED_ROXO, GPIO_OUT);

  gpio_init(LED_YELLOW);
  gpio_set_dir(LED_YELLOW, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if (!gpio_get(BTN)){
      gpio_put(LED_RED,1);
      sleep_ms (300);
      gpio_put(LED_RED,0);
      gpio_put(LED_ROXO,1);
      sleep_ms (300);
      gpio_put(LED_ROXO,0);
      gpio_put(LED_AZUL,1);
      sleep_ms (300);
      gpio_put(LED_AZUL,0);
      gpio_put(LED_YELLOW,1);
      sleep_ms (300);
      gpio_put(LED_YELLOW,0);
    }
  }
}
