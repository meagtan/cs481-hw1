CS 481
HW 1
Ata Deniz Aydın
21502637

The provided makefile compiles the C source files main.c and medstr.c using the GNU C Compiler. After calling 'make', the compiled program may be run by calling './main'. The program relies on the built-in popcnt instruction, supported by Intel processors starting from Nehalem architecture Core i7 processors released in 2008, in order to compute distances between bit sequences more efficiently. As such, the compiler directive includes the flags -march=corei7 and -msse4.2 to compile the __builtin_popcount function call into a popcnt instruction. If, by some chance, the compiled program throws an "Illegal instruction" error, try removing those two flags from the makefile and calling 'make' again. The program was tested to compile and run correctly for the provided datasets on an Intel Core i5 processor from 2012.
