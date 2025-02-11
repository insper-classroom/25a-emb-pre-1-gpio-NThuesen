#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26;
const int BTN__PIN_AZUL = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN__PIN_AZUL);
  gpio_set_dir(BTN__PIN_AZUL, GPIO_IN);
  gpio_pull_up(BTN__PIN_AZUL);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN)) {
      }
    }
    else if (!gpio_get(BTN__PIN_AZUL)){
      printf("Botao 2\n");
      while (!gpio_get(BTN__PIN_AZUL)){
      }
    }
  }
}