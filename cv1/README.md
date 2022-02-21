# 기본 함수

---

**기본적으로 opencv의 namespace는 cv다.**

### 목차

1. [cv::imread](#imread)
2. [cv::imwrite](#imwrite)
3. [Mat::empty](#empty-in-Mat)
4. [cv::nameWindow](#nameWindow)
5. [cv::destroy[All]Window](#destoryWindow)
6. [cv::move/resizeWindow](#move/resizeWindow)
7. [cv::imshow](#imshow)

---

## imread
### Mat imread(const String& name, int flags=IMREAD_COLOR);

flag: 옵션 / ImreadModes 열거형 상수

| option | description |
| --- | --- |
| IMREAD_UNCHANGED | 입력 파일에 저장된 그대로 사용.<br>(PNG 투명, TIFF 파일 ⇒ 알파 채널 사용 ⇒ 4채널) |
| IMREAD_GRAYSCALE | 1채널 그레이스케일 영상으로 변환 |
| IMREAD_COLOR | 3채널 BGR 컬러 영상으로 변환 |
| IMREAD_ANYDEPTH | depth에 따라 정밀도를 16/32비트 영상으로 변환
(depth가 없으면 8비트로) |
| IMREAD_ANYCOLOR | 가능한 color 포맷으로 read |
| IMREAD_LOAD_GDAL | GDAL 드라이버를 활용하여 이미지 read
(GDAL: 지도관련 이미지 처리) |
| IMREAD_REDUCED_GRAYSCALE_n | 크기 1/n로 줄인 1채널 그레이스케일 영상으로 변환
(n = 2, 4, 8) |
| IMREAD_REDUCED_COLOR_n | 크기 1/n로 줄인 3채널 BGR 컬러 영상으로 변환
(n = 2, 4, 8) |
| IMREAD_IGNORE_ORIENTATION | EXIF에 저장된 방향 정보를 사용하지 않는다. |

EXIF: 이미지 파일 안에 저장되어 잇는 파일 형식.

## imwrite
### bool imwrite(const String& name, InputArray img, const std::vector<int>& params=std::vector<int>());

params: 이미지 객체를 파일로 저장할 때 활용할 (옵션, value)쌍

(option1, value1, option2, value2, ...., value_i, option_i, ...)

## empty in Mat
**bool Mat::empty()**

## nameWindow
### void nameWindow(const String& name, int flags=WINDOW_AUTOSIZE);

- name : 창 고유 id
- flags : 창의 속성 (WindowFlags 열거형 상수)

| option | description|
| --- | --- |
| WINDOW_NORMAL | 창 크기에 영상 맞춤. |
| WINDOW_AUTOSIZE | 영상 크기에 창을 맞춤. |
| WINDOW_OPENGL | OpenGL 지원 |

## destoryWindow
**void destroyWindow(const String& name);**  
**void destroyAllWindow();**

## move/resizeWindow
**void moveWindow(const String& name, int x, int y);**  
**void resizeWindow(const Stirng& name, int w, int h);**

## imshow
### void imshow(const String& name, InputArray mat);

- image의 원소가 8bit면 그대로 출력
- 16bit면 255로 나누어서 출력 ([0, 255*255] → [0, 255])
- floating point면 255를 곱해서 출력 ([0, 1] → [0, 255])
