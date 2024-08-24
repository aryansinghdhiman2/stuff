// let radius = 3
// const pi = 3.14
// console.log(pi)
// console.log(`Area of circle with radius ${radius} is ${(pi*radius*radius)}`)

// let vari=null
// console.log(vari==null)

// console.log(typeof(pi))

// console.log({}+{}+{})

// console.log({}+{})

// let x,y=5
// console.log(x)
// console.log(y)

// var check = 'a';
// switch(check){
//     case 'A':console.log('Lower and Uppercase letters are same for JavaScript');              
//     case 'a':console.log('Lower and Uppercase letters are different for JavaScript');                
//     default:console.log('Lower and Uppercase letters cannot be compared in JavaScript');            
// }
// let addValues = (a=30,b) => a+b;
// console.log(addValues(35));
// function sayHello(x, y) {
//     console.log('Hello' + ' ' + x[1]);
// }
// sayHello(['Heena', 'Rita']);
// class Person {
// 	constructor(name, age) {
// 		this._pname = name;
// 		this._page = age;
// 	}
// 	display() {

// 		console.log("name :" + this.pname);
// 		console.log("age :" + this.page);
// 	}
// 	set pname(namePerson) { this._pname = namePerson; }
// 	get pname() { return this._pname; }
// }
// let per = new Person();              // line 8
// per.pname = "Rexha";                 // line 9
// console.log(per.pname);              // line 10
// let per1 = new Person("Alex", 10);   // line 11
// console.log(per1.pname);    
// let companies= ["C1", "C2", "C3", "C4"];  
// companies.splice(2, 0, "C5");  
// console.log(companies); 
// new Promise(function (resolve, reject) {
// 	let b;
// 	setTimeout(compute = (a) => resolve(a + b), 10000);
// 	b = 25;
// }).then(function (data) { console.log(data); });
// compute(5);
// function func1() {
//     console.log("Am in func1");
// }
// function func2() {
//     console.log("Am in func2");
// }
// for (var i = 0; i < 2; i++) {
//     setTimeout(function() {
//         console.log("setTimeout message");
//         func1();
//     }, );
//     func2();
// }

// async function foo(){
//     return {a:1};
// }

// async function another(){
//     let j = foo()
//     let k = await j;
//     console.log(k.a)
// }

// another()

var myPromise = new Promise(function (resolve, reject) {
	setTimeout(function () {
		resolve("success");
	}, 2000);
});
myPromise.then(
	function (data) {
		console.log(data + " received in 2 seconds");
	},
	function (error) {
		console.log(error);
	}
);
var count=0;
// let pr = new Promise((resolve)=>{
//     var t=setInterval(()=>{
//         count++;
//         if(count===5){
//             clearInterval(t)
//         }
//         resolve(Math.random()*1000);
//     },2000)
// })

// pr.then(x=>console.log(x))
// setTimeout(()=>{
//     pr.then(x=>console.log(x))
// },3000)