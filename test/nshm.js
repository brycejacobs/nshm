var nshm = require('../build/Release/nshm');

var shmId = nshm.open(0xCBA5FFF0, 'a', 0x1000, 0660);

console.log('Shared Memory Id: %d', shmId);

function readSHM (){
    nshm.read(shmId);
}

var attempts = 10;
while (attempts){

    setTimeout(function (){
        readSHM();
        attempts--;
    }, 500)
}


