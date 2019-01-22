

def forloop():
    for x in range(10):         # 0 t/m 9
        print(x);
    
    for y in range(4, 10):      # 4 t/m 9
        print(y);
    
    for z in range(4, 10, 2):   # 4, 6, 8
        print(z);

def getInput():
    #Get input from console
    name = input("Enter your name: ");
    print("Hello ", name, "!");
    
getInput();