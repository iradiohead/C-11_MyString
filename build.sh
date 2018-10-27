#!/bin/bash

echo "Environment: `uname -a`"
#echo "Compiler: `$CXX --version`"

if [ -d build ]
then
    echo "removing the build folder"
    rm -rf build
fi

mkdir -p build
cd build

echo "=================cmake================"
cmake -DCMAKE_BUILD_TYPE=ON -DBUILD_TESTS=ON .. 

echo "================make all targets======"
make
make Sting_coverage

echo "================run string============"
./String


echo "================run unit testing======"
cd ./test
./unittest_string

#make test
#make String
#echo "returning to up folder"
cd ../../
#codecov -t 6cab29fe-1861-468f-903e-61e4fc96107e -X gcov
