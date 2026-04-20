set -e

apt-get update
apt-get install -y software-properties-common

bash -c 'wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|apt-key add -'
apt-add-repository -y 'deb http://apt.llvm.org/bullseye/ llvm-toolchain-bullseye-15 main'
apt-add-repository -y 'deb https://archive.debian.org/debian bullseye-backports main'

apt-get update

apt-get -y install -t llvm-toolchain-bullseye-15 \
    clang-15 libc++-15-dev

echo '[settings]
arch=armv8
build_type=Release
compiler=clang
compiler.cppstd=20
compiler.libcxx=libc++
compiler.version=15
os=Linux

[conf]
tools.build:compiler_executables={"c": "clang-15", "cpp": "clang++-15"}

[options]
boost/*:without_cobalt=True

' > ~/.conan2/profiles/default

conan profile show

