#include "opencv2/core/types.hpp"
#include <iostream>
#include <vector>

/*
template <typename _Tp>
_Tp x
_Tp y

cv::Point_< _Tp >::Point_	(		)	
cv::Point_< _Tp >::Point_	(	_Tp 	_x, _Tp 	_y )		
cv::Point_< _Tp >::Point_	(	const Point_< _Tp > & 	pt	)	
cv::Point_< _Tp >::Point_	(	const Size_< _Tp > & 	sz	)	
cv::Point_< _Tp >::Point_	(	const Vec< _Tp, 2 > & 	v	)

double cv::Point_< _Tp >::cross	(	const Point_< _Tp > & 	pt	)	const
_Tp cv::Point_< _Tp >::dot	(	const Point_< _Tp > & 	pt	)	const;
bool 	inside (const Rect_< _Tp > &r) const;

pt1 = pt2 + pt3;
pt1 = pt2 - pt3;
pt1 = pt2 * a;
pt1 = a * pt2;
pt1 = pt2 / a;
pt1 += pt2;
pt1 -= pt2;
pt1 *= a;
pt1 /= a;
double value = norm(pt); // L2 norm
pt1 == pt2;
pt1 != pt2;

typedef Point_<int> Point2i;
typedef Point2i Point;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
*/

void print_point(const cv::Point& p, cv::String start="", cv::String end = "\n") {
	std::cout << start << "[" << p.x << ", " << p.y << "]" << end;
}

int main(void) {
	cv::Point2d p;
	cv::Point2f p2;
	cv::Point p3;
	cv::Rect rect;

	p = { 1, 2 };
	print_point(p, "p ");
	
	p2 = cv::Point(3, 4);
	print_point(p2, "p2 ");

	std::cout << p.dot(p2) << " ";
	print_point(p2, "p2 ");

	//std::cout << p.cross(p2).y << std::endl;
	print_point(p2, "p2 ");

	p3 = p2;
	rect = { 1, 2, 5, 6 };

	print_point(p3, "p3 ");
	std::cout << p3.inside(rect) << std::endl;

	//p3 = p + p2; <- error: different types
	p3 = p + p;
	print_point(p, "p(int) ");
	print_point(p3, "p+p ");
	print_point(2 * p + p, "2*p+p ");
	print_point((p+p+p) / 2, "(p+p+p) / 2 ");
	print_point(p + p + p / 2, "p+p+p/2 ");

	return 0;
}

