#[cxx::bridge(namespace = "rust_cxx")]
mod ffi {
    extern "Rust" {
        fn hello_world() -> String;
    }
}

pub fn hello_world() -> String {
    String::from("Hello World from Rust-CXX-crate!")
}
