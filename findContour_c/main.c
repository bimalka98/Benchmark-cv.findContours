/*
Author: Bimalka Piyaruwan 
Date Created: 2022/01/13
Last Modified: 2022/01/31

Varable declaration convention
Global Variables        : Start with capital, Combine with Capital letters
Local Variables         : Start with underscore & a simple letter, combine with simple letters
Function Arguments      : Start with simple letters, combine with simple letters
#def define constants   : All Capitals and combined with underscore
*/

// including libraries and dependancies

#define __STDC_WANT_LIB_EXT1__ 1 //this must be defined before including the <stdio.h> library to use fopen_s
#include <stdio.h>
#include <stdlib.h>


// user defined libraries
#include "utilities.h" // Misscelaneous functions
#include "tsa.h" // Paper: "Topological Structural Analysis of Digitized Binary Images by Border Following"
#include "dsa.h" // Data structures and Algorithms
#include <time.h>


// sample binary image for contour detection
/*
short BinaryImage[IMG_HEIGHT][IMG_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
*/

// Sample binary images saved in header files: Remember to image size parameters in the tsa.h file
//#include "image256.h"     // BinaryImage256
#include "image512.h"   // BinaryImage512
//#include "image1024.h"  // BinaryImage1024
//#include "image2048.h"  // BinaryImage2048
 
int main () {

    
    
    // declaring variables to measure time duration
    clock_t _start, _end;
    double _cputimeused;


    _start = clock (); 
    struct Node* contours = findContours (BinaryImage512, IMG_WIDTH, IMG_HEIGHT);
    _end = clock ();
    
    // calculating the execution time
    _cputimeused = ( (( double ) ( _end - _start )) / CLOCKS_PER_SEC );
    printf ("\nStart: %ld", _start);
    printf ("\nEnd: %ld", _end);
    printf ("\nExecution time: %f s", _cputimeused);
    
    /*
    // saving the processed image to a file
    FILE* _fptr;
    char const* _filepath = "image512.txt";
    writeImage (BinaryImage512, &_fptr, _filepath);
    */
    return 0;
}
