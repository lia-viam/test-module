set -e

apt-get update
apt-get install -y software-properties-common

bash -c 'wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|apt-key add -'
apt-add-repository -y 'deb http://apt.llvm.org/bullseye/ llvm-toolchain-bullseye-19 main'
apt-add-repository -y 'deb https://archive.debian.org/debian bullseye-backports main'

apt-get update

apt-get -y install -t llvm-toolchain-bullseye-19 \
    clang-19 libc++-19-dev libc++abi-19-dev

echo '[settings]
arch={{detect_api.detect_arch()}}
build_type=Release
compiler=clang
compiler.cppstd=17
compiler.libcxx=libc++
compiler.version=19
os=Linux

[conf]
tools.build:compiler_executables={"c": "clang-19", "cpp": "clang++-19"}
tools.build:exelinkflags+=["-static-libstdc++"]
tools.build:sharedlinkflags+=["-static-libstdc++"]

[buildenv]
LD_LIBRARY_PATH+=/usr/lib/llvm-19/lib

[options]
boost/*:without_cobalt=True

' > ~/.conan2/profiles/default

conan profile show

cmake --version

