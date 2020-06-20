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

    const char* value = "mahdi";
    auto functionName = "simpleReturn";

    void Method(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(
        isolate, value, NewStringType::kNormal).ToLocalChecked());
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, functionName, Method);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}


