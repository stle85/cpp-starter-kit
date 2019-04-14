FROM ubuntu:18.04
MAINTAINER serenissimus

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \
    gcc \
    g++ \
    gdb \
    cmake \
    clang-format \
    cppcheck

WORKDIR /opt/build
VOLUME ["/opt"]
