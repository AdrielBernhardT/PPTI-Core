let a = 'a'
let b = 1
var c = 2.1

let d = [1, 2, 3, "string", 'a', true]

console.log(a,b,c,d)

if(a == 'a'){
    
} else if(a == b){
    
} else {
    
}

switch(a){
    case 'B':
        console.log('value of a is B')
        break
    case 'C':
        break
    default:
        console.log('ndatau')
}

// Loop
while(true){
    break;
}

for(let i = 0; i < 10; i++){
    console.log(i)
}

function printSomething(text, callback){
    console.log(text)
    callback()
}

const someFunction = () => {
    console.log("This is a function")
}

printSomething('This is a text', someFunction)
someFunction();
printSomething('text', () => {
    console.log('This is a callback function 1')
})

printSomething('text', () => {
    console.log('This is a callback function 2')
})