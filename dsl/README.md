# DOT Domain-Specific Language (DSL) Extension for Network Topologies

This document provides an overview of the updates made to the DOT language to support custom attributes for queues, arbiters, and other components in order to enforce specific syntax constructs and enable clear specification of the network-on-chip (NoC).

## Overview

The DSL project is a domain-specific language designed to simplify the development of specific applications within a particular domain. It provides a set of abstractions and syntax tailored to the needs of that domain, making it easier for developers to express their intent and solve problems efficiently.

## Building with Conan

To build the project, you can use Conan, a package manager for C and C++ libraries. Follow the steps below to set up and build the project:

1. Install Conan by following the instructions in the [Conan documentation](https://docs.conan.io/en/latest/installation.html).

    **Note** the conanfile.py used here relies upon conan version < 2.0.  If you have a python installation, you can install using e.g., 
    ```bash
    python -m pip install conan==1.66.0
    ```
2. Ensure conancenter is added as a remote to grab dependencies:

    ```bash
    conan remote add conancenter https://center.conan.io
    ```

2. Clone the DSL project repository from the following location:

    ```bash
    git clone https://github.com/path/to/dsl-project.git
    ```

3. Change to the project directory:

    ```bash
    cd dsl-project/dsl
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

This final build step invokes cmake to build the project and runs any tests in the `dsl/test` directory.

**Note:** Java is required to run ANTLR4, which is included as a .jar file.

For more information on antlr4, please see [their documentation](https://www.antlr.org/).