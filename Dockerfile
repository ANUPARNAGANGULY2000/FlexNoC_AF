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

# Configure Conan (idempotent for rebuilds)
RUN if conan remote list | grep -q '^conancenter:'; then \
        conan remote list | grep -q '^conancenter: https://center.conan.io' || \
        conan remote update conancenter https://center.conan.io; \
    else \
        conan remote add conancenter https://center.conan.io; \
    fi

WORKDIR /flexnoc

# Copy repository into container
COPY . .

# Create Conan profile
RUN conan profile new default --detect --force

# Build project
RUN mkdir -p build && cd build && \
    conan install .. --build=missing && \
    conan build ..

WORKDIR /flexnoc/build

CMD ["./bin/flexnoc","regression"]



# FROM ubuntu:22.04

# ENV DEBIAN_FRONTEND=noninteractive

# RUN apt-get update && apt-get install -y \
#     build-essential \
#     cmake \
#     python3 \
#     python3-pip \
#     git \
#     wget \
#     default-jre \
#     && rm -rf /var/lib/apt/lists/*

# # install Conan (version 1)
# RUN pip3 install "conan<2.0"

# WORKDIR /FlexNoC

# # copy project files
# COPY . .

# # build project
# RUN rm -f conan.lock && \
#     rm -rf build && \
#     mkdir build && \
#     cd build && \
#     conan remote add conancenter https://center.conan.io || true && \
#     conan install .. --build=missing && \
#     cmake .. && \
#     make -j4

# CMD ["/bin/bash"]
