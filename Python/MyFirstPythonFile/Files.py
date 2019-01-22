import Module

def read():
    #Reading a file
    names_file = open("names.txt", "r");
    
    print(names_file.readable()); #REturn een bool, kun je de file lezen
    
    print(names_file.readline()); #Read 1 line
    
    names_arr = names_file.readlines(); #Read de hele file en slaat het op in een array
   
    names_file.close();
    
def write():
    file = open("names.txt", "a"); # a -> append
    
    file.write("New name \n");
    
    file.close();
    
    file = open("names.text", "w");
    
    
write();

Module.test();