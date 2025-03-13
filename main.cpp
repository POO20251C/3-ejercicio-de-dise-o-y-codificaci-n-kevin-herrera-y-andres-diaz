//
// Created by kevin on 12/03/2025.
//
#include <iostream>
#include "tienda.h"

int main() {
    // Crear productos iniciales
    producto p1(1, "Balon de Fútbol", 50.0, 20);
    producto p2(2, "Raqueta de Tenis", 150.0, 10);
    producto p3(3, "Guantes de Boxeo", 40.0, 15);

    // Crear tienda y agregar productos
    tienda miTienda;
    miTienda.agregarProducto(p1);
    miTienda.agregarProducto(p2);
    miTienda.agregarProducto(p3);

    // Registrar clientes
    cliente c1(1, "Kevin Herrera", {});
    cliente c2(2, "Andres Diaz", {});
    miTienda.registrarCliente(c1);
    miTienda.registrarCliente(c2);

    // Registrar compra de Kevin
    std::vector<producto> compraKevin;
    producto producto1 = miTienda.buscarProductoPorId(1);  // Balón de Fútbol
    producto producto3 = miTienda.buscarProductoPorId(3);  // Guantes de Boxeo

    if (producto1.getid() != -1 && producto3.getid() != -1) {  // Validar que los productos existen
        if (producto1.getstock() > 0 && producto3.getstock() > 0) {  // Validar que hay stock
            compraKevin.push_back(producto1);
            compraKevin.push_back(producto3);
            venta v1(101, &c1, compraKevin, 0);
            v1.calcularTotal();
            miTienda.registrarVenta(v1);
            std::cout << "\nCompra de Kevin registrada con éxito.\n";
        } else {
            std::cout << "\nError: No hay suficiente stock para algunos productos.\n";
        }
    } else {
        std::cout << "\nError: Algunos productos no existen.\n";
    }

    // Registrar compra de Andres
    std::vector<producto> compraAndres;
    producto producto2 = miTienda.buscarProductoPorId(2);  // Raqueta de Tenis

    if (producto2.getid() != -1) {  // Validar que el producto existe
        if (producto2.getstock() > 0) {  // Validar que hay stock
            compraAndres.push_back(producto2);
            venta v2(102, &c2, compraAndres, 0);
            v2.calcularTotal();
            miTienda.registrarVenta(v2);
            std::cout << "\nCompra de Andres registrada con éxito.\n";
        } else {
            std::cout << "\nError: No hay suficiente stock para el producto.\n";
        }
    } else {
        std::cout << "\nError: El producto no existe.\n";
    }

    // Consultar kevin
    std::vector<venta> comprasKevin = miTienda.consultarCompras(c1);
    std::cout << "\nCompras de " << c1.getNombre() << ":\n";
    for (int i = 0; i < comprasKevin.size(); i++) {
        std::cout << "- Venta ID: " << comprasKevin[i].getId() << "\n";
        std::vector<producto> productosComprados = comprasKevin[i].getProductos();
        for (int j = 0; j < productosComprados.size(); j++) {
            std::cout << "  - " << productosComprados[j].getnombre() << "\n";
        }
    }

    // Consultar Andres
    std::vector<venta> comprasAndres = miTienda.consultarCompras(c2);
    std::cout << "\nCompras de " << c2.getNombre() << ":\n";
    for (int i = 0; i < comprasAndres.size(); i++) {
        std::cout << "- Venta ID: " << comprasAndres[i].getId() << "\n";
        std::vector<producto> productosComprados = comprasAndres[i].getProductos();
        for (int j = 0; j < productosComprados.size(); j++) {
            std::cout << "  - " << productosComprados[j].getnombre() << "\n";
        }
    }

    // Mostrar listado de productos después de las compras
    std::cout << "\nProductos en la tienda (después de las compras):\n";
    std::vector<producto> listaProductos = miTienda.getProductos();
    for (int i = 0; i < listaProductos.size(); i++) {
        std::cout << "- " << listaProductos[i].getnombre() << " - Stock: " << listaProductos[i].getstock() << "\n";
    }

    return 0;
}
