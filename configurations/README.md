# Installing Raspberry pi OS

- https://github.com/bimalka98/Raspberry-Pi-Projects

# Build and Install OpenCV 4 for Raspberry Pi

- https://learnopencv.com/build-and-install-opencv-4-for-raspberry-pi/

You can significantly optimize OpenCV by letting it know more details of your hardware during the compilation.

Here is the full list of ARM CPU features, and the corresponding CMake options for OpenCV configuration:


|CPU Feature |	CMake Key	|Comment|
|:----:|:-----|:-----|
|thumb	|N/A	|ARM Thumb instruction set is enabled by default|
|VFPv3	|-DENABLE_VFPV3=ON|	ARM VFPv3 floating point instructions extension|
|NEON	|-DENABLE_NEON=ON	|ARM NEON vector instruction set|

```shell
pi@rpibimalka98:~ $ cat /proc/cpuinfo
processor       : 0
model name      : ARMv7 Processor rev 4 (v7l)
BogoMIPS        : 38.40
Features        : half thumb fastmult vfp edsp neon vfpv3 tls vfpv4 idiva idivt vfpd32 lpae evtstrm crc32
CPU implementer : 0x41
CPU architecture: 7
CPU variant     : 0x0
CPU part        : 0xd03
CPU revision    : 4

```

# Cmake platform settings options

```
cmake -DENABLE_NEON=ON -DENABLE_VFPV3=ON -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules ../opencv


```
# Personal Access Token

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
