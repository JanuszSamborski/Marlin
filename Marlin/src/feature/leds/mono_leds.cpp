#include "mono_leds.h"
#include "../../MarlinCore.h"

MonoLeds mono_led;

MonoLeds::MonoLeds()
{
    SET_OUTPUT(LED1);
    SET_OUTPUT(LED2);
    SET_OUTPUT(LED3);
    SET_OUTPUT(LED4);
    extDigitalWrite(LED1, LOW);
    extDigitalWrite(LED2, HIGH);
    extDigitalWrite(LED3, HIGH);
    extDigitalWrite(LED4, HIGH);
    led_state.led1=HIGH;
    led_state.led1=LOW;
    led_state.led1=LOW;
    led_state.led1=LOW;
}
    
void MonoLeds::switch_led(uint8_t led_no, bool state)
{
    switch (led_no)
    {
    case 1:
        if (led_state.led1 != state){
            extDigitalWrite(LED1, !state);
            led_state.led1 = state;
            SERIAL_ECHO_MSG("led 1 switched");
        }
        break;
    case 2:
        if (led_state.led2 != state){
            extDigitalWrite(LED2, !state);
            led_state.led2 = state;
            SERIAL_ECHO_MSG("led 2 switched");
        }
        break;
    case 3:
        if (led_state.led3 != state){
            extDigitalWrite(LED3, !state);
            led_state.led3 = state;
            SERIAL_ECHO_MSG("led 3 switched");
        }
        break;
    case 4:
        if (led_state.led4 != state){
            extDigitalWrite(LED4, !state);
            led_state.led4 = state;
            SERIAL_ECHO_MSG("led 4 switched");
        }
        break;
    
    default:
        break;
    }
}