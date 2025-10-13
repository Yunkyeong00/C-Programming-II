#include <stdio.h>

void UnionRGB();


typedef union color_t
{
	unsigned int color;
	unsigned char rgb[4];
}COLOR_T;

int main(void)
{
	UnionRGB();

	return 0;

}

void UnionRGB()
{
	COLOR_T c1;

	c1.rgb[0] = 0xFF;
	c1.rgb[1] = 0xAB;
	c1.rgb[2] = 0x1F;
	c1.rgb[3] = 0x0;

	printf("rgb color = %08X\n", c1.color);
}