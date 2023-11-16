/*
 * File:	cargable.h
 * Date:	march 2023
 * Comms:	Fichero cargable.h de la práctica 3 de la asignatura
 * 		de Tecnología de Programación.
 */
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/*
 * Clase que representa cualquier objeto cargable en un contenedor determinado.
 */
class Cargable {
protected:
    string nom;
    double vol, pes;
public:
    Cargable(const string& _nom, double _vol, double _pes);
    ~Cargable();

    virtual string nombre() const;
    virtual double volumen() const;
    virtual double peso() const;

    virtual string tipo() const = 0;
    virtual string to_string() const;
    
    friend ostream& operator<<(ostream& f, const Cargable& c);
};

/*
 * Clase que representa un ser vivo
 */
class SerVivo : public Cargable {
public:
    SerVivo(const string& _nom, double _vol, double _pes);
    string tipo() const override;
};

/*
 * Clase que representa un producto tóxico
 */
class Toxico : public Cargable {
public:
    Toxico(const string& _nom, double _vol, double _pes);
    string tipo() const override;
};
