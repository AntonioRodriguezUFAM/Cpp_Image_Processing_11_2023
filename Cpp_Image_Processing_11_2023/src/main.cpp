/*
 - Image Processing with C++: Ep. 1 - Setup
 - Ref: https://www.youtube.com/watch?v=028GNYC32Rg&list=PLG5M8QIx5lkzdGkdYQeeCK__As6sI2tOY

*/

#include "Image.h"

int main(int argc , char** argv) {

	Image test("./Images/apple.jpg");
	test.write("./Images/NewImge.png");

	//Copy Images
	Image copy = test;
	for (int i = 0; i < copy.w * copy.channels; i++) {
		copy.data[i]=0; // to black =0 ,  white=255 color

	}
	copy.write("Images/Copy.png");

	Image blank(100, 100, 3);
	blank.write("Images/blank.jpg");
	return 0;

}