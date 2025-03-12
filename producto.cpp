//
// Created by kevin on 12/03/2025.
//

#include "producto.h"
#include <iostream>

// Constructor
producto::producto(int id, std::string nombre, double precio, int stock) {
  this->id = id;
  this->nombre = nombre;
  this->precio = precio;
  this->stock = stock;
}

// Getters
double producto::getprecio() {
  return precio;
}

int producto::getstock() {
  return stock;
}

int producto::getid() {
  return id;
}

std::string producto::getnombre() {
  return nombre;
}

// Setters
void producto::setprecio(double precio) {
  this->precio = precio;
}

void producto::setstock(int stock) {
  this->stock = stock;
}

void producto::setnombre(std::string nombre) {
  this->nombre = std::move(nombre);
}

void producto::setid(int id) {
  this->id = id;
}

// Implementación
void producto::actualizarStock(int cantidad) {
  this->stock += cantidad;
  if (this->stock < 0) {
    this->stock = 0;
  }
}
