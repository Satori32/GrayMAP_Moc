#pragma once

#include <stdio.h>

#include "MemoryAllocator.h"

template<class T>
struct RGBOne {
	T C = 0;
};

struct Gray8 {
	uint8_t C = 0;
};

struct Gray16 {
	uint16_t C = 0;
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

template<class T> SurfaceT<T> ConstructSurfaceT(size_t Width, size_t Height);
template<class T> size_t Width(SurfaceT<T>& In);
template<class T> size_t Height(SurfaceT<T>& In);
template<class T> bool Free(SurfaceT<T>& In);
template<class T> bool Resize(SurfaceT<T>& In, size_t Width, size_t Height);
template<class T> T* Index(SurfaceT<T>& In, size_t X, size_t Y);
template <class T> bool SetPixel(SurfaceT<T>& In, size_t X, size_t Y, const T& P);
template<class T> bool IsNULL(SurfaceT<T>& In);
template<class T> bool Fill(SurfaceT<T>& In, const T& C);