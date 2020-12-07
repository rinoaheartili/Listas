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
public class Estructuras_datos1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ListaDoblementeLigada lista = new ListaDoblementeLigada();
        
        
        lista.insertarInicio(25);
        lista.insertarFinal(94);
        lista.insertarFinal(29);
        lista.insertarFinal(15);
        lista.insertarFinal(39);
        
        lista.numerarNodos();
        lista.imprimirLista();
        lista.getMitad();
        //lista.buscar_numero(7);
        
        //lista.inserta_numero_despues(94, 5);
        //lista.imprimir();
        
        //lista.posicionar_nodo(4);
        
        //lista.reescribe_nodo(29, 30);
        //lista.imprimir();
        /*
        lista.imprimirListaReversa();
        
        lista.borrarFinal();
        lista.borrarFinal();
        lista.borrarFinal();
        lista.borrarFinal();
        lista.borrarFinal();
        
        
        lista.imprimirLista();
        lista.imprimirListaReversa();
        */

        
    }
    
}
