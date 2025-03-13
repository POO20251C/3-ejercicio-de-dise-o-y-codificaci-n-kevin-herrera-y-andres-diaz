//
// Created by kevin on 12/03/2025.
//

#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include "producto.h"
#include "cliente.h"
#include "venta.h"

class tienda {

private:
  std::vector<producto> productos;
  std::vector<cliente> clientes;
  std::vector<venta> ventas;

public:
  tienda() = default;
  tienda(std::vector<producto> productos, std::vector<cliente> clientes);

  // Getters
  std::vector<producto> getProductos();
  std::vector<cliente> getClientes();
  std::vector<venta> getVentas();

  // Setters
  void setProductos(std::vector<producto> productos);
  void setClientes(std::vector<cliente> clientes);

  // Métodos
  void registrarCliente(cliente nuevoCliente);
  void agregarProducto(producto nuevoProducto);
  void registrarVenta(venta nuevaVenta);
  std::vector<venta> consultarCompras(const cliente& cliente);
  producto buscarProductoPorId(int id);
};

#endif // TIENDA_H
