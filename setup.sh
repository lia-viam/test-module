set -e

apt-get update
apt-get install -y software-properties-common

conan profile show

cmake --version

