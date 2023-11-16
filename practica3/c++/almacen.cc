/*
 * File:	almacen.cc
 * Date:	march 2023
 * Comms:	Fichero almacen.cc de la práctica 3 de la asignatura
 * 		de Tecnología de Programación.
 */
#include "almacen.h"
using namespace std;

/* 
 * Constructor de la clase Camion.
 */
Camion::Camion(double _cap)
    : Almacen<Carga>(_cap) {}


/*
 * Pre: ---
 * Post: Devuelve el nombre del objeto cargable, su capacidad (en m3) y su peso (en kg).
 */
string Camion::to_string() const {
    stringstream str;
    str << "Camion" << " [" << setprecision(4) << capacidad() << " m3] ["
        << setprecision(4) << peso() << " kg]\n";
    for (auto i : Almacen::elementos){
        str << "  " << i->to_string();
    }
    return str.str();
}

/*
 * Pre: ---
 * Post: Devuelve el peso total del Camión.
 */
double Camion::peso() const {
    return Almacen<Carga>::peso();
}

/*
 * Operador de inserción para la clase Camión.
 */
ostream& operator<<(ostream& f, const Camion& c) {
    f << c.to_string();
    return f;
}

