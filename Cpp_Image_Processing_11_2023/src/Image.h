#pragma once
#pragma warning(disable : 4996)
#include <cstdint>

// check image type enum.

enum ImageType
{
	PNG,JPG,BMP,TGA

};




// Data Image Structure!!
struct Image {
	// All the Picture data!!
	uint8_t* data = NULL;  // one byte
	size_t size = 0; // size of the data storage
	int w; // Image width
	int h; // Image Height
	int channels; //How namy color value for Pixel Image 
	
	// Contractors
	Image(const char* filename); // File name
	Image(int w, int h, int channels);
	Image( const Image& img); // copy image
	~Image();

	bool read(const char* filename);
	bool write(const char* filename);

	ImageType getFileType(const char* filename);


};