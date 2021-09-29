/**
 PRODUCTOS DE CADA CLIENTES.
 */
SELECT
    prov.nombre AS proveedor,
    count (cod) AS productos
FROM
    producto AS p,
    proveedor AS prov
WHERE
    p.id_proveedor = prov.id gruop BY prov.id
    /**
     PRODUCTOS DE CADA CLIENTES AUNQUE NO TENGA.
     */
SELECT
    prov.nombre AS PROVEEDOR,
    count (cod) AS PRODUCTOS
FROM
    producto p
    RIGHT JOIN proveedor prov ON p.id_proveedor = prov.id
GROUP BY
    prov.id
    /**
     lISTADO DE TODAS LAS VENTAS (QUIEN CON DNI Y NOMBRE, EL QUE Y A QUIEN)
     */
SELECT
    c.dni AS DNI,
    c.nombre AS NOMBRE,
    p.nombre AS PRODUCTO,
    prov.nombre AS PROVEEDOR
FROM
    cliente - producto as compras
    JOIN cliente as C ON compras.id_cliente = c.id_Cliente
    JOIN producto as p ON compras.id_producto = p.cod
    JOIN proveedor as prov ON p.id_proveedor = prov.id_Proveedor
    /**
     CUANTO DINERO SE HA GASTADO CADA CLIENTE
     */
SELECT
    c.nombre AS NOMBRE_CLIENTE,
    SUM(p.precio) AS DINERO_GASTADO
FROM
    cliente - producto AS cp
    JOIN cliente AS c ON cp.id_cliente = c.id_Cliente
    JOIN producto AS p ON cp.id_producto = p.cod
GROUP BY
    c.id_Cliente
    /**
     GASTO DE CLIENTE AUNQUE NO TENGA PRODUCTOS.
     */
SELECT
    c.nombre AS NOMBRE_CLIENTE,
    IFNULL(SUM(p.precio), 0) AS DINERO_GASTADO
FROM
    cliente AS c
    LEFT JOIN cliente - producto AS cp ON cp.id_cliente = c.id_Cliente
    LEFT JOIN producto AS p ON cp.id_producto = p.cod
GROUP BY
    c.id_Cliente
    /**
     ORDENAR LOS CLIENTES QUE HAN GASTADO MAS Y QUE HAN GASTADO MENOS
     */
SELECT
    c.nombre SUM(p.precio) AS DINERO_GASTADO
FROM
    cliente AS c
    LEFT JOIN cliente - producto AS cp ON cp.id_cliente = c.id_Cliente
    LEFT JOIN producto AS p ON cp.id_producto = p.cod
GROUP BY
    c.id_Cliente
ORDER BY
    DINERO_GASTADO ASC
    /** 
     MOSTRAR LOS NOMBRES CON MAS DE 4 LETRAS
     */
SELECT
    c.nombre SUM(p.precio) AS DINERO_GASTADO
FROM
    cliente AS c
    LEFT JOIN cliente - producto AS cp ON cp.id_cliente = c.id_Cliente
    LEFT JOIN producto AS p ON cp.id_producto = p.cod
GROUP BY
    c.id_Cliente
HAVING
    LENGTH (c.nombre > 4)
ORDER BY
    DINERO_GASTADO ASC
    /*Las sedes olímpicas se dividen en complejos deportivos. Los complejos deportivos se subdivide en aquellos que 
     se desarrolla un unico deporte y en los polideportivos. Los complejos polideportivos tienen areas designadas para 
     cada deporte con un indicador de localización (ejemplo: centro, esquina-NE,etc.) Un complejo tiene una localización,
     un jefe de orgacizacion individual y un area total ocupada. Los dos tipos de complejos(deporte unico y polideportivo) tendrán 
     diferentes tipos de información. Para cada tipo de sede, se conservará el numero de complejos junto con su presupuesto aproximado.
     Cada complejo celebra una serie de eventos (ejemplo: la pista del estadio puede celebrar muchas carreras distintas).
     Para cada evento está prevista una fecha, duración, numero de participantes, numero de comisarios. Una lista de todos 
     los comisarios se conservará junto con la lista de los eventos en los que esté involucrado cada comisario ya sea cumpliendo 
     la tarea de juez u observador. Tanto para cada evento como para el mantenimiento se necesitará cierto equipamiento
     (ejemplo: arcos, pértigas, barras paralelas, etc). */
    /* Cuantos eventos hay en las sedes de Córdoba*/
SELECT
    nombre ev
FROM
    evento ev
    JOIN area AS ar ON ev.id_area = ar.id
    JOIN complejo AS co ON ar.id_complejo = co.id
    JOIN sede AS se ON co.id_sede = se.id
WHERE
    se.id = 1;

/*1ª PREGUNTA*/
SELECT co.nombre AS NOMBRE, COUNT(*) AS n_JUEZ
FROM comisario as co
LEFT JOIN evento_comisario as ec ON co.id = ec.id_comisario
JOIN evento as e ON ec.id_evento = e.id
WHERE ec.rol = 1
GROUP BY co.id;

/*2º PREGUNTA*/
SELECT ev.nombre AS Evento_Realizado
FROM evento AS ev
WHERE ev.fecha <= NOW()

/* 3ª PREGUNTA */
SELECT co.nombre AS NOMBRE, ar.area AS AREA_TOTAL
FROM complejo AS co
JOIN area AS ar ON ar.id_complejo = co.id
GROUP BY co.id
ORDER BY SUM(ar.area)


/* 4ª PREGUNTA*/
SELECT co.nombre AS NOMBRE, COUNT(ev.id) AS N_Eventos
FROM complejo AS co
JOIN area AS ar ON co.id = ar.id_complejo
JOIN evento AS ev ON ar.id = ev.id_area
WHERE co.tipo = 1 
GROUP BY co.id
ORDER BY COUNT(ev.id) DESC

