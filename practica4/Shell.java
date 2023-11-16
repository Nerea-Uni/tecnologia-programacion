/*
 * File:    Shell.java
 * Date:    april 2023
 * Comms:   Fichero Shell.java de la práctica 4 de la asignatura
 * 			de Tecnología de Programación.
 */
import java.util.Stack;

public class Shell {
    private Stack<Directorio> pila; //=  new ArrayList<Directorio>();

    public Shell (Directorio root) {
        pila = new Stack<>();
        pila.push(root);
    }

    /*
     * Devuelve la ruta completa de forma textual, con todos los nombres
     * de los directorios desde la raíz hasta el directorio actual 
     * concatenados y separados por el separador '/'.
     */
    public String pwd() {
        StringBuilder wd = new StringBuilder();
        Stack<Directorio> temp = new Stack<>();
        while (!pila.isEmpty()) {
            Directorio dir = pila.pop();
            wd.insert(0, "/" + dir.nombre());
            temp.push(dir);
        }
        while (!temp.isEmpty()) {
            pila.push(temp.pop());
        }
        return wd.toString().equals("") ? "/" : wd.toString();
    }

    /*
     * Devuelve un shell con el nombre de todos los nodos contenidos 
     * en la ruta actual, uno por línea.
     */
    public String ls() {
        return pila.peek().ls();
    }

    /*
     * Devuelve un shelldo con el nombre y el tamaño de todos los nodos 
     * contenidos en la ruta actual, uno por línea.
     */
    public String du() {
        return pila.peek().du();
    }
    
    /*
     * Edita el fichero de nombre 'name' (en el directorio actual). Para
     * simular la edición, simplemente se cambia el tamaño del fichero al
     * valor especificado como parámetro. Si el fichero no existe, se
     * debe crear con el nombre y tamaño especificados.
     */
    public void vi(String name, int size) throws ExcepcionArbolFicheros{
        try {
            if (size <= 0) {
                throw new NegativeSize();
            }
            if (name.contains("/")) {
                throw new InvalidNameF1();
            }
            if (!name.contains(".")){
                throw new InvalidNameF2();
            }
            if (name.endsWith(".")) {
                throw new InvalidNameF3();
            }
            Nodo aux = pila.peek().buscar(name);
            if (aux != null && aux instanceof Fichero){
                //El fichero ya existe, actualizamos el tamaño con el introducido
                Fichero fich = (Fichero) aux;
                fich.actTamagno(size);
            }
            else {
                //El fichero no existe, hay que crearlo
                Fichero ficher = new Fichero(name, size);
                pila.peek().crear(ficher);
            }
        } catch(ExcepcionArbolFicheros e){
            throw e;
        }
    }   
    
    /*
     * Crea un directorio de nombre 'name' en el directorio activo. 
     */
    public void mkdir(String name) throws ExcepcionArbolFicheros {
        try {            
            if (name.contains("/")) {
                if (name.charAt(0) == '/') {
                    throw new InvalidNameD1();
                } else if (name.charAt(name.length() - 1) == '/') {
                    throw new InvalidNameD2();
                } else {
                    throw new InvalidNameD3();
                }
            }
            if (name.contains(".")) {
                throw new InvalidNameD4();
            }
            if (pila.peek().buscar(name) != null) {
                throw new YaExisteDir();
            }
            // Crea el directorio
            Directorio newDir = new Directorio(name);
            pila.peek().crear(newDir);
        } catch(ExcepcionArbolFicheros e){
            throw e;
        }
    }

    /*
     * Hace que la ruta activa pase a referenciar a otro directorio. La 
     * nueva ruta activa definida en 'path' debe referenciar un 
     * directorio o un enlace a un directorio.
     */
    public void cd(String path) throws ExcepcionArbolFicheros {
        try {
            if (path.equals("..")) {
                // Si el path es "..", subimos un nivel en la pila
                if (pila.size() > 1) {
                    pila.pop();
                }
            }
            else if (path.equals("/")) {
                // Si el path es "/", vamos a la raíz (el primer elemento de la pila)
                while (pila.size() > 1) {
                    pila.pop();
                }
            }
            else {
                // Si el path es relativo, lo procesamos para avanzar en la pila
                String[] dirs = path.split("/");
                for (String dir : dirs) {
                    if (dir.equals("..")) {
                        // Si encontramos "..", subimos un nivel en la pila
                        if (pila.size() > 1) {
                            pila.pop();
                        }
                        else {
                            // Si ya estamos en el nivel superior, lanzamos una excepción
                            throw new EstasRoot();
                        }
                    }
                    else if (!dir.equals(".")) {
                        // Si encontramos un nombre de directorio distinto de "." o "..", buscamos el directorio en el nivel actual
                        Stack<Directorio> route = new Stack<>();
                        route.addAll(pila);
                        Nodo exists = route.peek().buscar(dir);
                        if (exists == null) {
                            throw new NoExisteDir();
                        }
                        if (exists instanceof Directorio) {
                            pila.push((Directorio) exists);
                        }
                        else {
                            throw new NoEsDir();
                        }
                    }
                }
            }
        } catch (ExcepcionArbolFicheros e) {
            throw e;
        }
    }

