//
// Created by kevin on 12/03/2025.
//
#include "venta.h"
#include "cliente.h"

// Constructor
venta::venta(int id, cliente* clientePtr, std::vector<producto> productos, double total) {
  this->id = id;
  this->clientePtr = clientePtr;
  this->productos = productos;
  this->total = total;
}

// Getters
int venta::getId() {
  return id;
}

cliente* venta::getCliente() {
  return clientePtr;
}

std::vector<producto> venta::getProductos() {
  return productos;
}

double venta::getTotal() {
  return total;
}

// Setters
void venta::setId(int id) {
  this->id = id;
}

void venta::setCliente(cliente* clientePtr) {
  this->clientePtr = clientePtr;
}

void venta::setTotal(double total) {
  this->total = total;
}

void venta::setProductos(std::vector<producto> productos) {
  this->productos = productos;
}

// Implementación
void venta::calcularTotal() {
  total = 0.0;
  for (int i = 0; i < productos.size(); i++) {
    total += productos[i].getprecio();
  }
}