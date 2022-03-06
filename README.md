# Timing Analysis of Contour finding algorithms

|Image size|cLang_findContour on PC (Image Type: int)|openCV_findContour on PC(Python) | cLang_findContour on RPi (Image Type: short) | openCV_findContour on RPi(C++)|
|:------:|:----:|:-----:|:-----:|:-----:|
|256x256|653 us|73 us|683 us| 650 us|
|512x512|781 us|445 us|1140 us| 2000 us|
|1024x1024|1268 us|2000 us|2162 us | 6000 us|

# Device specifications

| *PC*| *Raspberry Pi 3 B+*|
|:----|:---|
|- **Processor**: Intel(R) Core(TM) i7-7700HQ CPU @ 2.80GHz   2.81 GHz |- **SoC**: Broadcom BCM2837B0 quad-core A53 (ARMv8) 64-bit @ 1.4GHz<br> |
|- **RAM**: 8.00 GB (7.89 GB usable)|- **RAM**: 1GB LPDDR2 SDRAM|
