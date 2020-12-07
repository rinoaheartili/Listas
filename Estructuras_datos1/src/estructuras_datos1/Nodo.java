/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estructuras_datos1;

/**
 *
 * @author magicorlan
 */
public class Nodo {
    private int dato;
    private int numNodo;
    private Nodo siguienteNodo;
    
    public Nodo(){
        this.siguienteNodo = null;
    }
            
    public Nodo(int dato){
        this.dato = dato;
        this.siguienteNodo = null;
    }

    public int getDato() {
        return dato;
    }

    public int getNumNodo() {
        return numNodo;
    }
    
    public void setDato(int dato) {
        this.dato = dato;
    }

    public void setNumNodo(int numNodo) {
        this.numNodo = numNodo;
    }
    /*
    Para avanzar al siguiente nodo hacemos, p.e.
    aux = aux.getSiguienteNodo();
    */
    public Nodo getSiguienteNodo() {
        return siguienteNodo;
    }
    /*
    Gráficamente cambia la flecha del nodo actual
    para que apunte al nodo que se pasa como parámetro
    */
    public void setSiguienteNodo(Nodo siguienteNodo) {
        this.siguienteNodo = siguienteNodo;
    }
    
    @Override
    public String toString(){
        return "Nodo "+this.numNodo+": "+this.dato;
    }
    
}
