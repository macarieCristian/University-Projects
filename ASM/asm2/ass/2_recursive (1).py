'''
Back-ul recursiv de bazeaza pe un if si un for.
If-ul inlocuieste practic functia solution de la iterativ, in sensul
ca atunci cand intri in functia back, if-ul verifica daca stack-uk curent e solutie, daca da, o scrie, daca nu, intra
pe else si in else e for-ul.
Forul inlocuieste intr-un fel functia value de la iterativ.

Incearca sa te uiti in paralel la romanul asta de deasupra cu comentariile aferente din functia back ca sigur
intelegi mai bine.

La permutari, de exemplu, if-ul verifica daca nivel = n - 1. Daca da, e solutie, daca nu, intra pe else.
La problema asta, stack-ul e solutie daca suma elementelor e egala cu n, asa ca am pus un parametru in plus
back-ului care se cheama total si in care am la fiecare pas suma elementelor. Ala incepe de pe 0 si de fiecare
data cand adauga un element in stack, cand apeleaza back-ul apeleaza cu total + elementul nou. Altfel, ai putea
sa calculezi de fiecare data inainte de if suma elementelor si sa verifici asa si renunti la unul din
parametri, dar e mult mai eficient daca nu are de facut calculul ala la fiecare apel.

For-ul merge pe fiecare numar ce se poate pune pe un nivel. Spuneam ieri ca e mult mai usor sa vezi
elementele ca pozitii ale numerelor din vectorul in care ai numerele prime. Aici e foarte folositoare chestia
asta, in sensul ca for-ul in mod normal merge de pas +1. Deci daca vrei sa faci fara sa ai separat vectrul
de numere prime si ai pune (ipotetic) n = 25, poti sa iei i de la 1 la 25 si la fiecare i sa verifici daca e prim,
daca e sa il validezi, dupa sa il adaugi in stack si tot asa. Dar daca ai ca ieri un vector in care ai deja numerele
prime pana la 25 (care sunt in nr de 9 CRED), atunci for-ul ala o sa mearga doar de la 1 la 9, deci sunt mult mai
putini pasi. Sper ca sunt coerenta :)).

Anyway, deci for-ul la fiecare apel face i+1 si incearca sa puna valoarea i-ului in stack. Spre deosebire de 
iterativ, asta nu pune valoarea acolo si dupa aia o valideaza, ci intai o valideaza si daca e buna ii da append
la stack. Deci ai un i, apeleaza cu i-ul ala functia de validare si vede daca e ok si daca e, il adauga la
stack, creste nivelul, apeleaza back pt nivelul urmator si face aceeasi chestie pt nivelul nou.
Find recursiva, o sa tot apeleze chestii si cand termina pe un nivel, se intoarce in apelul dinainte de unde o
ramas, adica (uita-te la cod la partea asta) in else, in for, in if, dupa apelul lui back. Adica atunci cand
se intoarce pe nivelul precedent, ajunge pe linia cu del stack[-1], linie care sterge nivelul pe care o fost
inainte.
Cand se termina valorile din for, se intoarce pe nivelul precedent si tot asa pana nu mai are pe ce nivel sa
se intoarca si iese din back.
'''


def isPrime(x):
    d = 2
    while d <= x / 2:
        if x % d == 0:
            return False
        d = d + 1
        
    return True

def generatePrimeNumbers(n):
    result = [0]
    if 2 <= n:
        result.append(2)
        
    x = 3
    while x <= n:
        if isPrime(x) == True:
            result.append(x)
        x = x + 2
        
    return result

def validate(new, k, stack, total, n):
    '''
    Valizeaza elementul nou.
    input - new, elementul nou pe care vrem sa il validam.
          - k, nivelul pe care incercam sa il punem pe new
          - stack - stack
          - total, suma elementelor de pana acuma, am dat-o ca parametru ca sa nu o mai calculez de fiecare
          data cand intru in validate, dar se putea si calcula daca nu o vrei ca parametru
          - n, suma ce trebe obtinuta
    output - True or False
    
    Asta merge la fel ca ieri, cu diferenta ca nu verifica daca stack[k] e valid, ci daca new e valid. Doar daca
functia asta returneaza True o sa il adauge pe new la stack.
    '''
    ok = True
    
    if k > 0 and new < stack[-1]:
        ok = False
        
    if ok == True:
        if total + new > n:
            ok = False
        
    return ok

def printSolution(k, stack, a):
    result = ''
    
    for i in range(0, k):
        result = result + str(a[stack[i]]) + ' '
        
    print(result)
    
def back(k, stack, total, a, n, nr):
    '''
    'Creierul' :))
    
    input - k - nivelul pe care incercam sa punem valoare
          - stack - stack-ul curent
          - total - suma curenta a elementelor din stack
          - a - vectorul cu numere prime
          - n - suma ce trebe obtinuta
          - nr - nr de numere prime din a
          
    '''
    
    if total == n:                                              #daca suma curenta a elementelor = n, stack-ul e solutie
        back.count = back.count + 1                             #asta e ca number de ieri, adica numara daca avem vreo solutie
        printSolution(k, stack, a)                              #apeleaza functia de tiparit
    else:                                                       #daca nu e solutie, intra pe else
        for i in range(1, nr):                                  #for-ul merge de la 1 la nr maxim de numere prime
            if validate(i, k, stack, total, n) == True:         #valideaza i-ul, daca e bun, intra pe if, daca nu
                                                                #se intoarce la for si face i + 1
                stack.append(i)                                 #daca i-ul e ok, il adauga la stack
                back(k + 1, stack, total + a[i], a, n, nr)      #apeleza back de noile valori
                                                                    #k + 1  -> nivelul creste cu 1
                                                                    #total + a[i]  -> suma elementelor creste cu noul
                                                                    #nr prim pe care l-am adaugat, adica a[i]
                del stack[-1]                                   #cand se intoarce din apelul de mai sus, ajunge
                                                                #aici, unde sterge nivelul urmator si continua
                                                                #for-ul de pe nivelul asta    
    
n = int(input('Give n: '))
a = generatePrimeNumbers(n)
nr = len(a)

stack = []

back.count = 0                      #fiind recursiva nu mergea cu number = 0 inauntrul back-ului pentru ca ala
                                    #se tot suprascria. Chestia asta am luat-o de pe stackoverflow

back(0, stack, 0, a, n, nr)         #primul 0 e k, adica nivelul si incepe de pe 0
                                    #al doilea 0 e total, adica suma elementelor si incepe de pe 0

if back.count == 0:
    print('No solution.')