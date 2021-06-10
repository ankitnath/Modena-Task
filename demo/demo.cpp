#include<iostream>
#include "utils.h"
#include "Specs.h"
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv){
    // std::cout<<"This is the demo, using ";
    // printOpenCVVersion();
    if ( argc != 3 )
    {
        std::cout<<"usage: DisplayImage.out <Image_Path> <Spec_file>"<<std::endl;
        return -1;
    }
    Mat image;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    Specs resizeSpecs;
    resizeSpecs.parseFromFile(argv[2]);


    // debug test
    // std::cout<<"Max Width : "<< resizeSpecs.getMaxWidth()<<std::endl;
    // std::cout<<"Max height : "<<resizeSpecs.getMaxHeight()<<std::endl;
    // std::cout<<"Avg width : "<<resizeSpecs.getAvgWidth()<<std::endl;
    // std::cout<<"Avg height : "<<resizeSpecs.getAvgHeight()<<std::endl;

    Mat img1(resizeSpecs.getAvgWidth(), resizeSpecs.getMaxHeight(), CV_8UC3, Scalar(10, 100, 150)); //mock image
    Mat outImg;

    std::cout << "Resizing \'"<<argv[1]<<"\' with specs from \'"<<argv[2]<<"\' file."<<std::endl;   

    cv::resize(image, outImg, img1.size());
    std::cout << "Displaying both images.."<<std::endl;

    imwrite("./resized.jpg", outImg);
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    namedWindow("Display outImage", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    imshow("Display outImage", outImg);
    
    waitKey(0);
    

    return 0;
}