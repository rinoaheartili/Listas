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
public class ListaDoblementeLigada {
    private NodoDoble primerNodoDoble;
    private int numeroNodos;
    
    public ListaDoblementeLigada(){
        this.primerNodoDoble  = null;
        numeroNodos = 0;
    }
    
    public ListaDoblementeLigada(NodoDoble nodo){
        this.primerNodoDoble = nodo;
        numeroNodos = 1;
    }
    
    public void vaciarLista(){
        this.primerNodoDoble = null;
        numeroNodos = 0;
    }
    
    public boolean estaVacia(){
        return this.primerNodoDoble == null;
    }

    public NodoDoble getPrimerNodoDoble() {
        return primerNodoDoble;
    }
    
    public void insertarInicio(int dato){
        
        NodoDoble nuevoNodo = new NodoDoble(dato);
        
        if(!estaVacia()){
            nuevoNodo.setSiguienteNodo(this.primerNodoDoble);
            nuevoNodo.getSiguienteNodo().setAnteriorNodo(nuevoNodo);
        }
        
        numeroNodos++;
        this.primerNodoDoble = nuevoNodo;
    }
    
    public void insertarFinal(int dato){
        if(estaVacia())
            insertarInicio(dato);
        else{
            NodoDoble nuevoNodo = new NodoDoble(dato);
            NodoDoble aux = this.primerNodoDoble;
            while(aux.getSiguienteNodo() != null)
                aux = aux.getSiguienteNodo();
            aux.setSiguienteNodo(nuevoNodo);
            nuevoNodo.setAnteriorNodo(aux);
        }      
        numeroNodos++;
    }
    
    public void borrarInicio(){
        if(estaVacia())
            System.out.println("Lista vacía, no hay nodos para borrar");
        else{
            this.primerNodoDoble = this.primerNodoDoble.getSiguienteNodo();

            if(!estaVacia()){
                this.primerNodoDoble.getAnteriorNodo().setSiguienteNodo(null);
                this.primerNodoDoble.setAnteriorNodo(null);
            }
        }
        numeroNodos--;
    }
    
    public void borrarFinal(){
        if(estaVacia())
            System.out.println("La lista está vacía, no hay nodos para borrar");
        else{
            if(this.primerNodoDoble.getSiguienteNodo() == null){
                vaciarLista();
                return;
            }
            NodoDoble aux =  this.primerNodoDoble;
            while(aux.getSiguienteNodo().getSiguienteNodo() != null)
                aux = aux.getSiguienteNodo();
            aux.getSiguienteNodo().setAnteriorNodo(null);
            aux.setSiguienteNodo(null);
        }
        numeroNodos--;
    }
    
    public void imprimirLista(){
        if(estaVacia())
            System.out.println("\nLa lista no tiene nodos que imprimir\n");
        else{
            NodoDoble aux = this.primerNodoDoble;
            System.out.println("\nImprimiento lista doblemente ligada");
            while(aux != null){
                System.out.print(" "+aux.toString());
                aux = aux.getSiguienteNodo();
            }
            System.out.println("");
        }
    }
    
    public void imprimirListaReversa(){
        if(estaVacia())
            System.out.println("\nLa lista no tiene nodos que imprimir");
        else{
            NodoDoble aux = this.primerNodoDoble;
            while(aux.getSiguienteNodo() != null)
                aux = aux.getSiguienteNodo();
            System.out.println("\nImprimiento al reves lista doblemente ligada");
            while(aux != null){
                System.out.print(" "+aux.toString());
                aux = aux.getAnteriorNodo();
            }
            System.out.println("");
        }        
    }
    
    public void numerarNodos(){
        if(estaVacia())
            System.out.println("\nLa lista está vacía. No hay nodos para numerar");
        else{
            NodoDoble aux = this.primerNodoDoble;
            int cont = 1;
            aux.setMarca(cont);
            
            while(aux.getSiguienteNodo() != null){
                aux = aux.getSiguienteNodo();
                cont++;
                aux.setMarca(cont);
            }
            this.numeroNodos = cont;
        }
    }
    
    public void getMitad() 
    {
        if(estaVacia())
            System.out.println("\nLa lista no tiene nodos que imprimir");
        else{
            int mitad;
            mitad = numeroNodos/2;
            NodoDoble aux = this.primerNodoDoble;
            while(aux != null) 
            {
                if(aux.getMarca() == mitad) 
                {
                    if(mitad%2 == 0)
                        System.out.print(" "+aux.getSiguienteNodo().toString());
                    else
                        System.out.print(" "+aux.toString());
                } 
                aux = aux.getSiguienteNodo();
            }
        }
    }
    
}
