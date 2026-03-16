FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    python3 \
    python3-pip \
    git \
    wget \
    default-jre \
    && rm -rf /var/lib/apt/lists/*

# install Conan (version 1)
RUN pip3 install "conan<2.0"

WORKDIR /FlexNoC

# copy project files
COPY . .

# build project
RUN rm -f conan.lock && \
    rm -rf build && \
    mkdir build && \
    cd build && \
    conan remote add conancenter https://center.conan.io || true && \
    conan install .. --build=missing && \
    cmake .. && \
    make -j4

CMD ["/bin/bash"]
