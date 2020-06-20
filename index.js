let { orginalV8Object } = require('./build/Release/v8Object');
let { simpleReturn } = require('./build/Release/simpleReturn');
console.log('=====================')
console.log(orginalV8Object())
console.log(simpleReturn())
console.log('=====================')