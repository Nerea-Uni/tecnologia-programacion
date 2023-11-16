/*
 * File:    Directorio.java
 * Date:    april 2023
 * Comms:   Fichero Directorio.java de la práctica 4 de la asignatura
 * 			de Tecnología de Programación.
 */
import java.util.*;

public class Directorio extends Nodo {  
    private Map<String, Nodo> contenido;

    public Directorio(String name) {
        super(name);
        this.contenido = new HashMap<>();
    }

    // Devuelve el tamaño de un directorio
    public int tamagno() {
        int size = 0;
        for (Nodo i : contenido.values()) {
            size += i.tamagno();
        }
        return size;
    }

    // creara un nuevo archivo o directorio al directorio
    public void crear(Nodo Nodo) {
        contenido.put(Nodo.nombre(), Nodo);
    }

    // Borra un archivo o directorio del directorio
    public void borrar(String name) {
        contenido.remove(name);
    }

    // Borra el directorio
    public void eliminar() {
        contenido.clear();
    }

    // Busca un archivo o directorio en el directorio
    public Nodo buscar(String name) {
        return contenido.get(name);
    }

    // Muestra el nombre de los archivos y directorios de un directorio
    public String ls() {
        String str = "";
        if(!contenido.isEmpty()) {
            for (Map.Entry<String,Nodo> name : contenido.entrySet()) {
                str += name.getValue().nombre() + "\n";
            }
        }
        return str;
    }

    // Muestra el nombre y tamaño de los archivos y directorios de un directorio 
    public String du() {
        String str = "";
        if(!contenido.isEmpty()){
            for (Map.Entry<String,Nodo> i : contenido.entrySet()) {
                str += i.getValue().nombre() + " " + Integer.toString(i.getValue().tamagno()) + "\n";
            }
        }
        return str;
    }


    // Devuelve una lista con todos los archivos y directorios almacenados dentro de un directorio
    public List<Nodo> listar() {
        return new ArrayList<Nodo>(contenido.values());
    }
}





