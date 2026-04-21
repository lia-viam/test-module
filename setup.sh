set -e

apt-get update
apt-get install -y software-properties-common

bash -c 'wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|apt-key add -'
apt-add-repository -y 'deb http://apt.llvm.org/bullseye/ llvm-toolchain-bullseye-19 main'
apt-add-repository -y 'deb https://archive.debian.org/debian bullseye-backports main'

apt-get update

apt-get -y install -t llvm-toolchain-bullseye-19 \
    clang-19

echo '[settings]
arch=armv8
build_type=Release
compiler=clang
compiler.cppstd=20
compiler.libcxx=libstdc++11
compiler.version=19
os=Linux

[conf]
tools.build:compiler_executables={"c": "clang-19", "cpp": "clang++-19"}

[options]
boost/*:without_cobalt=True

' > ~/.conan2/profiles/default

conan profile show

