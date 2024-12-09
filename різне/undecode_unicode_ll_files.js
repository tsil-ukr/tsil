const fs = require('fs');
const path = require('path');

const pathFromArgs = process.argv[2];

if (!pathFromArgs) {
    console.error('Path is not specified');
    process.exit(1);
}

const absolutePath = path.resolve(pathFromArgs);

if (!fs.existsSync(absolutePath)) {
    console.error('Path does not exist');
    process.exit(1);
}

undecodePath(absolutePath);

function undecodePath(path) {
    const stats = fs.statSync(path);
    if (stats.isDirectory()) {
        const files = fs.readdirSync(path);
        files.forEach(file => {
            const filePath = path + '/' + file;
            undecodePath(filePath);
        });
    } else {
        undecodeFile(path);
    }
}

function undecodeFile(path) {
    if (!path.endsWith('.ll')) {
        return;
    }
    console.log('Undecoding file:', path);
    const fileData = fs.readFileSync(path, 'utf8');
    const undecodedData = undecodeCode(fileData);
    fs.writeFileSync(path, undecodedData, 'utf8');
}

function undecodeCode(value) {
    const bytes = [];
    for (let i = 0; i < value.length; i++) {
        const char = value[i];
        if (char === '\\') {
            const byte = parseInt(value.substr(i + 1, 2), 16);
            if (byte === 0) {
                bytes.push('\\'.charCodeAt(0));
                bytes.push('0'.charCodeAt(0));
            } else {
                bytes.push(byte);
            }
            i += 2;
        } else {
            const charCode = char.charCodeAt(0);
            if (charCode > 127) {
                const utf8 = new TextEncoder().encode(char);
                bytes.push(...utf8);
            }
            if (charCode < 128) {
                bytes.push(charCode);
            }
        }
    }
    const text = new TextDecoder().decode(new Uint8Array(bytes));
    return text;
}