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
public class NodoDoble {
    private int dato;
    private int marca;
    private NodoDoble anteriorNodo;  // flecha al nodo anterior
    private NodoDoble siguienteNodo; // flecha al nodo siguiente
    
    
    public NodoDoble(int dato){
        this.dato = dato;
        this.anteriorNodo = null;
        this.siguienteNodo = null;
    }

    public int getDato() {
        return dato;
    }

    
    // Ayuda a avanzar hacia atrás
    public NodoDoble getAnteriorNodo() {
        return anteriorNodo;
    }

    // Ayuda a avanzar hacia adelante
    public NodoDoble getSiguienteNodo() {
        return siguienteNodo;
    }

    public void setDato(int dato) {
        this.dato = dato;
    }

    // Pone su flecha de "atrás" a otro nodo llamado aquí anteriorNodo
    public void setAnteriorNodo(NodoDoble anteriorNodo) {
        this.anteriorNodo = anteriorNodo;
    }

    // Pone su flecha de "adelante" a otro nodo llamado aquí siguienteNodo
    public void setSiguienteNodo(NodoDoble siguienteNodo) {
        this.siguienteNodo = siguienteNodo;
    }

    public int getMarca() {
        return marca;
    }

    public void setMarca(int marca) {
        this.marca = marca;
    }
    
    
    
    @Override
    public String toString(){
        return "Nodo: " + this.marca + ": " +this.dato;
    }
    
    
    
    
}
