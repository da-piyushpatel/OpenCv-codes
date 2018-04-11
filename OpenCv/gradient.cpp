#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{

	Mat img = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

	Mat grad = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

	//to calculate geradient 
	for(int j=0;j<img.rows;j++) 
	{
  		for (int i=0;i<img.cols;i++)
  		{   
       			if(i==img.cols-1)
				grad.at<uchar>(j,i)=fabs(img.at<uchar>(j,i)-img.at<uchar>(j,i-1))/2;
			else if(i==0)
				grad.at<uchar>(j,i)=fabs(img.at<uchar>(j,i+1)-img.at<uchar>(j,i))/2;			
			else
				grad.at<uchar>(j,i)=fabs(img.at<uchar>(j,i-1)-img.at<uchar>(j,i+1))/2;

  		}
	}


	for(int j=0;j<img.rows;j++) 
	{
  		for (int i=0;i<img.cols;i++)
  		{
    			if( grad.at<uchar>(j,i)<4.25)   
       				img.at<uchar>(j,i) = 255;
			else
				img.at<uchar>(j,i) = 0;
  		}
	}

	imshow("Result",img);

    	cvWaitKey(0);

    	return 1;
}