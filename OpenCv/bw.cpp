#include<cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{

 Mat square;
 int image_width,image_height,side_length,k=0;
 	cin >>image_width >>image_height >>nside_length;

	Mat image(image_width,image_height,CV_8UC3,Scalar::all(255));

 for(int i=0;i<image_height;i+=side_length){
  	for(int j=0;j<image_width;j+=side_length)
  	{
  		square=image(Rect(i,j,side_length,side_length));
  		if(k%2==0)
  				square.setTo(Scalar::all(255));
  			else
  				square.setTo(Scalar::all(0));
 
  		k+=1;
  	}k+=1;}
 imwrite( "CHESS.jpg", image );

 namedWindow( "image", CV_WINDOW_AUTOSIZE );
 imshow( "CHESS", image );
 waitKey();
 return 0;
}

