
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace std::chrono;

namespace
{
const int         CURRENT_OPENCV_BUILD_MAJOR{ 4 };
const int         CURRENT_OPENCV_BUILD_MINOR{ 4 };
const int         CURRENT_OPENCV_BUILD_REVISION = { 0 };
const std::string IMAGE{ "image256.png" };
}

bool
check_build_info( )
{
    bool error_found{ false };

    std::cout << "OpenCV version: " << cv::getVersionMajor( ) << "." << cv::getVersionMinor( ) << "."
              << cv::getVersionRevision( ) << std::endl;
    if ( cv::getVersionMajor( ) != CURRENT_OPENCV_BUILD_MAJOR || cv::getVersionMinor( ) != CURRENT_OPENCV_BUILD_MINOR ||
         cv::getVersionRevision( ) != CURRENT_OPENCV_BUILD_REVISION ) {
        std::cout << "ERROR: OpenCV version is different than the expected." << std::endl;
        error_found = true;
    }

    std::cout << "Available CPUs: " << cv::getNumberOfCPUs( ) << std::endl;
    std::cout << "Available threads: " << cv::getNumThreads( ) << std::endl;
    if ( cv::getNumThreads( ) < cv::getNumberOfCPUs( ) ) {
        std::cout << "ERROR: TBB is not enabled." << std::endl;
        error_found = true;
    }

    std::cout << "Cpu NEON support: " << cv::checkHardwareSupport( CV_CPU_NEON ) << std::endl;
    if ( cv::checkHardwareSupport( CV_CPU_NEON ) == 0 ) {
        std::cout << "ERROR: NEON is not enabled." << std::endl;
        error_found = true;
    }

    return error_found;
}

int
main( )
{
    // build info check
    /*
    if ( !check_build_info( ) ) {
        std::cout << "SUCCESS: You are using latest OpenCV version, with NEON/TBB support enabled." << std::endl;
    } else {
        std::cout << "FAIL: You are using wrong OpenCV version or without NEON/TBB support enabled." << std::endl;
        return 1;
    }*/

    auto image = cv::imread( IMAGE );
    if ( !image.data ) {
        std::cout << "ERROR: Could not open or find the image" << std::endl;
        return 1;
    }
    
    /*
    *************************************************************
    **               Object Detection Framework                **
    *************************************************************
    */

    
    
    cv::Mat _grayimage, _thresholdedimage, _closedimage;

    // Convert the image to grayscale
    cv::cvtColor( image, _grayimage, cv::COLOR_BGR2GRAY );
    
    
    
    
    
    // Threshold the image
    cv::threshold( _grayimage, _thresholdedimage, 0, 255, cv::THRESH_BINARY_INV+cv::THRESH_OTSU );
    
    
    
    
    
    // morphological closing (fill small holes in the foreground)
    cv::Mat _element = cv::getStructuringElement( cv::MORPH_RECT, cv::Size( 3, 3 ) );
    cv::morphologyEx( _thresholdedimage, _closedimage, cv::MORPH_CLOSE, _element );
    
    // Get the timepoint before the object detection
    auto start = high_resolution_clock::now();

    // conneceted component analysis
    cv::Mat _labels, _stats, _centroids;
    int _numberofobjects = cv::connectedComponentsWithStats( _closedimage, _labels, _stats, _centroids );
    
    // Get the timepoint after the the object detection
    auto stop = high_resolution_clock::now();
    

    // Calculate the duration
    auto duration = duration_cast<microseconds>( stop - start );
    // std::cout << "Time taken by findContours function: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Time taken : " << duration.count() << " microseconds" << std::endl;

    // Display the labels and centroids with bounding boxes
    // Neglecting the 0 labeled background by starting from 1
    for ( int i = 1; i < _numberofobjects; i++ ) {

        int _x      = _stats.at< int >( i, cv::CC_STAT_LEFT );
        int _y      = _stats.at< int >( i, cv::CC_STAT_TOP );
        int _width  = _stats.at< int >( i, cv::CC_STAT_WIDTH );
        int _height = _stats.at< int >( i, cv::CC_STAT_HEIGHT );
        double _cx  = _centroids.at<double>(i, 0);
        double _cy  = _centroids.at<double>(i, 1);

        // generating the bounding box
        cv::Rect _boundingbox( _x, _y, _width, _height );
        // draw the bounding box
        cv::rectangle( image, _boundingbox, cv::Scalar( 0, 0, 255 ), 2 );
        // mark the number of the object
        cv::putText( image, std::to_string( i ), cv::Point(_cx, _cy) , cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar( 0, 0, 255 ), 2 );
        // mark the center of the object
        cv::circle( image, cv::Point(_cx, _cy), 0, cv::Scalar( 0, 0, 255 ), -1 );
    }
    std::cout << "CCA Complete." << std::endl;
    cv::imshow( "Detected Objects", image );
    cv::waitKey( 0 );

    /*
    *************************************************************
    **                Object Tracking Framework                **
    *************************************************************
    */

    std::cout << "Tracking started." << std::endl;
    // Get the timepoint before the object tracking
    start = high_resolution_clock::now();

    // subtracting the background
    cv::Mat _ones = cv::Mat::ones( _closedimage.size(), CV_8UC1 );
    cv::Mat _mask;
    cv::bitwise_and( _ones, _labels, _mask );
    
    // Visualize the mask
    //cv::imshow( "Mask", _mask );
    //cv::waitKey( 0 );
    
    std::vector< std::vector< cv::Point > > _contours;
    cv::findContours( _mask, _contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE );
    
    // Get the timepoint after the object tracking
    stop = high_resolution_clock::now();

    // Calculate the duration
    duration = duration_cast<microseconds>( stop - start );
    std::cout << "Time taken by findContours function: " << duration.count() << " microseconds" << std::endl;

    // draw contours
    cv::drawContours( image, _contours, -1, cv::Scalar( 0, 255, 0 ), 3 );
    cv::imshow( "Contours of Objects", image );
    cv::waitKey( 0 );

    return 0;
}
