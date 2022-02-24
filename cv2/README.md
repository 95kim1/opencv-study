# 주요 클래스

## 1) 기본 클래스 
---
#include<opencv2/core/types.hpp>  
(#include<opencv2/opencv.hpp>)

### 1-1) Point_ 클래스

[OpenCV: cv::Point_ Class Template Reference](https://docs.opencv.org/4.5.5/db/d4e/classcv_1_1Point__.html#a7df967231a76a7c6c941ba170954ee8a)
#### data
    x, y

#### operator
    Point +[ - * / ] Point
    Point ==[ != ] Point

#### method
    Point = Point.cross(Point)
    Point = Point.dot(Point)
    double size = norm(Point)
    if ( Point.inside(Rect(...)) )

#### constructor
> cv::Point_< _Tp >::Point_	(		)	
> cv::Point_< _Tp >::Point_	(	_Tp 	_x, _Tp 	_y )		
> cv::Point_< _Tp >::Point_	(	const Point_< _Tp > & 	pt	)	  
> cv::Point_< _Tp >::Point_	(	const Size_< _Tp > & 	sz	)	  
> cv::Point_< _Tp >::Point_	(	const Vec< _Tp, 2 > & 	v	)  

#### typedef
> typedef Point_<int> Point2i;   
> typedef Point2i Point;    
> typedef Point_<float> Point2f;    
> typedef Point_<double> Point2d;    

<br><br>

### 1-2) Size_ 클래스

[OpenCV: cv::Size_ Class Template Reference](https://docs.opencv.org/4.5.5/d6/d50/classcv_1_1Size__.html)

#### data
    height, width

#### method
    size = Size.area()
    ratio = Size.aspectRatio()  // width/height.
    if ( Size.empty() )  // width <= 0 or height <= 0

#### constructor
> Size_ ()  
> Size_ (_Tp _width, _Tp _height)  
> Size_ (const Size_ &sz)=default  
> Size_ (Size_ &&sz) CV_NOEXCEPT=default  
> Size_ (const Point_< _Tp > &pt)  

#### typdef
> typedef Size_<int> Size2i;
> typedef Size2i Size;
> typedef Size_<float> Size2f;

<br><br>

### 1-3) Rect_ 클래스

[OpenCV: cv::Rect_ Class Template Reference](https://docs.opencv.org/4.5.5/d2/d44/classcv_1_1Rect__.html)

#### data
    height, widht
    x, y

#### method
    _size = Rect.area()
    Size = Rect.size()
    Point = Rect.br()  // bottom-right
    Point = Rect.tl()  // top-left
    if ( Rect.contain(Point) )
    if ( Rect.empty() )  // height or wight <= 0

#### operator
> rect=rect ± point (shifting a rectangle by a certain offset)  
> rect=rect ± size (expanding or shrinking a rectangle by a certain amount)  
> rect += point, rect -= point, rect += size, rect -= size (augmenting operations)  
> rect = rect1 & rect2 (rectangle intersection)  
> rect = rect1 | rect2 (minimum area rectangle containing rect1 and rect2 )  
> rect &= rect1, rect |= rect1 (and the corresponding augmenting operations)  
> rect == rect1, rect != rect1 (rectangle comparison)  

#### constructor
> Rect_ ()  
> Rect_ (_Tp _x, _Tp _y, _Tp _width, _Tp _height)  
> Rect_ (const Rect_ &r)=default  
> Rect_ (Rect_ &&r) CV_NOEXCEPT=default  
> Rect_ (const Point_< _Tp > &org, const Size_< _Tp > &sz)  
> Rect_ (const Point_< _Tp > &pt1, const Point_< _Tp > &pt2)  


#### (rect1 ⊆ rect2)
    ```cpp
    template<typename _Tp> inline bool
    operator <= (const Rect_<_Tp>& r1, const Rect_<_Tp>& r2)
    {
        return (r1 & r2) == r1;
    }
    ```

#### virtually, loop over an image ROI in OpenCV (where ROI = Recv_<int>)
    ```cpp
    for(int y = roi.y; y < roi.y + roi.height; y++) {
        for(int x = roi.x; x < roi.x + roi.width; x++)
        {
            // ...
        }
    }
    ```
