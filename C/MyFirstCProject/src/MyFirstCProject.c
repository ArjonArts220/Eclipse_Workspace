/*
 ============================================================================
 Name        : MyFirstCProject.c
 Author      : Arjon Arts
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include are header files, if you want to create them you press - file, new, empty file, name it and put .h behind it

#include <stdio.h> //file standard input/output - for taking inputs or outputs(printf)
#include <stdlib.h> //standard library??

#include<math.h>
#include<ctype.h>
#include<string.h> // for string modupilation
//compiling is to convert this code into a code the machine can understand , if you press the button build it compiles your program.
#define MYNAME "Tuna McButtur" //its like a constant it can never change, make it capital so you can separate normal variables from constant variables
#include "MyFirstCFile.h"

int main()
{
    files();
    return 0;
}



void dataTypes(){
    int a = 10;
    float pi = 3.14;
    char my_char = 'a';
    double big_pi = 3.14159268234234;
    char my_string[] = "String"; // na een string komt een string terminator (\0), dit wil zeggen dat de string is afgelopen. Je ziet het niet maar het neemt wel een extra plekje in beslag.
    printf(my_string);
    strcpy(my_string, "Arjon"); //if you want to change your string, use strcpy(nameOfArray, replace it with);
    printf(my_string);
}

void printFunction(){
    //%x is a placeholder, it holds a spot for an ....
    printf("Hello world!\n");
    printf("Integer: %d\n", 10);
    printf("Large integer: %ld\n", 129012391312);
    printf("Decimal number: %.2f\n", 32.234); //.2 means 2 numbers after the comma
    printf("Large decimal number: %lf\n", 32.3413);
    printf("Character: %c\n", 'a');
    printf("String: %s\n", "hello world");
    printf("Hexadecimaal getal: %x\n", 16);
    printf("The numbers are: %d, %d and %d\n", 10, 20, 30); //combine them

    puts("Hello"); //it will print out a string whit a enter at the end
}

void scanFunction(){
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);  //scan your input and store it in the variable age
    printf("\nYour age is: %d", age);
    //if you want to scan a string, for example "Arjon Arts", it would only read Arjon because he thinks that that is the end of the string

    char name[50];
    gets(name); // it will scan the users input and put it in the array name, it is possible to have spaces between the words
}

void comparingInOneLine(){
    int number1, number2, finalNumber;
    printf("Enter number 1: ");
    scanf("%d", &number1);
    printf("Enter number 2: ");
    scanf("%d", &number2);
    finalNumber = (number1 >= number2) ? number1 : number2; // if number1 >= number2 is true dan wordt finalNumer number1 anders number 2
    printf("Final number is: %d", finalNumber);
}

void switchCase(){
    int evenNumber;
    printf("Chose an even number between 2 and 6 ");
    scanf("%d", &evenNumber);
    switch(evenNumber){
        case 2:
            printf("You chose number 2");
            break;
        case 4:
            printf("You chose number 4");
            break;
        case 6:
            printf("You chose number 6");
            break;
        default:
            printf("That number is incorrect");
    }
}

void doWhile(){
    int i = 0;
    do{ //This loop will execute at least one time, he prints it and then check if its smaller than 10
        printf("The value of i is %d", i);
    } while(i <= 10);
}

void continueExplained(){
    int number = 1;
    do{
        if(number == 6 || number == 8){
            number++;
            continue;   //continue means, don't do the code below but start from the beginning of the loop
        }
        printf("Number %d is available\n", number);
        number++;
    }while(number <= 10);
}

void arrayExplained(){
    int numberArray[6] = {10, 20, 30, 40, 50, 60};
    numberArray[3] = 45;
    for(int i = 0; i < 6; i++){
        printf("Number %d of array is %d\n", i, numberArray[i]);
    }

    /*Multi dimencial array, this is easy for example if you want to make a game (tic tac to), you kan make your bord*/
    int multiArray[4][3] = { //je kan 4 delen hebben met daarin max 3 nummers
        {010, 020, 030}, //positie 00 01 02
        {110, 120, 130}, //positie 10 11 12
        {210, 220, 230}, //positie 20 21 22
        {310, 320, 330}  //positie 30 31 32
    };
    printf("At position [3][1] is %d", multiArray[3][1]);

    char word[][7] = { //7 is stringlength
        {"Loaded"},
        {"Loaded"},
        {"Loaded"},
        {"Loaded"}
    };


}

