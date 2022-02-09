
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

namespace
{
const int         CURRENT_OPENCV_BUILD_MAJOR{ 4 };
const int         CURRENT_OPENCV_BUILD_MINOR{ 4 };
const int         CURRENT_OPENCV_BUILD_REVISION = { 0 };
const std::string IMAGE{ "belt.png" };
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
    if ( !check_build_info( ) ) {
        std::cout << "SUCCESS: You are using latest OpenCV version, with NEON/TBB support enabled." << std::endl;
    } else {
        std::cout << "FAIL: You are using wrong OpenCV version or without NEON/TBB support enabled." << std::endl;
        return 1;
    }

    auto image = cv::imread( IMAGE );
    if ( !image.data ) {
        std::cout << "ERROR: Could not open or find the image" << std::endl;
        return 1;
    }

    cv::Mat gray_image, thresholded_image;
    cv::cvtColor( image, gray_image, cv::COLOR_BGR2GRAY );
    cv::threshold( gray_image, thresholded_image, 0, 255, cv.THRESH_BINARY_INV+cv.THRESH_OTSU );

    std::vector< std::vector< cv::Point > > contours;
    cv::findContours( thresholded_image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE );
    cv::drawContours( image, contours, -1, cv::Scalar( 0, 255, 0 ), 3 );

    cv::imshow( "Image", image );
    cv::waitKey( 0 );

    return 0;
}
