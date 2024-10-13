#include <stdio.h>

#include "MemoryAllocator.h"

template<class T>
struct RGBOne{
	T C = 0;
};

struct GRay {
	uint8_t C = 0;
};

struct RGB16
{
	union RGBA {
		struct Color
		{
			uint16_t G : 5;
			uint16_t B : 5;
			uint16_t R : 5;
			uint16_t A : 1;
		};
		uint16_t RGBA = 0;
	};
};
struct RGB24
{
	uint8_t B = 0;
	uint8_t G = 0;
	uint8_t R = 0;
};

struct RGB32
{
	uint8_t B = 0;
	uint8_t G = 0;
	uint8_t R = 0;
	uint8_t A = 0;
};

template<class T>
struct  SurfaceT
{
	Memory<T> M;
	size_t Width = 0;
	size_t Height = 0;
	typedef T Type;
};

template<class T>
SurfaceT<T> ConstructSurfaceT(size_t Width, size_t Height) {
	SurfaceT<T> S;
	S.M = ConstructMemroy<T>(Width * Height);
	S.Width = Width;
	S.Height = Height;

	return S;
}

template<class T>
size_t Width(SurfaceT<T>& In){
	return In.Width;
}
template<class T>
size_t Height(SurfaceT<T>& In){
	return In.Height;
}
template<class T>
bool Free(SurfaceT<T>& In) {
	Free(In.M);
	In.Height = 0;
	In.Width = 0;

	return true;
}
template<class T>
bool Resize(SurfaceT<T>& In, size_t Width, size_t Height) {
	if (ReAllocateMemory(In.M, Width*Height) == false) { return false; }
	In.Width = Width;
	In.Height = Height;

	return true;
}
template<class T>
T* Index(SurfaceT<T>& In, size_t X, size_t Y) {
	return Index(In.M, Y * In.Width + X);
}

template <class T>
bool SetPixel(SurfaceT<T>& In, size_t X, size_t Y, const T& P) {
	if (Index(In, X, Y) == NULL) { return false; }
	(*Index(In, X, Y)) = P;

	return true;
}
template<class T>
bool IsNULL(SurfaceT<T>& In) {
	return IsNULL(In.M);
}

int main() {
	SurfaceT<RGB16> S16 = ConstructSurfaceT<RGB16>(16, 16);
	RGB16 C;
	C.RGBA.R = 16;
	SetPixel(S16, 8, 8, C);
}