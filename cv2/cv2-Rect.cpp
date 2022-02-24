#include <opencv2/core/types.hpp>
#include <iostream>

/*
template <typename _Tp>
_Tp 	height
_Tp 	width
_Tp 	x
_Tp 	y

Rect_ ()
Rect_ (_Tp _x, _Tp _y, _Tp _width, _Tp _height)
Rect_ (const Rect_ &r)=default
Rect_ (Rect_ &&r) CV_NOEXCEPT=default
Rect_ (const Point_< _Tp > &org, const Size_< _Tp > &sz)
Rect_ (const Point_< _Tp > &pt1, const Point_< _Tp > &pt2)

_Tp 	area () const
Point_< _Tp > 	br () const //bottom-right
bool 	contains (const Point_< _Tp > &pt) const
// x ≤ pt.x < x + width,  y ≤ pt.y < y + height 
bool 	empty () const

template <typename _Tp2 >
operator Rect_< _Tp2 > () const	//conversion to another data type

Rect_ & 	operator= (const Rect_ &r)=default
Rect_ & 	operator= (Rect_ &&r) CV_NOEXCEPT=default

Size_< _Tp > 	size () const //Size(wight, height)
Point_< _Tp > 	tl () const //top-left

Virtually every loop over an image ROI in OpenCV (where ROI is specified by Rect_<int> ) is implemented as:

for(int y = roi.y; y < roi.y + roi.height; y++) {
    for(int x = roi.x; x < roi.x + roi.width; x++)
    {
        // ...
    }
}

implement like these...
rect=rect ± point (shifting a rectangle by a certain offset)
rect=rect ± size (expanding or shrinking a rectangle by a certain amount)
rect += point, rect -= point, rect += size, rect -= size (augmenting operations)
rect = rect1 & rect2 (rectangle intersection)
rect = rect1 | rect2 (minimum area rectangle containing rect1 and rect2 )
rect &= rect1, rect |= rect1 (and the corresponding augmenting operations)
rect == rect1, rect != rect1 (rectangle comparison)

This is an example how the partial ordering on rectangles can be established (rect1 ⊆ rect2):

template<typename _Tp> inline bool
operator <= (const Rect_<_Tp>& r1, const Rect_<_Tp>& r2)
{
    return (r1 & r2) == r1;
}

*/

template <typename RECT>
void print_rect(RECT rect, cv::String start = "------", cv::String end = "\n") {
	std::cout << "------" << start << "-------" << std::endl;
	std::cout << "x     : " << rect.x << std::endl;
	std::cout << "y     : " << rect.y << std::endl;
	std::cout << "width : " << rect.width << std::endl;
	std::cout << "hegith: " << rect.height << std::endl;
	std::cout << "area  : " << rect.area() << std::endl;
	std::cout << "==================" << end;
}

int main(void) {
	cv::Rect rect;
	cv::Rect2f rect2;
	cv::Rect2d rect3;

	rect = { 1, 2, 3, 4 };
	rect2 = { 1.0, 2.5, 3.0, 4.5 };
	rect3 = { 0.5, 2.25, 5.5, 6.5 };
	print_rect(rect, "rect");
	print_rect(rect2, "rect2");
	print_rect(rect3, "rect3");

	rect3 = rect2;
	print_rect(rect3, "rect3");

	cv::Rect rect1 = rect + cv::Point(1, 1) - cv::Size(1, 2);
	print_rect(rect, "rect");
	print_rect(rect1, "rect + Point(1,1) - Size(1,2)");
	print_rect(rect1 & rect, "rect1 & rect");


	return 0;
}