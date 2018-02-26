'''
Pe noi ne-a invatat in liceu sa ne bazam majoritatea codurilor de backtracking pe codul de generare de permutari.
Daca intelegi cum lucreaza ala, stii sa faci in mare chestiile de baza in back.
Codul de permutari genereaza toate combinatiile de numere intre 1 si n (ma gandesc ca stii ce ii aia permutare :)) )
Daca tu ai de exemplu sa generezi toate combinatiile de litere dintr-un cuvant, poti sa iti imaginezi ca
generezi permutari de pozitiile literelor respective in cuvantul ala.
e.x.: ai cuvantul s = 'info'. Atunci s[0] = i, s[1] = n, s[2] = f, s[3] = o. Deci, daca generezi permutari
de numerele de la 0 la 3, doar cand printezi solutia o sa ai nevoie de faptul ca numerele alea sunt de fapt pozitii.
O sa iti genereze de genul stack = 0123, stack = 0132 etc si la printare poti sa scrii s[stack[i]] sau ceva de
genul si atunci printezi info, inof si asa.

Sunt 5 functii principale.
    back - functia de baza care le apeleaza pe celelalte
    value (poti sa ii dai numele oricum dar eu le-am dat asa ca mi se par destul de sugestive) - pune valoare pe 
nivelul curent
    validate - valideaza valarea de pe nivelul curent
    solution - valideaza tot stack-ul (lista de valori) curent (in cazul permutarilor verifica daca
lungimea listei o ajuns la lungimea fixa la care trebe, adica n - 1)
    printSolution - tipareste solutia
    
    
Mai in detaliu mai jos :))
'''

def isPrime(x):
    '''
    Checks if a number is prime.
    input - x, integer number
    output - True or False
    '''
    
    d = 2
    while d <= x / 2:
        if x % d == 0:
            return False
        d = d + 1
        
    return True

def generatePrimeNumbers(n):
    '''
    Generates all prime numbers that are less than or equal to n.
    input - n, integer number
    output - list of all prime numbers <= n, starting on position 1 (position 0 is 0 to help in
            the backtracking implementation)
    '''
    
    result = [0]
    if 2 <= n:
        result.append(2)
        
    x = 3
    while x <= n:
        if isPrime(x) == True:
            result.append(x)
        x = x + 2
        
    return result

def value(k, nr, stack):
    '''
    Functia asta pune valoare pe nivelul curent (adica pe pozitia din stack pe care suntem acuma).
    Am mers tot pe idea de mai sus, adica am o lista de numere prime pe care o folosesc doar la tipar si
    la calculul de sume, dar la generare folosesc doar pozitiile lor, de la 1 la nr (nr de numere prime pe
    care il am).
    Deci daca avem de exemplu n = 10, dupa ce genereaza numerele prime o sa avem a = [0, 2, 3, 5, 7] (toate nr
    prime de la 2 la 10) si nr = 5. Pe 0 de la inceputul lui a o sa il ignore (pentru ca numerele din permutari
    incep de pe 1). Atunci programul asta o sa genereze de exemplu stack = [1,1,1,1,1], si atunci solutia e
    a[1],a[1],a[1],a[1],a[1], adica 2, 2, 2, 2, 2 (pt ca 2 + 2 + 2 + 2 + 2 = 10). O alta solutie o sa fie de
    exemplu stack = [1, 2, 3], adica a[1], a[2], a[3], adica 2, 3, 5 (pt ca 2 + 3 + 5 = 10, sper ca sunt coerenta..)
    
    input - k, nivelul (pozitia)
          - nr, nr de numere prime pe care le putem pune in stack
          - stack - stack :))
          
    output - True or False
    '''
    
    '''
    ok = False, adica presupune ca nu mai poate pune nicio valoare pe nivelul curent
    '''
    
    ok = False                          
    
    '''
    Pe un nivel o sa poata deci sa fie numere de la 1 la nr (nr de numere prime).
    Ca sa poata sa puna o valoare noua pe nivelul pe care suntem, valoarea veche trebe sa fie mai mica decat nr - 1.
    Sa zicem ca valoarea veche de pe nivelul curent e 3 si noi avem in total 5 numere prime. Il compara pe 3 cu 5,
    ii da ca e mai mic si atunci poate sa il creasca cu 1, deci valoarea de pe nivelul curent devine 4 si ok devine
    True. Daca valoarea de pe nivel e 5, nu mai poate sa o creasca pt ca nu avem atatea numere prime, si atunci
    ok ramane False.
    '''
    
    if stack[k] < nr - 1:               #compara valoarea de pe nivelul curent cu valoarea maxima ce poate sa o aiba
        stack[k] = stack[k] + 1         #daca e mai mica, o incrementeaza
        ok = True                       #si ok = True\
        
    return ok                           #returneaza ok, adica True daca a reusit sa puna o valoare pe nivel si
                                        #False daca nu

