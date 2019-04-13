FROM ubuntu:16.04
MAINTAINER serenissimus

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y gcc g++ gdb cmake

WORKDIR /opt/build
VOLUME ["/opt"]
