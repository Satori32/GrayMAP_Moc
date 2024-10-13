#include "SurfaceT.h"

template<class T>
SurfaceT<T> ConstructSurfaceT(size_t Width, size_t Height) {
	SurfaceT<T> S;
	S.M = ConstructMemroy<T>(Width * Height);
	S.Width = Width;
	S.Height = Height;

	return S;
}

template<class T>
size_t Width(SurfaceT<T>& In) {
	return In.Width;
}
template<class T>
size_t Height(SurfaceT<T>& In) {
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
	if (ReAllocateMemory(In.M, Width * Height) == false) { return false; }
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
template<class T>
bool Fill(SurfaceT<T>& In, const T& C) {
	for (size_t i = 0; i < Height(In); i++) {
		for (size_t j = 0; j < Width(In); j++) {
			(*Index(In, j, i)) = C;
		}
	}
	return true;
}