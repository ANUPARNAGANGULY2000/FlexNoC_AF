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

# Configure Conan (safe if the remote already exists)
RUN if conan remote list | grep -q '^conancenter:'; then \
        conan remote list | grep -q '^conancenter: https://center.conan.io' || \
        conan remote update conancenter https://center.conan.io; \
    else \
        conan remote add conancenter https://center.conan.io; \
    fi

# Set working directory
WORKDIR /flexnoc

# Copy repository into container
COPY . .

# Create Conan profile
RUN conan profile new default --detect --force

# Build project
RUN mkdir build && cd build && \
    conan install .. --build=missing && \
    conan build ..

# Move to build directory
WORKDIR /flexnoc/build

# Default command when container runs
CMD ["./bin/flexnoc","regression"]
