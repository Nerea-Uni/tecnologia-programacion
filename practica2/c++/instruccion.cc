/*
 * File:	instruccion.cc
 * Date:	march 2023
 * Comms:	Fichero instruccion.cc de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
#include "instruccion.h"
  
Instruccion::Instruccion()
{
}

string Instruccion::nombre()
{
    return "";
}

void Instruccion::ejecutar(stack<int>& pila, int& pc) const
{    
}

// ---------------------------- READ -------------------------
Read::Read()
{
}

void Read::ejecutar(stack<int>& pila, int& pc) const
{    
    cout << "? ";
    int num;
    cin >> num;
    pila.push(num);
};

string Read::nombre(){
   return "read";
}


// ---------------------------- WRITE -------------------------
Write::Write()
{
}

void Write::ejecutar(stack<int>& pila, int& pc) const
{
    int num = pila.top();
    pila.pop();
    cout << num << endl;
}

string Write::nombre(){
    return "write";
}


// ---------------------------- ADD -------------------------
Add::Add()
{
}

void Add::ejecutar(stack<int>& pila, int& pc) const
{
   int a = pila.top(); //Guardo el primer sumando
   pila.pop(); //Desapilo primer sumando
   int b = pila.top();  //Guardo segundo sumando
   pila.pop(); //Desapilo segundo sumando
   pila.push(a+b);   //apilo el resultado de la suma

}

string Add::nombre(){
   return "add";
}


// ---------------------------- DUP -------------------------
Dup::Dup()
{
}

void Dup::ejecutar(stack<int>& pila, int& pc) const
{    
    int num = pila.top();
    pila.pop();
    pila.push(num);
    pila.push(num);
};

string Dup::nombre(){
   return "dup";
}


// ---------------------------- PUSH -------------------------
Push::Push(int atri) 
    : atributo(atri)
{
}

void Push::ejecutar(stack<int>& pila, int& pc) const
{
    pila.push(atributo);
};

string Push::nombre(){
   return "push";
}


// ---------------------------- JUMPIF -------------------------
Jumpif::Jumpif(int atri) 
    : atributo(atri)
{
}

void Jumpif::ejecutar(stack<int>& pila, int& pc) const
{
    int num = pila.top();
    pila.pop();
    if (num >= 0) {
        pc = atributo-1;
    }
};

string Jumpif::nombre(){
   return "jumpif " + to_string(atributo);
}


// ---------------------------- OVER -------------------------
Over::Over()
{
}

void Over::ejecutar(stack<int>& pila, int& pc) const
{
    int num1 = pila.top();
    pila.pop();
    int num2 = pila.top();
    pila.pop();
    pila.push(num2);
    pila.push(num1);
    pila.push(num2);
}

string Over::nombre(){
   return "over";
}


// ---------------------------- SWAP -------------------------
Swap::Swap()
{
}

void Swap::ejecutar(stack<int>& pila, int& pc) const
{    
    int num1 = pila.top();
    pila.pop();
    int num2 = pila.top();
    pila.pop();
    pila.push(num1);
    pila.push(num2);
}

string Swap::nombre(){
   return "swap";
}


// ---------------------------- MUL -------------------------
Mul::Mul()
{
}

void Mul::ejecutar(stack<int>& pila, int& pc) const
{
    int num1 = pila.top();
    pila.pop();
    int num2 = pila.top();
    pila.pop();
    pila.push(num1*num2);
}

string Mul::nombre(){
   return "mul";
}

