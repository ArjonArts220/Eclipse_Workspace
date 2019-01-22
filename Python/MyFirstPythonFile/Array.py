def list():
    #Een list is hetzelfde als een array. Er kunnen verschillende datatypes in een list zitten
    lis = ["name", "arjon", 20, 'a'];
    lis[0] = "veranderen";
    lis.append("toevoegen");
    lis.pop(0);
    lenght = len(lis);
    print(lis);
    print(lis[2]);
    print(lis[1:3]);

def _set():
    #Een set is hetzelfde als een array, alleen kunnen er geen dubbele waardes in voorkomen
    se1 = set();
    se1.add(1);
    print(se1);

def directorie():
    #Een directorie is hetzelfde als een assosiative array, je hebt een key en een value
    direc = {'a':'aaa', 'b':'bbb',5:"nummer"};
    print(direc['a']);
    print(direc.get('a'));
    print(direc.get("c", "Als c key niet bestaat, print dit"));

def tulp():
    #Een tulp is hetzelfde als een array, alleen kun je na het aanmaken niets meer veranderen
    tul = (1, 2, "aaa", 'a');
    print(tul[0]);
    
directorie();
