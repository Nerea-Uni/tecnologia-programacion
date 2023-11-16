/*
 * File:	almacen.h
 * Date:	march 2023
 * Comms:	Fichero almacen.h de la práctica 3 de la asignatura
 * 		de Tecnología de Programación.
 */
#pragma once
#include <vector>
#include <iomanip>
#include "carga.h"
using namespace std;


template<typename T>
class Almacen {
protected:
    string nom;
    double cap;     //capacidad del almacen
    double vol;     //volumen ocupado
    vector<T*> elementos;
public:

    /*
     * Constructor de la clase Almacen.
     */
    Almacen(double _c)  : cap(_c), vol(0.0) {}

    /* 
     * Destructor de la clase Almacen.
     */
    virtual ~Almacen() {
        elementos.clear();
    }

    /*
     * Pre: ---
     * Post: Devuelve la capacidad del almacen .
     */
    double capacidad() const {   return cap; }
    
    /*
     * Pre: ---
     * Post: Devuelve el peso del objeto Almacen.
     */
    double peso() const {
        double peso = 0;
        for (auto ele : this->elementos){
            peso += ele->peso();
        }
        return peso;
    }
    
    /*
     * Pre: ---
     * Post: Muestra la capacidad en m3 y el peso en kg del Almacen.
     */
    virtual string to_string() const {
        stringstream str;
        str << nom << " [" << setprecision(4) << this->capacidad() << " m3] ["
            << setprecision(4) << peso() << " kg]\n";
        return str.str();
    }

    /*
     * Pre: ---
     * Post: Guarda un elemento en el almacén si hay capacidad libre suficiente,
     *       si es así, devuelve true. En caso contrario, devuelve false.
     */
    bool guardar(T* elem) {
        if(elem->volumen() <= (cap - vol)) {
            //Si cabe, lo deposito dentro del almacén (camión o contenedor)
            vol += elem->volumen();
            this->elementos.push_back(elem);
            return true;
        }
        return false;
    }
};

/*
 * Clase que representa un contenedor
 */
template<typename T>
class Contenedor : public Almacen<T>, public Carga {
public:
    /*
     * Constructor de la clase Contenedor.
     */
    Contenedor(double _cap) : Almacen<T>(_cap), Carga("Contenedor", _cap, 0.0) {}

    /*
     * Pre: ---
     * Post: Devuelve el peso total del Contenedor.
     */
    double peso() const {
        return Almacen<T>::peso();
    }

    /*
     * Pre: ---
     * Post: Devuelve el nombre del contenedor, su volumen (en m3), su peso (en kg) y 
     *       el tipo de los productos contenidos en él.
     */
    string to_string() const override{
        stringstream str;
        str <<" " <<nom << " [" << setprecision(4) << this->capacidad() << " m3] ["
            << setprecision(4) << peso() << " kg]" << this->elementos.front()->tipo() << "\n";
        for (auto i : Almacen<T>::elementos){
            str << "  " << i->to_string();
        }
        return str.str();
    }
};

/*
 * Clase que representa un camión
 */
class Camion : public Almacen<Carga> {
private:
    double pes;
public:
    Camion(double _cap);
    double peso() const;
    string to_string() const override;
    friend ostream& operator<<(ostream& f, const Camion& c); 
};
