#include "opencv2/core/types.hpp"
#include <iostream>
#include <vector>

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