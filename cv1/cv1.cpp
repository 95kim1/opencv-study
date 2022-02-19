#include "opencv2/opencv.hpp"
#include <iostream>
#include <array>
#include <vector>

int main()
{
	std::cout << "Hello, OpenCV" << CV_VERSION << std::endl;

	cv::Mat img;
	img = cv::imread("lenna.bmp", cv::IMREAD_UNCHANGED);
	/* 이미지 불러오기 - imread
	Mat imread(const String& filename, int flags=IMREAD_COLOR);
	// flags: option, ImreadModes 열거형 상수

	// BMP, JPG, TIF, PNG 등 널리 쓰이는 것 대부분 지원
	// flags 옵션 표
	// 1. IMREAD_UNCHANGED			: 입력 파일에 지정된 그대로 사용.
		투명한 PNG 또는 TIFF 파일의 경우 알파 채널까지 이용 (총 4채널)
	// 2. IMREAD_GRAYSCALE			: 1채널 그레이스케일 영상으로 변환
	// 3. IMREAD_COLOR				: 3채널 BGR 컬러 영상으로 변환
	// 4. IMREAD_REDUCED_GRAYSCALE_2: 크기 1/2로 줄인 1채널 그레이스케일 영상으로 변환
	// 5. IMREAD_REDUCED_COLOR_2	: 크기 1/2로 줄인 3채널 BGR 컬러 영상으로 변환
	// 6. IMREAD_IGNORE_ORIENTATION	: EXIF에 저장된 방향 정보를 사용하지 않는다.
	*/


	/* 이미지 저장하기 - imwrite
	bool imwrite(const String& filename, InputArray img,
				 const std::vector<int>& params=std::vector<int>());
	// params: 이미지 객체를 파일로 저장할 때 참고할 옵션과 value
				(paramId_1, paramVal_1, pramId_2, paramVal_2, ... )
				예를들어, jpg 압축률을 95%로 하고 싶다면...
				params.push_back(IMWRITE_JPEG_QUALITY);
				params.push_back(95);
				라고 하면 된다.
	*/


	if (img.empty()) {
		// img의 행렬의 row or col이 0이거나 멤버변수(이미지)가 NULL 이면 true
		std::cerr << "Image load failed!" << std::endl;
		return -1;
	}


	cv::namedWindow("image");
	// 영상을 띄울 창 생성 및 이름 부여.
	/*
	void namedWindow(const String& winname, int flags=WINDOW_AUTOSIZE);
	// winname	: 고유 이름. (문자열로 창을 구분한다.)
	// flags	: 창의 속성 지정. WindowFlags 열거형 상수
	
	// flag 옵션 표
	// 1. WINDOW_NORMAL		: 창의 크기에 영상을 맞춤. (사용자가 창 크기 변경 가능)
	// 2. WINDOW_AUTOSIZE	: 영상 크기에 창을 맞춤
	// 3. WINDOW_OPENGL		: OpenGL을 지원
	*/


	/*
	void destoryWindow(const String& winname);
	void destroyAllWindow();

	void moveWindow(const String& winname, int x, int y);
	void resizeWindow(const String& winname, int width, int height);
	*/
	cv::moveWindow("image", 1400, 0);

	cv::imshow("image", img);
	// image 이름을 가진 창에 img객체의 영상을 출력.
	// 해당 이름의 창이 없으면 새로 만드는 거 같다.

	cv::waitKey(); // 키보드 입력 대기

	return 0;
}