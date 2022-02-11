# Paper: "Automated Visual Inspection: Position Identification of Object for Industrial Robot Application based on Color and Shape"
> Muralindran Mariappan, Tony Chua Tung Ming, Manimehala Nadarajan

## Abstract
*"Inspection task is traditionally carried out by
human. However, Automated Visual Inspection (AVI)
has gradually become more popular than human
inspection due to the advantageous in the aspect of high
precision and short processing time. Therefore, this paper
proposed a system which identifies the object’s position
for industrial robot based on colors and shapes where, red,
green, blue and circle, square, triangle are recognizable.
The proposed system is capable to identify the object’s
position in three modes, either based on color, shape or
both color and shape of the desired objects. During the
image processing, RGB color space is utilized by the
proposed system while winner take all approach is used
to classify the color of the object through the evaluation
of the pixel’s intensity value of the R, G and B channel.
Meanwhile, the shapes and position of the objects are
determined based on the compactness and the centroid of
the region respectively. Camera settings, such as
brightness, contrast and exposure is another important
factor which can affect the performance of the proposed
system. Lastly, a Graphical User Interface was developed.
The experimental result shows that the developed system
is highly efficient when implemented in the selected
database."*

# Timing Analysis of Contour finding algorithms

|Image size|cLang_findContour on PC (Image Type: int)|openCV_findContour on PC(Python) | cLang_findContour on RPi (Image Type: short) | openCV_findContour on RPi(C++)|
|:------:|:----:|:-----:|:-----:|:-----:|
|256x256|653 us|73 us|683 us| 650 us|
|512x512|781 us|445 us|1140 us| 2000 us|
|1024x1024|1268 us|2000 us|2162 us | 6000 us|
