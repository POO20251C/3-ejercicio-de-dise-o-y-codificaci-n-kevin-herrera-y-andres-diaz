//
// Created by kevin on 12/03/2025.
//

#include "cliente.h"
#include "venta.h"

// Constructor
cliente::cliente(int id, std::string nombre, std::vector<venta> compras) {
  this->id = id;
  this->nombre = nombre;
  this->compras = compras;
}

// Getters
int cliente::getId() const{
  return id;
}

std::string cliente::getNombre() {
  return nombre;
}

std::vector<venta> cliente::getCompras() {
  return compras;
}

// Setters
void cliente::setId(int id) {
  this->id = id;
}

void cliente::setNombre(std::string nombre) {
  this->nombre = nombre;
}

void cliente::setCompras(std::vector<venta> compras) {
  this->compras = compras;
}
