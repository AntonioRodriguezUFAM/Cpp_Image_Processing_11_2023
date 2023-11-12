#pragma warning(disable : 4996)

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION






#include "../Include/stb_image.h"
#include "../Include/stb_image_write.h"

#include <cstdio>
#include <cstdint>
#include "Image.h"

// Contractors
Image::Image(const char* filename){ // File name
	if (read(filename)) {
		printf("Read %s\n",filename);
		size = w * h * channels;
	}
	else {
		printf("Failed to Read %s\n", filename);
	}
}
Image::Image(int w, int h, int channels):w(w),h(h),channels(channels) {
	size = w * h * channels;
	data = new uint8_t[size];

}
Image::Image(const Image& img):Image (img.w, img.h, img.channels) { // copy image
	memcpy(data, img.data, size);
}

Image::~Image(){
	stbi_image_free (data);

}

// Read the Image from File
bool Image::read(const char* filename){
	data = stbi_load(filename, &w, &h, &channels, 0);
	return data != NULL;
	
}
// Write Image to a file
bool Image::write(const char* filename){
	//There are five functions, one for each image file format :

	//int stbi_write_png(char const* filename, int w, int h, int comp, const void* data, int stride_in_bytes);
	//int stbi_write_bmp(char const* filename, int w, int h, int comp, const void* data);
	//int stbi_write_tga(char const* filename, int w, int h, int comp, const void* data);
	//int stbi_write_jpg(char const* filename, int w, int h, int comp, const void* data, int quality);
	//int stbi_write_hdr(char const* filename, int w, int h, int comp, const float* data);

	ImageType Type = getFileType(filename);
	int success;
	switch (Type) {
		case PNG:
			//int stbi_write_png(char const* filename, int w, int h, int comp, const void* data, int stride_in_bytes);
			success = stbi_write_png(filename, w, h, channels,data,w*channels );
			break;
		case BMP:
			//int stbi_write_bmp(char const* filename, int w, int h, int comp, const void* data);
			success = stbi_write_bmp(filename, w, h, channels, data);
			break;
		case JPG:
			//int stbi_write_jpg(char const* filename, int w, int h, int comp, const void* data, int quality);
			success = stbi_write_jpg(filename, w, h, channels, data, 100);
			break;
		case TGA:
			//int stbi_write_tga(char const* filename, int w, int h, int comp, const void* data);
			success = stbi_write_tga(filename, w, h, channels, data);
			break;
	}
	return success != 0;

}

ImageType Image::getFileType(const char* filename) { // Get file Type PNG,JPG,BMP,TGA
	const char* ext = strrchr(filename, '.');
	if (ext != nullptr) {
		if (strcmp(ext, ".png") == 0) {
			return PNG;
		} 
		else if (strcmp(ext, ".jpg") == 0) {
		return JPG;
		}
		else if (strcmp(ext, ".bmp") == 0) {
		return BMP;
		} 
		else if (strcmp(ext, ".tga") == 0) {
		return TGA;
		}
	}
	return PNG;
}