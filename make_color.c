#include <stdio.h>
#include <stdint.h>

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b) 
{
	const uint8_t a = 255;
	return (r<<24) + (g<<16) + (b<<8) + a;
}



int main() 
{
	const size_t win_w = 512;
	const size_t win_h = 512;

	uint32_t framebuffer[ win_w * win_h ];

	for (size_t j = 0; j < win_h; j++) {
		for (size_t i = 0; i < win_w; i++) {
			uint8_t r = 255 * 512 / win_h;
			uint8_t g = 255 * 512 / win_w;
			uint8_t b = 0;
			framebuffer[ i + j * win_w ] = pack_color(r, g, b);
		}
	}

	printf("%d\n", framebuffer[0]);

	return 0;

}