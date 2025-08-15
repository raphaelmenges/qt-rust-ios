cmake_minimum_required(VERSION 3.20)
project(mybridge LANGUAGES CXX)

if(CMAKE_OSX_SYSROOT MATCHES "iphonesimulator")
    set(Rust_CARGO_TARGET "aarch64-apple-ios-sim")
elseif(CMAKE_OSX_SYSROOT MATCHES "iphoneos")
    set(Rust_CARGO_TARGET "aarch64-apple-ios")
endif()

set(CORROSION_USE_HOST_BUILD ON)
set(CORROSION_VERBOSE_OUTPUT ON)
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

if(Rust_CARGO_TARGET MATCHES "aarch64-apple-ios")
  corrosion_add_target_rustflags(mybridgecxx
    "-C link-arg=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk"
    "-C link-arg=-L/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/lib"
  )
endif()
