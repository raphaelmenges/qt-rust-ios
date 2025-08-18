# Qt app with Rust on iOS

Should build and run on macOS for macOS and on macOS for iOS or the iPhone simulator.

### Requirements
- macOS
- CMake
- Qt for macOS, iOS, and iPhone simulator
- XCode including iPhone simulator
- Rust

### How to build for macOS

1. Generate project via CMake:
```
cmake \
-B build-macos \
-S . \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_PREFIX_PATH="~/Qt/6.8.3/macos" \
-DCMAKE_TOOLCHAIN_FILE="~/Qt/6.8.3/macos/lib/cmake/Qt6/qt.toolchain.cmake" \
-DCMAKE_OSX_DEPLOYMENT_TARGET=12.0
```

2. Build project via CMake: `cmake --build build-macos`

### How to build for iOS or iPhone simulator

1. Generate project via CMake:
```
cmake \
-B build-ios \ # Or "build-iphone-simulator"
-S . \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_PREFIX_PATH="~/Qt/6.8.3/ios" \
-DCMAKE_TOOLCHAIN_FILE="~/Qt/6.8.3/ios/lib/cmake/Qt6/qt.toolchain.cmake" \
-DCMAKE_SYSTEM_NAME=iOS \
-DCMAKE_OSX_SYSROOT=iphoneos \ # or "iphonesimulator"
-DCMAKE_OSX_ARCHITECTURES=arm64 \
-DCMAKE_OSX_DEPLOYMENT_TARGET=16.0
```

2. Build project via CMake: `cmake --build build-ios`