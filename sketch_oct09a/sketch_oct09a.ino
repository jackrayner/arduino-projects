/*
 *
 * An IR LED must be connected to Arduino PWM pin 3 (IR_SEND_PIN).
 * To receive IR signals in compatible format, you must comment out the line
 * #define USE_NEC_STANDARD in IRremote.h.
 */
/*
 * IRremote: IRsendNecStandardDemo
 *
 *  Demonstrates sending NEC IR codes in standard format with 16 bit Address  8bit Data
 *
 *  Created on: 15.09.2020
 *  Copyright (C) 2020  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *  This file is part of Arduino-RobotCar https://github.com/z3t0/Arduino-IRremote.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/gpl.html>.
 */

#include <IRremote.h>

IRsend IrSender;

// On the Zero and others we switch explicitly to SerialUSB
#if defined(ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

int sw = 2;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(sw, INPUT);

    Serial.begin(9600);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)
    delay(2000); // To be able to connect Serial monitor after reset and before first printout
#endif
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__));
    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}

uint16_t sAddress = 0xa90;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void loop() {

  

    IrSender.sendNECStandard(sAddress, sCommand, sRepeats);
    /*
     * Print values
     */
    Serial.print(F("Send NEC standard: address=0x"));
    Serial.print(sAddress, HEX);
    Serial.print(F(" command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(" repeats="));
    Serial.print(sRepeats);
    Serial.println();
    /*
     * Increment values
     */
    sAddress++;
    sCommand++;
    sRepeats++;
    if (sRepeats > 5) {
        sRepeats = 5;
    }

    delay(2000); // 2 second delay between each signal
}
