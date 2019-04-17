FROM ubuntu:18.04
MAINTAINER serenissimus

# Installing packages
RUN DEBIAN_FRONTEND=noninteractive apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \
    gcc \
    g++ \
    gdb \
    gdbserver \
    cmake \
    clang-format \
    clang-tidy \
    cppcheck \
    doxygen

# Cleanup container
RUN DEBIAN_FRONTEND=noninteractive apt-get clean autoclean -y
RUN DEBIAN_FRONTEND=noninteractive apt-get autoremove -y
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Suppress a warning when running gdb in the container
RUN echo "set auto-load safe-path /" >> /root/.gdbinit

# For gdbserver
EXPOSE 2000

WORKDIR /opt/build
VOLUME ["/opt"]
