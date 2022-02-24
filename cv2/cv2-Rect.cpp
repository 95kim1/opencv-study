#include <opencv2/core/types.hpp>
#include <iostream>

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