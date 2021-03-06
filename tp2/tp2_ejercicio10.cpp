#include <iostream>
using namespace std;
int main()
{
    //contadores de aciertos
    int bueno = 0;
    int regular = 0;
    int malo = 0;
    //numero a adivinar
    int n_adivinar = 3571;
    //variable auxiliar sobre la que se realizan opearaciones
    int aux_n_adivinar;
    //numero ingresado por el usuario
    int n_ingresado;
    //numero sobre el que se realizaran modificaciones
    int aux_n_ingresado;
    //variable que almacena el numero a buscar en el numero a adivinar
    int buscar_numero;
    //variable que determina la posicion del numero
    int posicion = 1000;
    //valible del numero a adivinar
    int numero_adivino;
    //variable para validar si se encontro el número en alguna vuelta
    bool numero_encontrado = false;
    cout<<"Bienvenido al juego de adivinanza"<<endl;
    cout<<"El número que debe ingresar debe ser de cuatro cifras"<<endl;
    cin >> n_ingresado;
    aux_n_ingresado = n_ingresado;
    //suponemos que el usuario ingresará un número de cuatros cifras
    //corroborar cada posición
    for(int i = 1; i <= 4; i++){
        //al ser buscar_numero un entero tomara solo la parte entera de la division por lo que obtendremos el numero de la posicion por la que dividimos en el caso de ser 1000 obtenermos el primer numero, 100 el segundo ...
        buscar_numero = aux_n_ingresado / posicion;
        //buscamos el numero en el numero a adivinar
        numero_encontrado = false;
        aux_n_adivinar = n_adivinar;
        for(int j = 1000; j >= 1; j=j/10){
           numero_adivino = aux_n_adivinar / j;
           //si la posicion es la misma en la que tiene que estar el numero debemos incrementar el contador bueno
           if(posicion == j && numero_adivino == buscar_numero){
                bueno ++;
                numero_encontrado = true;
                break;
                //si la posicion no es la misma en la que tiene que estar el numero debemos incrementar el contador regular
           }else if(numero_adivino == buscar_numero){
                regular ++;
                numero_encontrado = true;
                break;
           }
           aux_n_adivinar = aux_n_adivinar - (numero_adivino*j);
        }
        //si no se encuentra el numero incrementamos el malo
        if(numero_encontrado == false){
            malo ++;
        }
        //quito el numero que ya verifique y continuo con los restantes
        aux_n_ingresado = aux_n_ingresado - (buscar_numero * posicion);
        //busco en la posicion siguiente
        posicion = posicion / 10;
    }
    //Imprimo el resultado
    cout<<"El número a adivinar era: "<<n_adivinar<<endl;
    cout<<"El número ingresado es: "<<n_ingresado<<endl;
    cout<<"El resultado fue el siguiente:"<<endl;
    cout<<"     Bueno :"<<bueno<<endl;
    cout<<"     Regular :"<<regular<<endl;
    cout<<"     Malo :"<<malo<<endl;
    return 0;
}