void sortingAnArray(){ //we are comparing the x number with x+1, if x is bigger we swap them.
    int temp, swapped;
    int howmany = 10;
    int counter = 1;
    int goals[howmany];

    printf("Original list \n");
    for(int i = 0 ; i < howmany ; i++){
        goals[i] = (rand()%25) + 1;
        printf("%d \n", goals[i]);
    }

    while(1){
        swapped = 0;
        for(int i = 0 ; i < howmany-1 ; i++){ //minus one is because we don't have to compare the last number
            if(goals[i] > goals[i+1]){
                temp = goals[i];
                goals[i] = goals[i+1];
                goals[i+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
        printf("\nSorting list #%d\n", counter);
        for(int i = 0 ; i < howmany ; i++){
            printf("%d \n", goals[i]);
        }
        counter++;
    }
    printf("\nFinal sorting list \n");
    for(int i = 0 ; i < howmany ; i++){
        printf("%d \n", goals[i]);
    }
}

void absolute(){
    int year1, year2, age;
    printf("Enter year 1 \n");
    scanf("%d", &year1);

    printf("Enter year 2 \n");
    scanf("%d", &year2);

    age = year1 - year2;
    age = abs(age); //maakt van een negatieve waarde een positieve, positief blijft positief
    printf("Your age is %d \n", age);
}

void pointers(){ //a pointer a special type of variable that can hold an address
    /*a pointer is a variables that can store an address of another value, the pointer also has an address
    int a;
    int *p; --> p is a pointer that can store an integer, if you want to point it to "a" you have to make it equal to &a.
                if we put & it means that it gives us the address of that particular variable
    p = &a; --> p has now the address of a, it point to a
    printf(p); --> address of a
    printf(&a); --> address of a
    printf(&p); --> address of p
    printf(*p); --> value of a, dereference


    */
/*    int year = 18;
    int *pYear = &year;
    printf("Variable \n");
    printf("(year) I am %d years old \n", year);
    printf("(pYear)Address of year is %p \n", pYear);
    printf("(*pYear) I am %d years old \n", *pYear);
    printf("(&year)Address of year is %p \n", &year);

    printf("\n\nArray \n");
    int laptop[4] = {1, 2, 3 , 4};

    int *p = laptop; //the name of the array points to the first element in the array. now in p is the memory address of laptop[0]
    int *pLaptop0 = &laptop[0];
    printf("(pLaptop0)Element 0, address is %p \n", pLaptop0);
    int *pLaptopArray = laptop;
    printf("(pLaptopArray)Naam array0 address is %p \n", pLaptopArray);
    printf("(laptop)Naam array0 address is %d \n", laptop);
    printf("(*(laptop + 1))Value array1 address is %d \n", *(laptop + 1));*/

    int schriften[4] = {7, 45, 93, 26};
    int *pSchriften1;
    int *pSchriften2;
    *pSchriften1 = 10; //change value of element 0 to 10
    (*pSchriften1)++; //form 10 to 11;
    printf("Value \t Address &schriften[i] \t Address schriften + x \n");
    for(int i = 0 ; i < 4 ; i++){
        pSchriften1 = &schriften[i];
        pSchriften2 = schriften + i;
        printf("%d \t %p \t\t %p \n", *pSchriften1, pSchriften1, pSchriften2);

    }
}

void stingLenght(){
    /*size of char array >= number of characters + 1, the plus one is for the string terminator (\0). This comes at the end of the string so
    the computer sees that there the sting ends. If the the char array is full and there is no room for a string terminator, it prints a
    bunch of other characters out. */
    char movie[20] = "";
    char *pMovie = movie;

    fgets(movie, 20, stdin); //stdin staat voor standaart input zoals toetsenbord en niet bv random access file
    int lengtString = strlen(movie); //lenght of the string (stringlenght), max 19 because length array is 20
    puts(movie);
    printf("%d \n",lengtString);
}

void stuctures(){
    struct userInfo arjon; //je kan het ook op een andere manier maken, kijken headerfile 1)
    struct userInfo bucky;

    strcpy(arjon.firstName, "Arjon");
    strcpy(arjon.lastName, "Arts");
    arjon.userID = 15;
    arjon.weight = 70.2345;
    arjon.age = 18;
    //printInfo(arjon);

    /*You can make your own type istead of int, float...*/
    typedef int MYINT; //MYINT is represented as an integer
    int num = 3;
    printf("%d \n", num);
    MYINT num1 = 4;
    printf("%d \n", num1);

    CarType car1;
    car1.name = "Opel";
    printf("%s", car1.name);
}

void bitwise(){

    /*shift operator*/
    int a = 10;
    int shift_a = a << 4; //shift the binary value of 10 (1010) 4 times to the left
    for (int i = 11 ; i >= 0 ; i--){
        if((1 << i) & a){
            printf("1");
        }else{
            printf("0");
        }
    }
}

void enumExplained(){
    /*the variables in an enum are all constand*/
    enum{ one, two, three, four }; //it the same as: int one = 0; int two = 1 ....
    enum{ a = 10, b, c }; //int a = 10, int b = 11...
    printf("%d \n", a);

}

void mathFunctions(){
    printf("%f \n", pow(5, 3)); //5^3
    printf("%f \n", sqrt(64)); //wortel van
    printf("%d \n", rand()); //niets erin is een getal tussen 0 en ongeveer 32000)

    /*rand number*/
    srand(time(NULL)); //to get a different number each time
    int i = rand() % 5;

    /*size of*/
    printf("Size of an integer is %d \n", sizeof(int)); //print the size of an integer in bytes, an integer is 4 bytes
    printf("Size of an character is %d \n", sizeof(char)); //1 byte

    /*change string*/
    char ham[100] = "Hey ";
    strcat(ham, "Arjon ");  //it takes the string of "ham" and put "Arjon " erachter, Arjon is now part of the ham string
    strcpy(ham, "Hoi "); // it replaces one string with another string (Hey --> Hoi)

    /*get user input within a specific number of char*/
    char car[10];
    printf("Enter a car name");
    fgets(car, 10, stdin);

    /*check if user input is a number #1*/
    char userInput[4];
    int move = 0;
    printf("Please enter a number");
    fgets(userInput, 3, stdin);
    if(sscanf(userInput, "%d", &move) == 1){
        printf("Userinput is a number");
    }
    else{
        printf("Userinput isn't a number");
    }

    /*check if user input is a number #2*/
    char input[5];
    int number;
    printf("Enter a number \n");
    fgets(input, 5, stdin);
    number = atoi(input); //if int dan return int, if float dan return int (casting), else return 0
    (number != 0) ? (printf("You entered the number %d \n", number )) : (printf("You didn't entered a number %d", number));

    /*check if user input is a number... #3*/
    int tuna = 'g';
    if(isalpha(tuna)){} //if it is a letter form the alphabet a...z
    if(isdigit(tuna)){} //if it is a number
    if(isupper(tuna)){} //if it is a capital letter

    /*length string*/
    //size of char array >= number of characters + 1, the plus one is for the string terminator (\0). This comes at the end of the string so
    //the computer sees that there the sting ends. If the the char array is full and there is no room for a string terminator, it prints a
    //bunch of other characters out.
    char movie[20];
    fgets(movie, 20, stdin);
    int lengtString = strlen(movie);

    /*if the user types in...*/
    char command[16];
    fgets(command, 15, stdin);
    if(strncmp(command, "quit", 4) == 0){
        printf("You want to quit \n");
    }
    else{
        printf("You don't want to quit \n");
    }

    /*sscanf()*/
    char input1[16];
    int speed;
    char name[10];
    printf("Enter name and speed of car: ");
    fgets(input1, 15, stdin);
    int result = sscanf(input1, "%s / %d", name, &speed); //string, "Format", addresses of variables. If this is possible than the function returns a 2
    printf("Name is %s and speed is %d", name, speed);

    /*afronden*/
    float number1 = 5.734123; //afronden doe je met een float getal
    printf("Floor functie: %.2f \n", floor(number1)); //geeft 5, floor rond altijd naar beneden af
    printf("Ceil functie: %.2f \n", ceil(number1)); //geeft 6, ceil rond altijd naar boven af

}

void files(){
    //w -> write    r -> read   a -> append(toevoegen)
    /*write*/
    FILE *fp = fopen("baccon.txt", "a"); //make a file baccon, als het nog niet gemaakt is, maak het dan anders pak die file
    fprintf(fp, "I am cool \n"); //set i love baccon in the file
    fclose(fp); //close the file and save the data in the file

    /*read*/
    FILE *fp1 = fopen("baccon.txt", "r");
    char data[100];
    while(!(feof(fp1))){ //File End Of File, dus zolang hij niet aan het einde van de file is
        fgets(data, 100, fp1); //get line per line
        printf("%s \n", data);
    }
}
