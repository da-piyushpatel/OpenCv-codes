#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{

	Mat img = imread("img2.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	Mat out = imread("img2.jpg", CV_LOAD_IMAGE_GRAYSCALE);//else error

	int sobel_y[][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
	int sobel_x[][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
	
	int px,py,res;
	for(int x=1;x<img.rows-2;x++) 
	{
  		for (int y=1;y<img.cols-2;y++)
  		{   
  				//forvertical edge detection
  			  px=(sobel_x[0][0] * img.at<uchar>(x-1,y-1)) + (sobel_x[0][1] * img.at<uchar>(x,y-1)) + (sobel_x[0][2] * img.at<uchar>(x+1,y-1)) +
              	 (sobel_x[1][0] * img.at<uchar>(x-1,y))   + (sobel_x[1][1] * img.at<uchar>(x,y))   + (sobel_x[1][2] * img.at<uchar>(x+1,y)) +
              (sobel_x[2][0] * img.at<uchar>(x-1,y+1)) + (sobel_x[2][1] * img.at<uchar>(x,y+1)) + (sobel_x[2][2] * img.at<uchar>(x+1,y+1));
  			
  				//for horizontal edge detection	
  			  py=(sobel_y[0][0] * img.at<uchar>(x-1,y-1)) + (sobel_y[0][1] * img.at<uchar>(x,y-1)) + (sobel_y[0][2] * img.at<uchar>(x+1,y-1)) +
              	 (sobel_y[1][0] * img.at<uchar>(x-1,y))   + (sobel_y[1][1] * img.at<uchar>(x,y))   + (sobel_y[1][2] * img.at<uchar>(x+1,y)) +
              	 (sobel_y[2][0] * img.at<uchar>(x-1,y+1)) + (sobel_y[2][1] * img.at<uchar>(x,y+1)) + (sobel_y[2][2] * img.at<uchar>(x+1,y+1));
  				
                 px=px/9;
                 py=py/9;
          
  			//out.at<uchar>(x,y)=px;
  			res=ceil(sqrt(px*px+py*py));
                 if(res<20)   
              out.at<uchar>(x,y) = 0;
      else
        out.at<uchar>(x,y) =255;

  		}
	}

	imshow("Original",img);
	cvWaitKey(0);
	imshow("Result",out);

    	cvWaitKey(0);

    	return 1;
}