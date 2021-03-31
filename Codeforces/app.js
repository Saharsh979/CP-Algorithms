const EventEmit =  require('events');
const emitter = new EventEmit();

emitter.on('messageLogged', function(){
    console.log('Listener called');
});
 emitter.emit('messageLogged');  