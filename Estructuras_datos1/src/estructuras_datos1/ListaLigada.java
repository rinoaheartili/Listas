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
public class ListaLigada {
    private Nodo primerNodo;
    private int numeroNodos;
    
    public ListaLigada(){
        this.primerNodo = null;
        this.numeroNodos = 0;
    }
    
    public ListaLigada(int dato){
        this.primerNodo = new Nodo(dato);
        this.numeroNodos =  1;
    }
    
    public ListaLigada(Nodo nodo){
        this.primerNodo = nodo;
        this.numeroNodos = 1;
    }
    
    public boolean estaVacia(){
        return this.primerNodo == null;
    }

    public int getNumeroNodos() {
        return numeroNodos;
    }
    
    public void vaciarLista(){
        this.primerNodo = null;
        this.numeroNodos = 0;
    }
    
    
    public void insertaInicio(int dato){
        Nodo nuevoNodo = new Nodo(dato);
        
        if(!estaVacia())
            nuevoNodo.setSiguienteNodo(this.primerNodo);
        
        this.primerNodo = nuevoNodo;
        numerarNodos();
    }
    
    public void insertaFinal(int dato){
        if(estaVacia())
            insertaInicio(dato);
        else{
            Nodo nuevoNodo = new Nodo(dato);
            Nodo aux = this.primerNodo;
            System.out.println("\n======Insertando nodo "+nuevoNodo.getDato()+"=========");
            while(aux.getSiguienteNodo() != null){
                System.out.println("\nEstoy en el nodo con el dato: "+aux.getDato());
                aux = aux.getSiguienteNodo();
            }
            System.out.println("\nEstoy en el nodo con el dato: "+aux.getDato());
            aux.setSiguienteNodo(nuevoNodo);
            this.numeroNodos++;
            nuevoNodo.setNumNodo(numeroNodos);
        }        
    }
    
    public void insertaLugarN(int dato, int posicion){
        if(posicion < 1 || posicion > this.numeroNodos+1)
            System.out.println("Posicion fuera de rango");
        else if(posicion == 1)
            insertaInicio(dato);
        else if(posicion == this.numeroNodos+1)
            insertaFinal(dato);
        else{ // en medio posicion > 1 && posicion <= numeroNodos
            Nodo nuevoNodo = new Nodo(dato);
            Nodo aux = this.primerNodo;
            
            while(aux.getNumNodo() < posicion - 1)
                aux = aux.getSiguienteNodo();
            
            nuevoNodo.setSiguienteNodo(aux.getSiguienteNodo());
            aux.setSiguienteNodo(nuevoNodo);
            numerarNodos();
        }
    }
    
    public void imprimir(){
        if(estaVacia())
            System.out.println("La lista está vacía. No se puede imprimir");
        else{
            Nodo aux = this.primerNodo;
            System.out.println("\nImprimiendo lista ligada");
            while(aux != null){
                System.out.println(aux.toString());
                aux = aux.getSiguienteNodo();
            }
        }
    }
    
    public void borrarInicio(){
        if(estaVacia())
            System.out.println("La lista está vacía. No hay nodos por borrar");
        else{
            this.primerNodo = primerNodo.getSiguienteNodo();
            numerarNodos();
        }
    }
    
    public void borrarFinal(){
        if(estaVacia())
            System.out.println("La lista está vacía. No hay nodos por borrar");
        else{
            Nodo aux = this.primerNodo;
            
            // Si solo hay un nodo
            if(aux.getSiguienteNodo() == null){
                borrarInicio();
                return;
            }
            // Al salir de este ciclo aux estará en el penúltimo nodo
            while(aux.getSiguienteNodo().getSiguienteNodo() != null)
                aux = aux.getSiguienteNodo();
            aux.setSiguienteNodo(null);
            this.numeroNodos--;
        }
    }
    
    public void borrarLugarN(int posicion){
        if(posicion < 1 || posicion > this.numeroNodos)
            System.out.println("Posición fuera de rango");
        else if(posicion == 1)
            borrarInicio();
        else if(posicion == this.numeroNodos)
            borrarFinal();
        else{
            Nodo aux1 = this.primerNodo;
            Nodo aux2 = this.primerNodo.getSiguienteNodo();
            
            while(aux2.getNumNodo() != posicion){
                aux1 = aux1.getSiguienteNodo();
                aux2 = aux2.getSiguienteNodo();
            }
            
            aux1.setSiguienteNodo(aux2.getSiguienteNodo());
            aux2.setSiguienteNodo(null);
            numerarNodos();
        }
    }
    
