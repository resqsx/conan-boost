mkdir build

cd build

conan install ../conanfile.txt -s build_type=Release -g=cmake --build=missing

cmake -H./.. -B. -DCMAKE_INSTALL_PREFIX=./../out -DCMAKE_BUILD_TYPE=Release -G "Ninja"

cmake --build . --config Release

