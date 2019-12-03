//! hello world with WebAssembly
const imports = {
  env: {
    hello_insert_dom: () => {
      const h1 = document.createElement('h1');
      h1.innerHTML = 'Hello, world';
      const body = document.querySelector('body');
      body.appendChild(h1);
    }
  }
};
 
fetch('build/hello.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, imports))
  .then(results => {
    console.log(results);
    const exports = results.instance.exports;
    exports.hello_call_js();
    // exports.hello_call_js_pass_data();
  });