def validate(k, stack, a, n):
    '''
    Functia asta valideaza valoarea pe care o pus-o functia de mai sus.
    In cazul permutarilor, aici verifica sa nu se repete numerele.
    La problema asta, ne intereseaza sa fie numerele doar in ordine crescatoare (ca nu are sens sa dea
    si 2 2 3 si 2 3 2 si tot asa), si suma numerelor sa nu depaseasca n.
    
    input - k, nivelul curent
          - stack, stack
          - a, lista de numere prime (ne trebuie la calculatul sumei)
          - n, suma pe care trebuie sa o obtinem
          
    output - True sau False
    '''
    
    '''
    ok = True, adica presupune ca valoarea curenta e buna.
    total = suma initializata cu 0
    '''
    ok = True
    total = 0
    
    '''
    Asta verifica sa nu fie numerele in ordine descrescatoare.
    Daca e pe primul nivel, nu intra in if ca nu are de ce. De la nivelul 1 incepand, verifica sa fie valoarea
    de pe nivelul curent mai mare sau egala decat valoarea dinaintea ei. Daca e mai mica, ok se face False.
    '''
    
    if k > 0 and stack[k] < stack[k - 1]:
        ok = False
    
    '''
    Daca ok o ramas True, calculeaza suma elementelor de pana acuma.
    Suma asta nu are voie sa depaseasca n. Deci, daca e mai mare decat n, ok = False, daca e <=, ok ramane True.
    '''
        
    if ok == True:
        for i in range(0, k + 1):
            total = total + a[stack[i]]
            
        if total > n:
            ok = False
      
    '''
    Returneaza ok, care e True daca valoarea de pe nivelul curent e valida si False altfel.
    '''  
    return ok

def solution(k, stack, a, n):
    '''
    Functia asta verifica daca stack-ul curent e solutie.
    Aici, conditia ca stack-ul sa fie solutie e ca suma elementelor din stack sa fie egala cu n.
    Dat fiind faptul ca functia de mai sus returneaza True doar daca suma curenta e <= n, aici nu o
    sa trebuiasca sa verificam si sa nu fie mai mare ca n, pentru ca nu o sa fie niciodata.
    Deci, aici returneaza True daca suma = n, False daca suma < n
    
    Daca suma = n, stack-ul e solutie si returneaza True. Daca suma < n, nu e solutie.
    
    input - ca mai sus
    '''
    total = 0
    
    for i in range(0, k + 1):
        total = total + a[stack[i]]
        
    if total == n:
        return True
    
    return False

def printSolution(k, stack, a):
    '''
    Printeaza solutia.
    '''
    
    result = ''
    
    for i in range(0, k + 1):
        result = result + str(a[stack[i]]) + ' '
        
    print(result)

def back(a, n, nr):
    '''
    Asta e functia de back propriu-zisa.
    
    number o sa numere daca avem vreo solutie. Daca nu exista nicio solutie (number = 0), la sfarsit o sa
    scrie 'No solution.'
    
    k = nivelul (poate iti e mai usor sa ii dai numele niv sau nivel, eu m-am obisnuit cu k
    stack e initializat cu [0] pentru ca o sa incerce direct sa puna valoare pe primul nivel.
    Daca nu il initializezi si ramane stack = [], cand intra prima data in functia value o sa faca stack[0]
    si da eroare index out of reach.
    '''
    
    number = 0
    k = 0
    stack = [0]
    
    '''
    Backtracking-ul ca metoda incearca sa puna o valoare pe nivel. Daca reuseste, creste nivelul si incearca sa puna
    o valoare pe urmatorul si tot asa pana cand ori ajunge la nr maxim de niveluri, ori nu mai are ce valoare
    sa puna. Daca ramane fara valori de pus pe un nivel, se intoarce la nivelul dinainte si incearca sa puna pe
    ala ce valori o ramas. Deci nivelul tot face -1, asa ca o sa ajunga la -1 la un moment dat. Cand ajunge
    la -1 inseamna ca o terminat toate valorile de pe toate nivelele si atunci iese din while si gata.
    '''
    
    while k >= 0:
        '''
        answer o sa fie True cat timp mai avem ce valoare sa punem pe nivelul curent.
        valid o sa fie False cat timp valoarea pe care am pus-o pe nivel nu e valida.
        
        Deci tot repeta wbile-ul pana ori da de o valoare valida, ori nu mai are valori.
        '''
        
        answer = True
        valid = False
        while answer == True and valid == False:
            '''
            Incearca sa puna o valoare pe nivel. answer = True daca reuseste, False daca nu.
            '''
            
            answer = value(k, nr, stack)
            '''
            Daca o reusit, valideaza valoarea aia. valid = True daca e buna, False daca nu.
            '''
            
            if answer == True:
                valid = validate(k, stack, a, n)
        
        '''
        Cand ajunge aici inseamna ca ori nu mai are valori, ori o gasit o valoare valida.
        Daca nu mai are valori, answer = False sau valid = False si merge pe else, scade nivelul si
        continua sa puna valori pe nivelul precedent. Daca o gasit valoare buna, answer = True si valid = True.
        '''
                
        if answer == True and valid == True:
            '''
            Daca o gasit valoare buna, verifica daca stack-ul curent e solutie.
            Daca e solutie, o scrie. Daca nu e solutie, creste nivelul si pune valori pe nivelul urmator.
            '''
            
            if solution(k, stack, a, n) == True:            #apeleaza solution, returneaza True daca suma elementelor
                                                            #de pana acuma e n, False daca nu
                number = number + 1                         #daca e solutie, o numara ca sa nu mai scrie la sfarsit 'No solution.'
                printSolution(k, stack, a)                  #apeleaza functia care printeaza solutia
            else:
                stack.append(0)                             #daca nu e solutie, creste nivelul si initializeaza
                                                            #nivelul nou cu 0
                k = k + 1
        else:
            del stack[-1]                                   #daca nu mai are valori, sterge nivelul curent
                                                            #si merge inapoi pe nivelul precedent
            k = k - 1
            
    if number == 0:
        print('No solution.')

n = int(input('Give n: '))          #citeste n si converteste la int
a = generatePrimeNumbers(n)         #apeleaza functia care genereaza toate numerele prime <= n
nr = len(a)                         #nr = nr de numere prime generate

back(a, n, nr)                      #apeleaza backtracking-ul
