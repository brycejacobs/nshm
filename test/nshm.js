var nshm = require('../build/Release/nshm');

var shmId = nshm.open(0xCBA5FFF0, 'a', 0x1000, 0660);

console.log('Shared Memory Id: %d', shmId);

var attempts = 20;
function readSHM(){
    while (attempts){
        console.log('Attempting Read');
        console.log(nshm.read(shmId));
        setTimeout(function (){
            attempts--;
            readSHM();
        }, 500)
    }
}

readSHM();

