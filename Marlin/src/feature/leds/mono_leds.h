#pragma once
#include "../../inc/MarlinConfigPre.h"

#if ENABLED(MONO_LED)
    typedef struct {
        bool    led1:1,
                led2:1,
                led3:1,
                led4:1
        ;
    } led_states_t;

    class MonoLeds
    {
    private:
        led_states_t led_state;
    public:
        MonoLeds();
        void switch_led(uint8_t led_no, bool state);
    };

    extern MonoLeds mono_led;
#endif