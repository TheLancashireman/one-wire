/* conversion.c - test program for the DS18B20 conversion function
 *
 * (c) David Haworth
 *
 *  This file is part of one-wire.
 *
 *  one-wire is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  one-wire is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with one-wire.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>

#define NCONV 10

/* Values from ds18b20 data sheet
*/
short vals[NCONV] =
{
	0x07D0,
	0x0550,
	0x0191,
	0x00A2,
	0x0008,
	0x0000,
	0xFFF8,
	0xFF5E,
	0xFE6F,
	0xFC90,
};


int main(int argc, char **argv)
{
	int i;
	float temp1, temp2;
	for ( i = 0; i < NCONV; i++ )
	{
		temp1 = (float)vals[i];
		temp2 = temp1 / 16.0;

		printf("%d  %d   %f   %f\n", i, vals[i], temp1, temp2);
	}

	return 0;
}