    public void numerarNodos(){
        if(estaVacia())
            System.out.println("\nLa lista está vacía. No hay nodos para numerar");
        else{
            Nodo aux = this.primerNodo;
            int cont = 1;
            aux.setNumNodo(cont);
            
            while(aux.getSiguienteNodo() != null){
                aux = aux.getSiguienteNodo();
                cont++;
                aux.setNumNodo(cont);
            }
            this.numeroNodos = cont;
        }
    }
    
    public void actualizarNodoN(int posicion, int nuevoDato){
        if(posicion < 1 || posicion > this.numeroNodos)
            System.out.println("Posicion fuera de rango");
        else{
            Nodo aux = this.primerNodo;
            
            while(aux.getNumNodo() != posicion)
                aux = aux.getSiguienteNodo();
            System.out.println("\nActualizando nodo "+posicion+" con dato "+aux.getDato()+
                                " el nuevo dato es "+nuevoDato);
            aux.setDato(nuevoDato);
        }
    }
    
    public int buscarNodo(int datoABuscar){
        if(estaVacia()){
            System.out.println("La lista está vacía");
            return -999;
        }else{
            Nodo aux =  this.primerNodo;
            
            while(aux != null){
                if(aux.getDato() == datoABuscar){
                    System.out.println("El nodo con dato = "+datoABuscar+
                            " está en la posición "+aux.getNumNodo());
                    return aux.getNumNodo();
                }
                aux = aux.getSiguienteNodo();
            }
            System.out.println("El nodo con dato = "+datoABuscar+
                    " no se encuentra en la lista");
            return -999;
        }
    }
    
    public int buscar_numero(int numeroBuscado)
    {
	if(estaVacia())
	{
            System.out.println("\nNo hay elementos para imprimir");
            return -999;
	}
        else
        {
            Nodo aux = this.primerNodo;
            while(aux != null)
            {
                if (aux.getDato() == numeroBuscado) 
                {
                    System.out.println("\nNumero " + numeroBuscado + " esta en la posicion " + aux.getNumNodo());
                    return aux.getNumNodo();
                }
                aux = aux.getSiguienteNodo();
            }
            System.out.println("\nEl numero " + numeroBuscado + " no encuentra en la lista");
        }
        return -999;
    }

    public void inserta_numero_despues(int numeroBuscado, int dato)
    {
        if(estaVacia())
        {
            System.out.println("\nNo hay elementos para insertar");
        }
        else
        {
            Nodo aux = this.primerNodo;
            Nodo aux2 = this.primerNodo.getSiguienteNodo();
            Nodo nuevo_nodo = new Nodo(dato);
            while(aux.getDato() == dato && aux != null)
            {
                aux = aux.getSiguienteNodo();
                aux2 = aux2.getSiguienteNodo();
            }
            nuevo_nodo.setSiguienteNodo(aux2);
            aux.setSiguienteNodo(nuevo_nodo);
            numerarNodos();
        }
    }
    
    public int posicionar_nodo(int posicion)
    {
        if(estaVacia())
        {
                System.out.println("\nNo hay elementos para imprimir");
                return -9999;
        }
        Nodo aux = this.primerNodo;
        int i = 0;
        while(aux != null)
        {
            for(i = 1; i < numeroNodos; i++)
            {
                if(i == posicion)
                {
                    System.out.println("\nNumero actual es: " + aux.getDato() +" esta en la posicion " + aux.getNumNodo());
                    return aux.getNumNodo();
                }else
                {
                    aux = aux.getSiguienteNodo();
                }
            }
        }
        return -9999;
    }

    public void reescribe_nodo(int datoViejo, int dato_nuevo)
    {
        if(estaVacia())
        {
            System.out.println("\nNo hay elementos para imprimir");
        }
        Nodo aux = this.primerNodo;
        while(aux != null)
        {
            if(aux.getDato() == datoViejo)
            {
                aux.setDato(dato_nuevo);
                System.out.println("\nNumero actualizado es: " + aux.getDato() +" en la posicion " + aux.getNumNodo());
            }
            aux = aux.getSiguienteNodo();
        }
    }

}
