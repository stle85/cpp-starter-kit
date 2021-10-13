# Use latest Ubuntu LTS release from Microsoft for VS Code
FROM mcr.microsoft.com/vscode/devcontainers/cpp:ubuntu

# Arguments
# USER_HOME contains the path to the user's home directory
ARG USER_HOME="/home/vscode"

# Set en_US locale for container
RUN \
    locale-gen en_US.UTF-8

ENV \
    LANG=en_US.UTF-8 \
    LANGUAGE=en_US:en \
    LC_ALL=en_US.UTF-8

# Disable interactive from apt(system package management tool)
ENV DEBIAN_FRONTEND=noninteractive

# install dev dependecies
# Clang for C++ development
# Python3 for scripts support
RUN \
    apt update && \
    apt -y --no-install-recommends install \
        clang \
        clang-format \
        clang-tidy \
        clangd \
        curl \
        dos2unix \
        git \
        lld \
        lldb \
        openjdk-11-jdk-headless \
        python3

# Change C++ toolchain to Clang
RUN \
    update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100 && \
    update-alternatives --install /usr/bin/c89 c89 /usr/bin/clang 100 && \
    update-alternatives --install /usr/bin/c99 c99 /usr/bin/clang 100 && \
    update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100 && \
    update-alternatives --install /usr/bin/ld ld /usr/bin/lld 100

# Install bazel and bazel build tools
RUN \
    curl -sLo /usr/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 && \
    chmod +x /usr/bin/bazel && \
    curl -sLo /usr/bin/buildifier https://github.com/bazelbuild/buildtools/releases/latest/download/buildifier-linux-amd64 && \
    chmod +x /usr/bin/buildifier && \
    curl -sLo /usr/bin/buildozer https://github.com/bazelbuild/buildtools/releases/latest/download/buildozer-linux-amd64 && \
    chmod +x /usr/bin/buildozer

# copy useful scripts
COPY scripts ${USER_HOME}/scripts

# add scripts in PATH
RUN \
    dos2unix ${USER_HOME}/scripts/* && \
    chmod +x ${USER_HOME}/scripts/*

ENV PATH="${USER_HOME}/scripts:${PATH}"
