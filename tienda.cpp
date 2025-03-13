//
// Created by kevin on 12/03/2025.
//

#include "tienda.h"

// Constructor
tienda::tienda(std::vector<producto> productos, std::vector<cliente> clientes) {
  this->productos = productos;
  this->clientes = clientes;
}

// Getters
std::vector<producto> tienda::getProductos() {
  return productos;
}

std::vector<cliente> tienda::getClientes() {
  return clientes;
}

std::vector<venta> tienda::getVentas() {
  return ventas;
}

// Setters
void tienda::setProductos(std::vector<producto> productos) {
  this->productos = productos;
}

void tienda::setClientes(std::vector<cliente> clientes) {
  this->clientes = clientes;
}

// Métodos
void tienda::registrarCliente(cliente nuevoCliente) {
  clientes.push_back(nuevoCliente);
}

void tienda::agregarProducto(producto nuevoProducto) {
  productos.push_back(nuevoProducto);
}

void tienda::registrarVenta(venta nuevaVenta) {
  // Reducir el stock de los productos vendidos
  std::vector<producto> productosVendidos = nuevaVenta.getProductos();
  for (auto& productoVendido : productosVendidos) {
    for (auto& productoEnTienda : productos) {
      if (productoEnTienda.getid() == productoVendido.getid()) {
        productoEnTienda.actualizarStock(-1);  // Reducir el stock en 1
      }
    }
  }

  // Registrar la venta
  ventas.push_back(nuevaVenta);
}

std::vector<venta> tienda::consultarCompras(const cliente& cliente) {
  std::vector<venta> comprasCliente;

  for (int i = 0; i < ventas.size(); i++) {
    if (ventas[i].getCliente()->getId() == cliente.getId()) {
      comprasCliente.push_back(ventas[i]);
    }
  }

  return comprasCliente;
}
producto tienda::buscarProductoPorId(int id) {
    for (auto& producto : productos) {
        if (producto.getid() == id) {
            return producto;  // Retorna el producto si se encuentra
        }
    }
    return producto(-1, "", 0.0, 0);  // Retorna un producto inválido si no se encuentra
}
