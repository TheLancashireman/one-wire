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
