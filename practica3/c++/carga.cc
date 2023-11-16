/*
 * File:	carga.cc
 * Date:	march 2023
 * Comms:	Fichero carga.cc de la práctica 3 de la asignatura
 * 		de Tecnología de Programación.
 */
#include "carga.h"
using namespace std;

/*
 * Constructor de la clase Carga.
 */
Carga::Carga(const string& _nom, double _vol, double _pes)
    : Cargable(_nom,_vol,_pes){}

/*
 * Pre:  ---
 * Post: Devuelve un string con el tipo de Carga del objeto.
 */
string Carga::tipo() const {
    return "de Carga Estandar";
}

/*
 * Constructor de la clase Producto.
 */
Producto::Producto(const string& _nom, double _vol, double _pes)
    : Carga(_nom,_vol,_pes) {}


/*
 * Pre: ---
 * Post: Devuelve el nombre del producto, su volumen (en m3) y su peso (en kg).
 */
string Producto::to_string() const {
    stringstream str;
    str << "   " << nom << " [" << setprecision(4) << volumen() << " m3] ["
        << setprecision(4) << peso() << " kg]\n";
    return str.str();
}
