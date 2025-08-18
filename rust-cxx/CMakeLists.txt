cmake_minimum_required(VERSION 3.20)
project(rust_cxx LANGUAGES CXX)

if(CMAKE_OSX_SYSROOT MATCHES "iphonesimulator")
    set(Rust_CARGO_TARGET "aarch64-apple-ios-sim")
elseif(CMAKE_OSX_SYSROOT MATCHES "iphoneos")
    set(Rust_CARGO_TARGET "aarch64-apple-ios")
endif()

set(CORROSION_VERBOSE_OUTPUT ON)
add_subdirectory(corrosion)

corrosion_import_crate(
  MANIFEST_PATH
    Cargo.toml
  CRATES
    rust-cxx
)

corrosion_add_cxxbridge(
  ${PROJECT_NAME}
  CRATE
    rustcxx
  FILES
    lib.rs
)
