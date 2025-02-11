#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_Vermelho = 28;
const int BTN_Verde = 26;
const int LED_Vermelho = 4;
const int LED_Verde = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_Verde);

  while (true) {
  }
}
