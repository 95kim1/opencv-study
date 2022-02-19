#include "opencv2/opencv.hpp"
#include <iostream>
#include <array>
#include <vector>

int main()
{
	std::cout << "Hello, OpenCV" << CV_VERSION << std::endl;

	cv::Mat img;
	img = cv::imread("lenna.bmp", cv::IMREAD_UNCHANGED);
	/* �̹��� �ҷ����� - imread
	Mat imread(const String& filename, int flags=IMREAD_COLOR);
	// flags: option, ImreadModes ������ ���

	// BMP, JPG, TIF, PNG �� �θ� ���̴� �� ��κ� ����
	// flags �ɼ� ǥ
	// 1. IMREAD_UNCHANGED			: �Է� ���Ͽ� ������ �״�� ���.
		������ PNG �Ǵ� TIFF ������ ��� ���� ä�α��� �̿� (�� 4ä��)
	// 2. IMREAD_GRAYSCALE			: 1ä�� �׷��̽����� �������� ��ȯ
	// 3. IMREAD_COLOR				: 3ä�� BGR �÷� �������� ��ȯ
	// 4. IMREAD_REDUCED_GRAYSCALE_2: ũ�� 1/2�� ���� 1ä�� �׷��̽����� �������� ��ȯ
	// 5. IMREAD_REDUCED_COLOR_2	: ũ�� 1/2�� ���� 3ä�� BGR �÷� �������� ��ȯ
	// 6. IMREAD_IGNORE_ORIENTATION	: EXIF�� ����� ���� ������ ������� �ʴ´�.
	*/


	/* �̹��� �����ϱ� - imwrite
	bool imwrite(const String& filename, InputArray img,
				 const std::vector<int>& params=std::vector<int>());
	// params: �̹��� ��ü�� ���Ϸ� ������ �� ������ �ɼǰ� value
				(paramId_1, paramVal_1, pramId_2, paramVal_2, ... )
				�������, jpg ������� 95%�� �ϰ� �ʹٸ�...
				params.push_back(IMWRITE_JPEG_QUALITY);
				params.push_back(95);
				��� �ϸ� �ȴ�.
	*/


	if (img.empty()) {
		// img�� ����� row or col�� 0�̰ų� �������(�̹���)�� NULL �̸� true
		std::cerr << "Image load failed!" << std::endl;
		return -1;
	}


	cv::namedWindow("image");
	// ������ ��� â ���� �� �̸� �ο�.
	/*
	void namedWindow(const String& winname, int flags=WINDOW_AUTOSIZE);
	// winname	: ���� �̸�. (���ڿ��� â�� �����Ѵ�.)
	// flags	: â�� �Ӽ� ����. WindowFlags ������ ���
	
	// flag �ɼ� ǥ
	// 1. WINDOW_NORMAL		: â�� ũ�⿡ ������ ����. (����ڰ� â ũ�� ���� ����)
	// 2. WINDOW_AUTOSIZE	: ���� ũ�⿡ â�� ����
	// 3. WINDOW_OPENGL		: OpenGL�� ����
	*/


	/*
	void destoryWindow(const String& winname);
	void destroyAllWindow();

	void moveWindow(const String& winname, int x, int y);
	void resizeWindow(const String& winname, int width, int height);
	*/
	cv::moveWindow("image", 1400, 0);

	cv::imshow("image", img);
	// image �̸��� ���� â�� img��ü�� ������ ���.
	// �ش� �̸��� â�� ������ ���� ����� �� ����.

	cv::waitKey(); // Ű���� �Է� ���

	return 0;
}