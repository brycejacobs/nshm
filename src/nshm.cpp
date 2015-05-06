#include <nan.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <v8.h>
#include <node.h>

using namespace v8;
/**
 * Open a shared memory regment and return shmid
 */
NAN_METHOD (Open){
    NanScope();

    if (args.Length() < 4){
        NanThrowTypeError("Wrong Number of Arguments");
        NanReturnUndefined();
    }

    char *flags = *(String::Utf8Value(args[1]->ToString()));

    int shm_key = args[0]->Int32Value();
    int shm_size = args[2]->Int32Value();
    int shm_mode = args[3]->Int32Value();
    

    int shmId = shmget(shm_key, shm_size, shm_mode);
    NanReturnValue(shmId);
}

void Initialize(v8::Handle<Object> exports) {
      
  exports->Set(NanNew<String>("open"),
      NanNew<FunctionTemplate>(Open)->GetFunction());
  
  // exports->Set(NanNew<String>("read"),
  //     NanNew<FunctionTemplate>(Read)->GetFunction());

  // exports->Set(NanNew<String>("write"),
  //     NanNew<FunctionTemplate>(Write)->GetFunction());
}

NODE_MODULE(nshm, Initialize)