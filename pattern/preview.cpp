#include "Stripes.h"

#include "Pattern.h"
#include "CImg.h"
using namespace cimg_library;

static const int pix_per_led = 1;
static const int slices = 1000;

int main() {
	Stripes gen;
	CHSV frame_hsv[Pattern::num_leds];
	CRGB frame_rgb[Pattern::num_leds];
	CImg<unsigned char> img(slices, Pattern::num_leds * pix_per_led, 1, 3, 0);
	for (int x = 0; x < slices; ++x) {
		gen.updateFrame(frame_hsv);
		for (int i = 0; i < Pattern::num_leds; ++i) {
			frame_rgb[i] = frame_hsv[i];
		}
		for (int y = 0; y < Pattern::num_leds; ++y) {
			for (int c = 0; c < 3; ++c) {
				img.atXY(x, y, 0, c) = frame_rgb[y][c];
			}
		}
	}
	img.display("Pattern Preview");
	return 0;
}
