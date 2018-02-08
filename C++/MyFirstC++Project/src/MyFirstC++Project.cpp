//============================================================================
// Name        : MyFirstC++Project.cpp
// Author      : Arjon Arts
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*The New Boston tutorial - 31*/

#include <iostream>
#include <string> //hiermee kan je zeggen: " string naam = 'arjon'; "
#include "Burrito.hpp"

/*
C++ les 2:

vector:
vector is een dynamisch array - komt dus op heap <vector> <--classe

Mijnklasse a; //komt op stack
Mijnklasse *b = new Mijnklasse; //komt op heap en is altijd een pointer, dus vergeet * niet
delete b; //deconsturctor word aangeroepen, delete (een adres - bv b bij voorbeeld hierboven)

map:
map in C++ is hetzelfde als hashmap in java

*/
using namespace std;

void print();
int tuna = 69;

int main(){
    Burrito b;
    Burrito *bp = &b;
    (*bp).printCrap();
    return 0;
}

void print(){
    cout << "hello world"; //print zonder enter
    cout << "hello world" << endl; //print met enter (endl -> end of line)
    cout << "hello world \n"; //print met enter

    int baccon = 5;
    cout << "baccon is: " << baccon << endl;
}

void getInputFromConsole(){
    int input;
    cin >> input;
}

void arrays(int arrayOne[], int *arrayTwo){
    /*Normal array*/
    int arrayName[5] = {1, 2, 3, 4, 5};
    int awwayName[8];

    /*Multidimensional array, dit moet je zien als rijen en colloms. Het is een array in een array.*/
    int multiArr[2][3] = {{2,3,4}, {5,6,7}}; //2, 3, 4
                                             //5, 6, 7
}

void pointers(int *pointer){
    /*Een pointer is een speciale variable die een adres vasthoud. Met het en-teken (&) krijg je het memory-adres van een variable.*/
    int fish = 6;
    int *fishPointer = &fish; //in fishpointer komt het adres van fish in te staan.
    *fishPointer = 66; //verander de fishvariable naar 66.
}

void classesAndObjectsAndContructors(){
    /*Een klasse word gebruikt om functies en variable bij elkaar te doen
      Een constructor word automatsch aangeroepen bij het aanmaken van het object, het heeft nooit een returnvalue. Een constructor begint altijd met de naam
      van je klass
    class myClass{
        public: //alles onder public word automatisch public, public wil zeggen dat je de functie/var buiten die class kan uitvoeren/pakken
            myClass(string name, int age){ //constructor
            }
            void functionName(){
            }
        private:
            void awesomeName(){
            }
    };

    myClass myClassObject;
    myClassObject.functionName();*/
}

void functions(){
    /*Random number*/
        /*Met de rand() functie kun je een random getal laten genereren, om een getal tussen x en 0 te hebben doe rand()%x (returnvalue tussen 0 en x-1). Het
        probleem is, is dat hij de heletijd hetzelfde nummer teruggeeft. De oplossing hiervoor is srand(), dit staat voor seed random, door een getal erin te
        stoppen doet hij de rand algoritme anders. De functie time(0) returnt het aantal secondes vanaf 1970, je krijgt dus elke keer een ander getal, dus
        een ander algoritme. Doe dit bovenaan je programma*/
 //       int a = (rand()%69) + 1;
 //       int b = sreed(time(0));

    /*:: unary scope resolution operator*/
        /*Als een lokale variable dezelfde naam heeft als een globale variable en je wilt bijvoorbeeld de globale variable uitprinten, dan gebruik je de "::".
        Dus "::" wilt zeggen: gebruik de globale variable.*/
        int tuna = 9;
        cout << ::tuna << endl; //ouput is 69

    /*sizeof() function, deze functie return de size of een variable in bytes.*/
        char a;
        cout << sizeof(a) << endl; //output is 1 (dus 1 byte)
}

void composition(){

}
