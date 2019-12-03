//! hello world with WebAssembly
let imports = {
  env: {
       // 'memoryBase':0,
        '__memory_base': 0,
        'tableBase': 0,
        'memory': new WebAssembly.Memory({initial: 256 }),
        'table': new WebAssembly.Table({initial: 256, element: "anyfunc" }),
        _alert: function (p) {
            // 这一块说明请看文章
            alert(utf8ToString(p));
        }
  }
};
function utf8ToString(p) {
    let h = new Uint8Array(imports.env.memory.buffer);
    let s = "";
    for (let i = p; h[i]; i++) {
        s += String.fromCharCode(h[i]);
    }
    return s;
}

fetch('helloworld.wasm').
       then(response => response.arrayBuffer()).
       then(bytes => WebAssembly.instantiate(bytes, imports)).
       then(mod => mod.instance).
       then(instance => {
           let exports = instance.exports;
           exports._sayHi();
       });
