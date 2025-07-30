cmake_minimum_required(VERSION 3.20)
project(mybridge LANGUAGES CXX)

if(CMAKE_OSX_SYSROOT MATCHES "iPhoneSimulator")
    set(Rust_CARGO_TARGET "aarch64-apple-ios-sim")
elseif(CMAKE_OSX_SYSROOT MATCHES "iPhoneOS")
    set(Rust_CARGO_TARGET "aarch64-apple-ios")
endif()

message(STATUS "CMAKE_OSX_SYSROOT=${CMAKE_OSX_SYSROOT}")
message(STATUS "Rust_CARGO_TARGET=${Rust_CARGO_TARGET}")

add_subdirectory(corrosion)

corrosion_import_crate(
  MANIFEST_PATH
    Cargo.toml
  CRATES
    mybridge-cxx
)

corrosion_add_cxxbridge(
  ${PROJECT_NAME}
  CRATE
    mybridgecxx
  FILES
    lib.rs
)
