interface Book {
    isbn: number,
    tittle: string
}

/**
 * Simula la carga remota de una lista de libros.
 * 
 * mook es crear datos falsos o de relleno
 */
function getFakeremoteData(): Promise<Book[]> {
    return new Promise((resolve, reject) => {
        let mookData: Book[] = [];
        mookData.push({
            isbn: 1,
            tittle: 'El Quijote'
        });
        mookData.push({
            isbn: 2,
            tittle: 'El Señor de los Anillos'
        });

        setTimeout(() => {
            resolve(mookData);
        }, 2000);
    });
}

async function cargaLibros() {
    //paso 1 indicar al cliente la carga
    let o = document.getElementById('contenedor');

    try {
        let libros : Book [] = await getFakeremoteData();
        if(o!=null)
        o.innerHTML = "Cargando...";
        document.getElementById('contenedor')!.innerHTML = "";
        let ui: string = '';
        libros.forEach((libro) => {
            ui += `<p>${libro.isbn}:${libro.tittle}</p>`;
        })
        document.getElementById('contenedor')!.innerHTML = ui;
    } catch (error) {
        document.getElementById('contenedor')!.innerHTML = "";
        alert('Error al Cargar');
    }
}