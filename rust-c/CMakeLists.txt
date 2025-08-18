cmake_minimum_required(VERSION 3.20)
project(rust_c LANGUAGES CXX)

string(TOLOWER "${CMAKE_OSX_SYSROOT}" SYSROOT_LOWER)
if(SYSROOT_LOWER MATCHES "iphonesimulator")
    set(Rust_CARGO_TARGET "aarch64-apple-ios-sim")
elseif(SYSROOT_LOWER MATCHES "iphoneos")
    set(Rust_CARGO_TARGET "aarch64-apple-ios")
endif()

set(CORROSION_VERBOSE_OUTPUT ON)
add_subdirectory(corrosion)

corrosion_import_crate(MANIFEST_PATH Cargo.toml)

add_library(${PROJECT_NAME} ALIAS rustc) # Align with rust-cxx naming scheme.
