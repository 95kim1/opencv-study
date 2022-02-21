# opencv-study
to study opencv
---
## 환경
- Windows10
- Visual Studio 2022
- OpenCV<b>4.5.5</b>

## 환경 변수
### 환경 변수 이름 : 추가할 경로 
- OPENCV_DIR
  + C:\opencv\build  
- Path
  + %(OPENCV_DIR)%\x64\vc15\bin

## Visual Studio 라이브러리 추가
### 프로젝트 속성
- C/C++
  > 일반/추가 포함 디렉터리:  
  > - $(OPENCV_DIR)\include
- 링커
  > 일반/추가 라이브러리 디렉터리:  
  > - $(OPENCV_DIR)\x64\vc15\lib   
  
  > 입력/추가 종속성:  
  > - debug   :  opencv_world455d.lib
  > - release :  opencv_world455.lib

