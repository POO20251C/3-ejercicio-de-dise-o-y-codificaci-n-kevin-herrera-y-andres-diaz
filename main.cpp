//
// Created by kevin on 12/03/2025.
//
#include <iostream>
#include "tienda.h"

int main() {
    // Crear productos
    producto p1(1, "Balon de Futbol", 50.0, 20);
    producto p2(2, "Raqueta de Tenis", 150.0, 10);
    producto p3(3, "Guantes de Boxeo", 40.0, 15);

    // Crear clientes
    cliente c1(1, "Kevin Herrera", {});
    cliente c2(2, "Andres Diaz", {});

    // Crear tienda y agregar productos
    tienda miTienda;
    miTienda.agregarProducto(p1);
    miTienda.agregarProducto(p2);
    miTienda.agregarProducto(p3);

    // Registrar clientes
    miTienda.registrarCliente(c1);
    miTienda.registrarCliente(c2);

    // Mostrar estado inicial de los productos
    std::cout << "Productos en la tienda :\n";
    std::vector<producto> listaProductosInicial = miTienda.getProductos();
    for (int i = 0; i < listaProductosInicial.size(); i++) {
        std::cout << "- " << listaProductosInicial[i].getnombre() << " - Stock: " << listaProductosInicial[i].getstock() << "\n";
    }

    // Registrar venta de Kevin
    std::vector<producto> compraKevin = {p1, p3};  // Compra un balón y unos guantes
    venta v1(101, &c1, compraKevin, 0);
    v1.calcularTotal();
    miTienda.registrarVenta(v1);

    // Registrar venta de Andres
    std::vector<producto> compraAndres = {p2};
    venta v2(102, &c2, compraAndres, 0);
    v2.calcularTotal();
    miTienda.registrarVenta(v2);

    // Consultar compras de Kevin
    std::vector<venta> comprasKevin = miTienda.consultarCompras(c1);
    std::cout << "\nCompras de " << c1.getNombre() << ":\n";
    for (int i = 0; i < comprasKevin.size(); i++) {
        std::cout << "- Venta ID: " << comprasKevin[i].getId() << " - Total: $" << comprasKevin[i].getTotal() << "\n";
    }

    // Consultar compras de Andres
    std::vector<venta> comprasAndres = miTienda.consultarCompras(c2);
    std::cout << "\nCompras de " << c2.getNombre() << ":\n";
    for (int i = 0; i < comprasAndres.size(); i++) {
        std::cout << "- Venta ID: " << comprasAndres[i].getId() << " - Total: $" << comprasAndres[i].getTotal() << "\n";
    }

    // Mostrar estado final de los productos
    std::cout << "\nProductos en la tienda (ACTUALIZADOS):\n";
    std::vector<producto> listaProductosFinal = miTienda.getProductos();
    for (int i = 0; i < listaProductosFinal.size(); i++) {
        std::cout << "- " << listaProductosFinal[i].getnombre() << " - Stock: " << listaProductosFinal[i].getstock() << "\n";
    }

    return 0;
}