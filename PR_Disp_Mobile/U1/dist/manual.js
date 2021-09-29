"use strict";
var variable = 3;
var variable2 = true;
var variable3 = "Hola";
var Color;
(function (Color) {
    Color[Color["Red"] = 0] = "Red";
    Color[Color["Green"] = 1] = "Green";
    Color[Color["Blue"] = 2] = "Blue";
})(Color || (Color = {}));
var c = Color.Red;
//ARRAYS
var list = [1, 2, 3]; // New Array ()
// let list:Array <number> = [];
for (var _i = 0, list_1 = list; _i < list_1.length; _i++) {
    var numero = list_1[_i];
    // Muestra el contenido
    console.log(numero);
}
for (var numero in list) {
    // Muestra la posición
    console.log(numero);
}
list.forEach(function (n) {
    // Muestra el contenido
    console.log(n);
});
list.push;
list.shift;
list.pop;
list.indexOf;
//Ordenar Array
var contacs = ["Maria", "Pedro", " Ana"];
console.log(contacs.sort());
//Coger Array y pasarlo a String
console.log(contacs.join(","));
//Al reves
var frase = "Hola como estas";
var resultado = frase.split(" ");
console.log(resultado);
var myExpression = /[0-9]+/gi;
var frase2 = "123";
console.log(myExpression.exec(frase2));
var listaContactos = ["Ana", "Carlos", "Federico"];
var filtrado = listaContactos.filter(function (v) {
    if (v.length > 4) {
        return v;
    }
});
console.log(filtrado);
var filtrado2 = listaContactos.filter(function (v) { return v.length > 4; });
var x = listaContactos.map(function (v) { return v.toUpperCase(); });
