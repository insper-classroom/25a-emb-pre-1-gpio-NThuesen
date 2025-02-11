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
  gpio_set_dir(BTN_Verde, GPIO_IN);
  gpio_pull_up(BTN_Verde);

  gpio_init(BTN_Vermelho);
  gpio_set_dir(BTN_Vermelho, GPIO_IN);
  gpio_pull_up(BTN_Vermelho);

  gpio_init(LED_Verde);
  gpio_set_dir(LED_Verde, GPIO_OUT);

  gpio_init(LED_Vermelho);
  gpio_set_dir(LED_Vermelho, GPIO_OUT); 

  bool Verde_desligado = true;
  bool Vermelho_desligado = true;

  while (true) {

    if (!gpio_get(BTN_Verde)){
      if (Verde_desligado){
        gpio_put(LED_Verde, 1);
        Verde_desligado = false;
        while (!gpio_get(BTN_Verde)) {
        }
      } 
      else if (!Verde_desligado){
        gpio_put(LED_Verde, 0);
        Verde_desligado = true;
        while (!gpio_get(BTN_Verde)) {
        }
      }
    }
    else if (!gpio_get(BTN_Vermelho)){
      if (Vermelho_desligado){
        gpio_put(LED_Vermelho, 1);
        Vermelho_desligado = false;
        while (!gpio_get(BTN_Vermelho)) {
        }
      }
      else if (!Vermelho_desligado){
        gpio_put(LED_Vermelho, 0);
        Vermelho_desligado = true;
        while (!gpio_get(BTN_Vermelho)) {
        }
      }
    }
  }
}
