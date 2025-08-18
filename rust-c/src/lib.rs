use nalgebra::Vector3;

#[unsafe(no_mangle)]
pub extern "C" fn get_forty_two() -> i32 {
    let foo = Vector3::from_row_slice(&[10, 20, 12]);
    foo.x + foo.y + foo.z
    // 42
}
