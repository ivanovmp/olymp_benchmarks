Table:

|Computer|OS|Compiler|Eratosthenes (45'000'000)|Output (45'000'000)|Input (45'000'000)|Random numbers (45'000'000)|Floyd–Warshall (1540)|
|-|-|-|-|-|-|-|-|
|Godbolt|Linux|[x86-64 gcc 13.2](https://godbolt.org/z/eEW56KrY4)|264.6 ms|1.783 s|848.1 ms|74.08 ms|5.677 s|
|Godbolt|Linux|[x86-64 icc 19.0.1](https://godbolt.org/z/eEW56KrY4)|381.8 ms|1.933 s|824.8 ms|96.53 ms|5.034 s|
|Godbolt|Linux|[x86-64 clang 17.0.1](https://godbolt.org/z/eEW56KrY4)|287.2 ms|1.684 s|881.1 ms|216.4 ms|4.302 s|
|Codeforces|Windows|[GNU G++20 11.2.0 (64 bits, winlibs)](https://codeforces.com/contest/1/customtest)|341.6 ms|5.611 s|7.361 s|252.6 ms|4.729 s|
|orz MacBook Air|MacOS Ventura 13.5.1|Apple clang 15.0.0|169.1 ms|5.447 s|10 s|175.5 ms|2.118 s|
|orz Predator|Windows 11 Home|x86-64 msvc 19.37.32824|228.8 ms|14.26 s|20.9 s|116.2 ms|3.902 s|
|orz Predator|Windows 11 Home|x86-64 mingw.org gcc build-2 9.2.0|203.1 ms|13.36 s|31.96 s|250 ms|1.375 s|
|orz Predator|[Ubuntu 22.04 ICPC Image](https://image.icpc.global/icpc2023/ImageBuildInstructions.html)|x86-64 ubuntu gcc 11.3.0|228.7 ms|2.232 s|2.377 s|211.8 ms|1.691 s|
|Google Colab|Linux 5.15.120+ x86_64 with glibc2.3|[Ubuntu gcc 11.4.0-1ubuntu1~22.04](https://colab.research.google.com/drive/1kW_vWlNgGP5HG64HNa9cR-MnQdsrqz72?usp=sharing)|4.757 s|6.418 s|6.75 s|1.765 s|1.613 min|
