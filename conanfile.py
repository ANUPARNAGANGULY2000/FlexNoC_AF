from conans import CMake, ConanFile, tools


class dotDSL(ConanFile):
    name = "dot_dsl"

    settings = "os", "compiler", "build_type"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "test": [True, False],
        "coverage": [True, False],
    }
    default_options = {
        "shared": False,
        "test": True,
        "fPIC": True,
        "coverage": False,
    }

    build_requires = ()
    requires = ("fmt/8.1.1", "antlr4-cppruntime/4.13.1", "boost/1.78.0")

    build_policy = ("missing", "outdated")

    generators = "cmake", "cmake_find_package", "json", "virtualenv"

    __cmake = None

    def export_sources(self):
        self.copy("CMakeLists.txt")
        self.copy("src/*")
        self.copy("include/*")
        self.copy("LICENSE")

    def build_requirements(self):
        if self.options.test:
            self.test_requires("gtest/[>=1.13.0]")
        self.build_requires("antlr4-cppruntime/4.13.1")

    def set_cmake_definitions(self):
        self.__cmake.definitions["COVERAGE"] = self.options.coverage
        self.__cmake.definitions["BUILD_TESTING"] = self.options.test

    def set_version(self):
        if self.version is not None:
            return
        else:
            return "0.0.1"

    @property
    def _cmake(self):
        if self.__cmake is None:
            if self.settings.build_type == "Debug":
                self.__cmake = CMake(self, build_type="Debug")
            elif self.settings.build_type == "Release":
                self.__cmake = CMake(self, build_type="Release")
            self.set_cmake_definitions()
        return self.__cmake

    def build(self):
        self._cmake.configure(source_dir=self.source_folder)
        self._cmake.build()
        if self.options.test:
            if tools.get_env("CONAN_RUN_TESTS", True):
                self._cmake.test(output_on_failure=True)

    def package(self):
        self._cmake.install()

    def package_info(self):
        self.cpp_info.name = "DotDSL"

        self.cpp_info.components["libdot_dsl"].names[
            "cmake_find_package"] = "dot_dsl"
        self.cpp_info.components["libdot_dsl"].libs = [
            "dot_dsl"
        ]
        self.cpp_info.components["libdot_dsl"].requires = [
            "fmt::fmt",
        ]
