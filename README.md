# FlexNoC: Fast and Flexible Analysis for NoCs with Arbitrary Topologies and Hybrid Arbitration

FlexNoC is a Fast and Flexible Analysis framework for NoCs with Arbitrary Topologies andHybrid Arbitration. This project extends the DOT language using ANTLR to define a Domain-SpecificLanguage(DSL) for describing custom Network-on-Chip(NoC) topologies. It supports user-defined attributes for components such as injectors, queues, arbiters, and servers and enable clearspecification of the network-on-chip (NoC) to explore irregular topology. FlexNoC offers automatic generation of .dot for regular NoC topologies. This automatic topology generation feature simplifies the process of exploring regular NoC topologies such as mesh, torus, and ring The DSL simplifies parsing, validation, and simulation of communication behavior on NoCs using analytical model.

FlexNoC is designed for architectural exploration, research prototyping, and performance evaluation of NoC designs.


## DOT File Syntax Guide (DSL Rules)

This DSL extends the DOT language to describe **Network-on-Chip (NoC)** components using custom attributes. The compiler parses these attributes to construct the analytical model.
Each node must define a `type` attribute. Additional attributes depend on the node type.

### Supported Node Types and their Attributes:

- **injector**
  - type: `Source`
  - Required: `rate`

- **queue**
  - type: `queue`
  - Required: `depth`

- **RoundRobin Arbiter**
  - type: `RoundRobin`
  - Required: `zero_load`

- **Priority Arbiter**
  - type: `Priority`
  - Required: `zero_load`

- **Hybrid Arbiter**
  - type: `hybrid`
  - Required: `zero_load`

- **Server**
  - type: `server`
  - Required: `t_serv`, `coeff_var`

- **Split**
  - type: `split`
  - Required: `out={port probabilities}`

- **Sink**
  - type: `sink`

**Note** 
- The compiler will validate all **required** attributes. Missing or incorrect attributes will raise an **error**.
- Ensure every node is connected to correct node and every node is defined properly with its type and parameters.

For real examples, check the provided `.dot` files:

- `graph2.dot`
- `graph3.dot`
- `graph4.dot`
- `hybrid1.dot`

## Prerequisites

### System Requirements

- Linux (tested on Ubuntu-like environments)

- GCC ≥ 9

- Python ≥ 3.7

- CMake ≥ 3.16

### Required Tools

- Conan (version < 2.0)

- CMake

- Make

Important: This project currently relies on Conan 1.x APIs and is not compatible with Conan 2.x.

## Building with Conan

To build the project, you can use Conan, a package manager for C and C++ libraries. Follow the steps below to set up and build the project:

### Note on Conan Dependency Fetching

This project uses Conan for dependency management.  
In some restricted network environments (e.g., institutional or firewall-restricted systems),
access to `conan.io` may be blocked, which can cause dependency resolution to fail.

If such an issue occurs, please ensure that:
- Internet access to `conan.io` is permitted, or
- Conan is configured to use a local cache or an alternative mirror.

Once dependencies are available locally, the build and tests proceed normally.


1. Install Conan by following the instructions in the [Conan documentation](https://docs.conan.io/en/latest/installation.html).

    **Note** the conanfile.py used here relies upon conan version < 2.0.  If you have a python installation, you can install using e.g., 
    ```bash
    python3 -m pip install conan==1.66.0
    ```
2. Ensure conancenter is added as a remote to grab dependencies:

    ```bash
    conan remote add conancenter https://center.conan.io
    ```

2. Clone the DSL project repository from the following location:

    ```bash
    git clone https://anonymous.4open.science/r/FlexNoC
    ```

3. Change to the project directory:

    ```bash
    cd FlexNoC
    ```

4. Create a Conan profile for your build environment:

    ```bash
    conan profile new default --detect
    ```

5. Create and cd into a build directory:
    ```bash
    mkdir build && cd build
    ```

6. Add the required dependencies to Conan:

    ```bash
    conan install .. --update --build=missing --build=outdated
    ```

7. Build the project:

    ```bash
    conan build ..
    ```
This final build step invokes cmake to build the project.

8. (Optional) Manual Build with CMake and Make:

    If `conan build ..` does not automatically compile everything, you can manually configure and compile the project.

    ```bash
     cmake ..
     make -j
    ```
This will build the main executable `bin/dot_iso`.

9. Running the Executable:

Once the build is complete, run the tool using 

   ```bash
   ./bin/flexnoc irregular ../test/hybrid1.dot
   ```
Replace `hybrid1.dot` with any DOT file containing valid NoC specifications for irregular topology.

10. Auto-generation of DOT files(Regular Mesh Topology):

This mode generates a full DOT file automatically based on parameters supplied in a `.txt` config file.
  
   ```bash
   ./bin/flexnoc regular ../test/test.txt
   ```
Replace `test.txt` with any `.txt` file containing valid NoC specifications for regular topology.

11. Running regression test mode:

Regression mode automatically executes all test DOT files inside the test directory.

   ```bash
   ./bin/flexnoc regression
   ```
This is useful for verifying correctness after grammar or compiler updates.

## Workflow of FlexNoC Framework

The tool supports both **regular topology(auto-generated)** and **irregular topologies(user-provided DOT file** depending on the mode.
This framework automatically performs the following steps:

1. Reads the configuration file.
2. Generates an auto-generated DOT file for regular topology.
3. Parses the produced DOT file and set the data-structure.
4. Update injection process and split probability if needed.
5. Invoke analytical model.
6. Calculate Waiting time.
7. Prints Waiting time of each Injector and Queues.


**Note:** Java is required to run ANTLR4, which is included as a .jar file.

For more information on antlr4, please see [their documentation](https://www.antlr.org/).
