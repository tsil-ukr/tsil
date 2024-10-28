const fs = require('node:fs');

const wasmBuffer = fs.readFileSync('./привіт.wasm');

WebAssembly.instantiate(wasmBuffer).then(wasmModule => {
  console.log(wasmModule.instance.exports);
  console.log(wasmModule.instance.exports.сума(2, 2));
});

