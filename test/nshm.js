var nshm = require('../build/Release/nshm');

console.log(nshm.open(0xCBA5FFF0, 'a', 0x1000, 0660));