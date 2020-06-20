#include <node.h>
#include <iostream>
#include <string>

namespace demo {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::NewStringType;
    using v8::Object;
    using v8::String;
    using v8::Value;

    const char* value = "userOneName";
    auto functionName = "orginalV8Object";

    void Method(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        v8::Local<v8::Object> temp = v8::Object::New(isolate);
        temp->Set(
            isolate->GetCurrentContext(),
            v8::String::NewFromUtf8(isolate, "name"),
            v8::String::NewFromUtf8(isolate, value)
        );
        args.GetReturnValue().Set(temp);
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, functionName, Method);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}


