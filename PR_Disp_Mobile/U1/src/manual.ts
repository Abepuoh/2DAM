let variable: number = 3;
let variable2: boolean = true;
let variable3: string = "Hola";

enum Color {
  Red,
  Green,
  Blue,
}
let c: Color = Color.Red;

//ARRAYS
let list: number[] = [1, 2, 3]; // New Array ()
// let list:Array <number> = [];

for (let numero of list) {
  // Muestra el contenido
  console.log(numero);
}

for (let numero in list) {
  // Muestra la posición
  console.log(numero);
}

list.forEach((n) => {
  // Muestra el contenido
  console.log(n);
});

list.push;
list.shift;
list.pop;
list.indexOf;

//Ordenar Array
let contacs: string[] = ["Maria", "Pedro", " Ana"];
console.log(contacs.sort());

//Coger Array y pasarlo a String
console.log(contacs.join(","));
//Al reves
let frase: string = "Hola como estas";
let resultado: Array<string> = frase.split(" ");
console.log(resultado);

let myExpression: RegExp = /[0-9]+/gi;
let frase2: string = "123";

console.log(myExpression.exec(frase2));

let listaContactos: string[] = ["Ana", "Carlos", "Federico"];
let filtrado: string[] = listaContactos.filter((v) => {
  if (v.length > 4) {
    return v;
  }
});

console.log(filtrado);

let filtrado2: string[] = listaContactos.filter((v) => v.length > 4);

let x = listaContactos.map((v) => v.toUpperCase());

interface Contacto {
  nombre: string;
  phone: string;
  address?: string;
  edad: number | string;
}

let listaca: Contacto[] = [];

let c1: Contacto = {
  nombre: "Michael",
  phone: "Scott",
  edad: 14
};

c1.nombre = "Nombre";

listaca.push(c1);

listaca.push({
  nombre: "Olga",
  phone: "Scott",
  edad: 13
});
