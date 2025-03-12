//
// Created by kevin on 12/03/2025.
//
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>


class venta;

class cliente {
private:
  int id;
  std::string nombre;
  std::vector<venta> compras;

public:
  // Constructor
  cliente() = default;
  cliente(int id, std::string nombre, std::vector<venta> compras);

  // Getters
  int getId() const;
  std::string getNombre();
  std::vector<venta> getCompras();

  // Setters
  void setId(int id);
  void setNombre(std::string nombre);
  void setCompras(std::vector<venta> compras);
};

#endif // CLIENTE_H
