#include "opencv2/core/types.hpp"
#include <iostream>
#include <vector>
/*
template <typename _Tp>
_Tp height
_Tp width

Size_ ()
Size_ (_Tp _width, _Tp _height)
Size_ (const Size_ &sz)=default
Size_ (Size_ &&sz) CV_NOEXCEPT=default
Size_ (const Point_< _Tp > &pt)
 
_Tp 	area () const
double 	aspectRatio () const //width/height.
bool 	empty () const

template <typename _Tp2 >
operator Size_< _Tp2 > () const //conversion of another data type.

Size_ & 	operator= (const Size_ &sz)=default
Size_ & 	operator= (Size_ &&sz) CV_NOEXCEPT=default

typedef Size_<int> Size2i;
typedef Size2i Size;
typedef Size_<float> Size2f;
*/

void print_size(const cv::Size& size, cv::String start = "", cv::String end = "\n") {
	std::cout << start << "[" << size.width << " / " << size.height << " = " << size.aspectRatio() << "]" << end;
	std::cout << start << "[" << size.width<< " * " << size.height << " = " << size.area() << "]" << end;
}
void print_size(const cv::Size2f& size, cv::String start = "", cv::String end = "\n") {
	std::cout << start << "[" << size.width << " / " << size.height << " = " << size.aspectRatio() << "]" << end;
	std::cout << start << "[" << size.width << " * " << size.height << " = " << size.area() << "]" << end;
}
void print_size(const cv::Size2d& size, cv::String start = "", cv::String end = "\n") {
	std::cout << start << "[" << size.width << " / " << size.height << " = " << size.aspectRatio() << "]" << end;
	std::cout << start << "[" << size.width << " * " << size.height << " = " << size.area() << "]" << end;
}

int main(void) {
	cv::Size size;
	cv::Size2f size2;
	cv::Size2d size3;

	size = { 3, 5 };
	print_size(size, "size ");

	size2 = cv::Size2d(3.3, 4.21);
	print_size(size2, "size2 ");

	size3 = size2;
	print_size(size3, "size3 ");

	return 0;
}