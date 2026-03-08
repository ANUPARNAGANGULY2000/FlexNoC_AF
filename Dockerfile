FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    python3 \
    python3-pip \
    default-jre \
    wget

# Install Conan (version compatible with project)
RUN python3 -m pip install conan==1.66.0

# Configure Conan
RUN conan remote add conancenter https://center.conan.io

WORKDIR /flexnoc

# Copy repository into container
COPY . .

# Create Conan profile
RUN conan profile new default --detect

# Build project
RUN mkdir build && cd build && \
    conan install .. --build=missing && \
    conan build ..

WORKDIR /flexnoc/build

CMD ["./bin/flexnoc","regression"]
