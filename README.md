# FlexNoC: Fast and Flexible Analysis for NoCs with Arbitrary Topologies and Hybrid Arbitration

FlexNoC is a fast and flexible analytical framework for Network-on-Chip (NoC) performance modeling with arbitrary topologies and hybrid arbitration policies.

The framework extends the DOT language using ANTLR to define a Domain-Specific Language (DSL) for describing custom NoC architectures. The DSL supports user-defined attributes for components such as injectors, queues, arbiters, and servers, enabling clear specification of both regular and irregular network topologies.

FlexNoC also supports automatic generation of DOT files for regular NoC topologies such as mesh, torus, and ring networks. These descriptions are parsed and translated into analytical queueing models used to evaluate communication performance.

FlexNoC is designed for:

- Architectural exploration
- Research prototyping
- Performance evaluation of NoC designs


------------------------------------------------------------
Artifact Links
------------------------------------------------------------

GitHub Repository

https://github.com/ANUPARNAGANGULY2000/FlexNoC_AF


Docker Image

https://hub.docker.com/r/anuparnaganguly2000/flexnoc


------------------------------------------------------------
Quick Start (Recommended for Artifact Reviewers)
------------------------------------------------------------

The easiest way to run FlexNoC is using the pre-built Docker image.

Pull the Docker image:

docker pull anuparnaganguly2000/flexnoc:latest


Run regression tests:

docker run anuparnaganguly2000/flexnoc:latest


This command downloads the container and executes the regression test suite automatically.


------------------------------------------------------------
Running a Specific Example (Docker)
------------------------------------------------------------

docker run -it anuparnaganguly2000/flexnoc:latest ./bin/flexnoc irregular ../test/hybrid1.dot


------------------------------------------------------------
Build Docker Image Locally
------------------------------------------------------------

Clone the repository:

git clone https://github.com/ANUPARNAGANGULY2000/FlexNoC_AF.git
cd FlexNoC_AF


Build the Docker image locally:

docker build -t flexnoc .


Run regression tests:

docker run flexnoc


------------------------------------------------------------
Native Build (Without Docker)
------------------------------------------------------------

If Docker is not available, the project can be built directly.

System Requirements:

- Linux (tested on Ubuntu-like environments)
- GCC >= 9
- Python >= 3.7
- CMake >= 3.16
- Java (required for ANTLR)

Required Tools:

- Conan (version < 2.0)
- CMake
- Make


Install Conan:

python3 -m pip install conan==1.66.0


Add Conan Center remote:

conan remote add conancenter https://center.conan.io


Create Conan profile:

conan profile new default --detect


Create build directory:

mkdir build
cd build


Install dependencies:

conan install .. --update --build=missing --build=outdated


Build the project:

conan build ..


Optional manual build:

cmake ..
make -j


The executable will be available at:

bin/flexnoc


------------------------------------------------------------
Running the Executable
------------------------------------------------------------

Run FlexNoC with a user-defined DOT topology:

./bin/flexnoc irregular ../test/hybrid1.dot


FlexNoC can also automatically generate DOT files for regular topologies using a configuration file.

Example:

./bin/flexnoc regular ../test/test.txt


------------------------------------------------------------
Regression Mode
------------------------------------------------------------

Regression mode executes all test DOT files in the test directory.

./bin/flexnoc regression


This mode is useful for validating correctness after updates to the grammar or analytical model.


------------------------------------------------------------
DOT DSL Syntax Guide
------------------------------------------------------------

The DSL extends the DOT language to describe Network-on-Chip (NoC) components using custom attributes.

Each node must define a "type" attribute.


Supported Node Types


Injector

type: Source
rate: <injection_rate>


Queue

type: queue
depth: <buffer_depth>


RoundRobin Arbiter

type: RoundRobin
zero_load: <latency>


Priority Arbiter

type: Priority
zero_load: <latency>


Hybrid Arbiter

type: hybrid
zero_load: <latency>


Server

type: server
t_serv: <service_time>
coeff_var: <coefficient_of_variation>
