/*
 * File:    ExcepcionArbolFicheros.java
 * Date:    april 2023
 * Comms:   Fichero ExcepcionArbolFicheros.java de la práctica 4 de la asignatura
 * 			de Tecnología de Programación.
 */
class ExcepcionArbolFicheros extends Exception {
    ExcepcionArbolFicheros () {
        super("Error");
    }
}

class NegativeSize extends ExcepcionArbolFicheros{
    public String toString(){
        return "File size must be greater than 0.";
    }
}

class Existe extends ExcepcionArbolFicheros {
    public String toString() {
        return "A file with the requested name already exists.";
    }
}

class InvalidNameD1 extends ExcepcionArbolFicheros {
    public String toString() {
        return "A directory can't have an extension.";
    }
}

class InvalidNameD2 extends ExcepcionArbolFicheros {
    public String toString() {
        return "Directory name can't start with '/'.";
    }
}

class InvalidNameD3 extends ExcepcionArbolFicheros {
    public String toString() {
        return "Directory name can't end with '/'.";
    }
}

class InvalidNameD4 extends ExcepcionArbolFicheros {
	public String toString(){
         return "A directory can't contain an extension."; 
    }
}

class InvalidNameE extends ExcepcionArbolFicheros {
	public String toString(){
        return "A link name can't contain an extension, must have a name and can't refer to a path."; 
    }
}

class InvalidNameF1 extends ExcepcionArbolFicheros {
    public String toString() {
        return "The file name can't refer to a path.";
    }    
}

class InvalidNameF2 extends ExcepcionArbolFicheros{
	public String toString(){
        return "The file needs an extension."; 
    }
}

class InvalidNameF3 extends ExcepcionArbolFicheros{
	public String toString(){
        return "The file needs a complete extension."; 
    }
}

class YaExisteF extends ExcepcionArbolFicheros {
    public String toString() {
        return "A file with the requested name already exists in the current path.";
    }
}

class YaExisteDir extends ExcepcionArbolFicheros {
    public String toString() {
        return "A directory with the requested name already exists in the current path.";
    }
}

class YaExisteEnl extends ExcepcionArbolFicheros {
    public String toString() {
        return "A link with the requested characteristics already exists in the current path.";
    }
}

class NoExisteF extends ExcepcionArbolFicheros {
    public String toString() {
        return "There's no file with the requested name.";
    }
}

class NoExisteDir extends ExcepcionArbolFicheros {
    public String toString() {
        return "There's no directory with the requested name.";
    }
}

class NoEsDir extends ExcepcionArbolFicheros {
    public String toString() {
        return "This is not a directory.";
    }
}

class Remove_error extends ExcepcionArbolFicheros{
	public String toString(){ 
        return "You are within the path you intend to erase."; 
    }
}


class EstasRoot extends ExcepcionArbolFicheros {
    public String toString() {
        return "You are in the root directory, you can't go back.";
    }
}

class ErrorPath extends ExcepcionArbolFicheros {
    public String toString() {
        return "There is a path error.";
    }
}

