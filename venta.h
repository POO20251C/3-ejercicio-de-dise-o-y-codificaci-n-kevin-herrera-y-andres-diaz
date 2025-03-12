#ifndef VENTA_H
#define VENTA_H

#include <string>
#include <vector>
#include "producto.h"


class cliente;

class venta {
private:
  int id;
  cliente* clientePtr;
  std::vector<producto> productos;
  double total;

public:
  // Constructores
  venta() = default;
  venta(int id, cliente* clientePtr, std::vector<producto> productos, double total);

  // Getters
  int getId();
  cliente* getCliente();
  std::vector<producto> getProductos();
  double getTotal();

  // Setters
  void setId(int id);
  void setCliente(cliente* clientePtr);
  void setProductos(std::vector<producto> productos);
  void setTotal(double total);

  // Métodos
  void calcularTotal();
};

#endif // VENTA_H