    /*
     * Crea en el directorio actual un enlace simbólico de nombre 'name' 
     * que apunta al elemento identificado mediante la ruta especificada
     * en 'path', que puede ser de cualquier tipo. El nombre 'name' es un
     * nombre simple de nodo (se creará en el directorio activo), por lo 
     * que no puede contener una ruta completa. La ruta definida en 'path'
     * sí, de tal modo que se puede crear un enlace a un elemento en otro
     * directorio del árbol, que debe existir previamente.
     */
    public void ln(String path, String name) throws ExcepcionArbolFicheros{
        try{
            if(name.equals(".") ||  name.equals("") || name.contains("/")){
                throw new InvalidNameE();
            }
            Directorio actual = pila.peek();
            Enlace nuevo = new Enlace(name);
            Nodo existe = pila.peek().buscar(name);

            if(existe != null && existe instanceof Enlace){
                throw new YaExisteEnl();
            }
            if(path.equals(actual.nombre())){
                nuevo.link = actual;
                actual.crear(nuevo);
            }
            else{
                String anterior = pwd();
                String[] parts = path.split("/");
                int numComponentes = parts.length;
                int i = 0;
                String newPath = "";
                while(i < numComponentes-1){
                    newPath+=parts[i];
                    i++;
                }
                if(numComponentes > 1){
                    cd(newPath);
                }
                Nodo pertenece = pila.peek().buscar(parts[numComponentes-1]);
                if(pertenece != null){
                    //buscado = pertenece;
                    actual.crear(nuevo);
                    if(numComponentes > 1){
                        cd(anterior);
                    }
                }
                else {
                    throw new ErrorPath();
                }
            }
        } catch(ExcepcionArbolFicheros e){
            throw e;
        }
    }

    /*
     * Devuelve el tamaño del nodo que referencia el path.
     */
    public int stat(String path) throws ExcepcionArbolFicheros {
        try {
            String back_up = pwd();             //Back-up del directorio actual
            int pos = path.lastIndexOf("/");    //Búsqueda del último directorio donde se encuentra el archivo a evaluar
            String fichero;                     //Guarda el nombre del path que referencia
            if (pos == -1) {
                // Directorio actual
                fichero = path;
            }
            else if (pos == 0) {
                // Directorio raiz
                cd("/");
                fichero = path.substring(1);
            }
            else {          //pos > 0
                //Ruta completa
                String ruta = path.substring(0, pos);
                cd(ruta);
                fichero = path.substring(pos+1);
            }
            //Obtención de los datos del archivo a evaluar
            Nodo node;
            if (path.equals("/")){
                node = pila.peek();
            }  
            else {
                node = pila.peek().buscar(fichero);
            }
            if (node == null) {
                throw new NoExisteDir();
            }
            int size = node.tamagno();

            cd(back_up);
            return size;
        } catch(ExcepcionArbolFicheros e) {
            throw e;
        }
    }

    /*
     * Elimina un nodo. Si es un fichero, es simplemente eliminado. Si es
     * un enlace, elimina el enlace pero no el nodo referenciado. Si es un
     * directorio, elimina el directorio y todo su contenido. Si existen
     * enlaces al elemento borrado, ese elemento sigue siendo accesible a
     * traves del enlace (todavía existe), pero no a través de su ubicación
     * original (que ha sido eliminada).
     */
    public void rm(String path) throws ExcepcionArbolFicheros {
        String backUp = pwd();
        if (backUp.contains(path)){
            throw new Remove_error();
        }
        //Busco el último directorio del path donde se encuentra el archivo que queremos borrar.
        int posicion = path.lastIndexOf("/");
        if (posicion != 1) {
            Nodo remove_elem = pila.peek().buscar(path.substring(posicion + 1));
            if (remove_elem == null) {
                throw new NoExisteF();
            }
            else{
                if(remove_elem instanceof Fichero) {
                    pila.peek().borrar(remove_elem.nombre());
                }
                else if (remove_elem instanceof Enlace) {
                    pila.peek().borrar(remove_elem.nombre());
                }
                else{
                    if(((Directorio) remove_elem).tamagno() == 0) {
                        pila.peek().borrar(remove_elem.nombre());
                    }
                    else {
                        cd(backUp + '/' + path);
                        remove_elem = pila.peek();
                        for(Nodo i : ((Directorio) remove_elem).listar()) {
                            rm(i.nombre());
                        }
                        cd(backUp);
                        remove_elem = pila.peek().buscar(path.substring(posicion + 1));
                        pila.peek().borrar(remove_elem.nombre());
                    }
                }
            }
        }
        else {
            cd(path.substring(0,posicion - 1));
            Nodo remove_elem = pila.peek().buscar(path.substring(posicion + 1));
            rm(remove_elem.nombre());
        }
    }
}

