//
// Created by kevin on 12/03/2025.
//

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class producto {
public:
    // Constructor
    producto() = default;
    producto(int id, std::string nombre, double precio, int stock);

    // Getters
    int getid();
    std::string getnombre();
    double getprecio();
    int getstock();

    // Setters
    void setid(int id);
    void setnombre(std::string nombre);
    void setprecio(double precio);
    void setstock(int stock);

    //Metodos
    void actualizarStock(int cantidad);

private:
    int id{};
    std::string nombre{};
    double precio{};
    int stock{};
};

#endif //PRODUCTO_H
