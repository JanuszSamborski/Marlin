/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(SDSUPPORT)

#include "../gcode.h"
#include "../../sd/cardreader.h"
#include "../../lcd/marlinui.h"
#include "../../feature/leds/mono_leds.h"

/**
 * M23: Handle start button
 *
 * Opens and starts 
 */
void GcodeSuite::M35() {
    if (!card.isFileOpen()){
        uint16_t file_num = card.get_num_Files();
        card.selectFileByIndex(file_num - 1);
        SERIAL_ECHO_MSG("File selected: ", card.filename);
        card.openFileRead(card.filename);
        mono_led.switch_led(1, LOW);
        mono_led.switch_led(2, LOW);
        mono_led.switch_led(3, LOW);
        mono_led.switch_led(4, LOW);
        card.startOrResumeFilePrinting();
        SERIAL_ECHO_MSG("Starting file print...");
    } else if (card.isPrinting()) {
        if (card.isPaused()){
            card.startOrResumeFilePrinting();
            SERIAL_ECHO_MSG("Printing paused");
        } else {
            card.pauseSDPrint();
            SERIAL_ECHO_MSG("Printing resumed");
        }
    } else {
        card.startOrResumeFilePrinting();
        SERIAL_ECHO_MSG("Starting file print...");
    }
}

#endif // SDSUPPORT
