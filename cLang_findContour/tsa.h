/*
Paper Implementation:
"Topological Structural Analysis of Digitized Binary Images by Border Following"
by SATOSHI SUZUKI AND KEIICHI ABE

Author          : Bimalka Piyaruwan
Date Created    : 2022/01/18
Last Modified   : 2022/01/28

Algorithms can be effectively used in component counting, shrinking, and
topological structural analysis of binary images, when a sequential digital computer is used.
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "dsa.h"

// defining parameters of the image
#define IMG_HEIGHT 1024
#define IMG_WIDTH  1024

// type definitiions
enum Direction{
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST
};



// declaring the fucntion to find the contours of the binary image
struct Node* findContours (short binary_image[IMG_HEIGHT][IMG_WIDTH], short image_width, short image_height);

struct Coordinate findFirstNonZeroPixel (
    struct Coordinate ij,
    struct Coordinate i2j2,
    short binaryimage[IMG_HEIGHT][IMG_WIDTH],
    bool cloclwise,
    short examined[],
    struct Coordinate mooreneighborhood[]); // array is required only when traversing CCW(Counter Clock Wise) at step 3.4

struct Node* followBorder (
    struct Coordinate ij,
    struct Coordinate* i2j2,
    short binary_image[IMG_HEIGHT][IMG_WIDTH],
    short nbd,
    short* lnbd);

struct Coordinate getPreviouslyExaminedPixel (
    struct Coordinate centerpixel,
    short examinedpixels[],
    struct Coordinate mooreneighborhood[]); // This fucntion was not used inside the algorithm. Found a new way of doing the same thing.
