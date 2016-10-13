# libfmilib.a  libfmilib_shared.so

rm -rf build
rm -rf install
mkdir build
mkdir install
cp ../../fmi/FMILibrary-2.0.2b3-src/install/lib/libfmilib_shared.so .
gcc -c -O2 -I"../../fmi/FMILibrary-2.0.2b3-src/install/include"  -std=c11 -MMD -MP -MF "build/FMIClient.o.d" -o build/FMIClient.o src/FMIClient.c
gcc -o FMIClient build/FMIClient.o ../../fmi/FMILibrary-2.0.2b3-src/install/lib/libfmilib.a -ldl 

echo "finish"
