//! a WebAssembly module with Rust
extern {
  fn hello_insert_dom();
}

#[no_mangle]
pub extern fn hello_call_js() { // equal pub extern "C" fn ...
    unsafe {
        hello_insert_dom();
    }
}
