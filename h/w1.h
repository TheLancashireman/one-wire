/* w1.h - 1-wire protocol
 *
 * (c) David Haworth
 *
 *  This file is part of tiny-bare-metal.
 *
 *  tiny-bare-metal is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  tiny-bare-metal is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with tiny-bare-metal.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "tinylib.h"

/* Maxim one-wire protocol (e.g. DS18B20)
 *
 * Communication always controlled by controller.
 * Bus is pulled to 0 by communication (open collector).
 * Pull-up of 5K0 (4K7) needed
 *
 * Reset pulse
 * - Controller pulls low for minimum 480 us, then release.
 * - Devices (if present) pull low within 60 us of release for min 60 us, max 240 us
 * - Controller must wait 480 us after release.
 *
 * Write (controller --> device)
 * - Controller pulls low
 * - Device samples line between 15 us and 60 us after falling edge. Therefore:
 * - To write 0, controller holds low for > 60 us (max 120 us)
 * - To write 1, controller releases after 1 us and waits for > 59 us
 *
 * Read (controller <-- device)
 * - Controller pulls low for 1 us
 * - Read 0: device holds low between 15 us and 60 us
 * - Read 1: device doesn't pull low
 * - Controller samples bus max 15 us after falling edge
 * - "Read slots must be min 60 us + 1 us recovery time" (why not stop when line goes high?)
*/

/* Return/status values
*/
#define W1_OK				0
#define W1_RST_NOTPRESENT	1
#define W1_RST_NOTIDLE		2
#define W1_RST_NOTGONE		3

/* Timing - see data sheet
*/
#define W1_TRSTL			480
#define W1_TRSTH			480
#define W1_TPDIH			60
#define W1_TPDLOW			240

static inline void w1_delay(u16_t us)
{
	/* ToDo */
}
