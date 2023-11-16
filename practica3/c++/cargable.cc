/*
 * File:	cargable.cc
 * Date:	march 2023
 * Comms:	Fichero cargable.cc de la práctica 3 de la asignatura
 * 		de Tecnología de Programación.
 */
#include "cargable.h"

using namespace std;

/*
 * Constructor de la clase Cargable.
 */
Cargable::Cargable(const string& _nom, double _vol, double _pes)
    : nom(_nom), vol(_vol), pes(_pes) {}

/*
 * Destructor de la clase Cargable.
 */
Cargable::~Cargable() {}

/*
 * Pre: ---
 * Post: Devuelve el nombre del objeto Cargable.
 */
string Cargable::nombre() const{
    return this->nom;
}

/*
 * Pre: ---
 * Post: Devuelve el volumen del objeto Cargable.
 */
double Cargable::volumen() const {
    return this->vol;
}

/*
 * Pre: ---
 * Post: Devuelve el peso del objeto Cargable.
 */
double Cargable::peso() const {
    return this->pes;
}


/*
 * Pre: ---
 * Post: Muestra el volumen en m3 y el peso en kg del objeto Cargable.
 */
string Cargable::to_string() const {
    stringstream ss;
    ss << "   " << nom << " [" << setprecision(4) << this->volumen() << " m3] ["
        << setprecision(4) << this->peso() << " kg]" << "\n";
    return ss.str();
}

/*
 * Operador de inserción para la clase Cargable
 */
ostream& operator<<(ostream& f, const Cargable& c) {
    f << c.to_string();
    return f;
}

/*
 * Constructor de la clase SerVivo.
 */
SerVivo::SerVivo(const string& _nom, double _vol, double _pes)
    : Cargable(_nom,_vol,_pes) {}


/*
 * Muestra el tipo de carga en los contenedores de seres vivos.
 */
string SerVivo::tipo() const {
    return "de Seres Vivos";
}

/*
 * Constructor de la clase Toxico.
 */
Toxico::Toxico(const string& _nom, double _vol, double _pes)
    : Cargable(_nom,_vol,_pes) {}

/*
 * Muestra el tipo de carga en los contenedores de toxicos.
 */
string Toxico::tipo() const {
    return "de Productos Toxicos";
}
