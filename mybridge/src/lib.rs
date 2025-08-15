#[cxx::bridge(namespace = "my_bridge")]
mod ffi {
    extern "Rust" {
        fn hello_world() -> String;
    }
}

pub fn hello_world() -> String {
    String::from("Hello World from Rust with CXX!")
}