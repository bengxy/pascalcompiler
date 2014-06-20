pascal compiler
==============

###discription

A simple MIPS compiler of pascal

author [@bengxy](https://github.com/bengxy) [@chenchengcc](https://github.com/ChenChengCC)  of Zhejiang University.

==============

Use lex and yacc to generate the parse tree.


<li>Files in [/pasTest](https://github.com/bengxy/pascalcompiler/tree/master/pasTest) are some test samples.
<li>Files in [/mipsAsmTestcase](https://github.com/bengxy/pascalcompiler/tree/master/mipsAsmTestcase) are MIPS asm result.

Syntax is standard MIPS and accord with [Mars](http://courses.missouristate.edu/KenVollmar/MARS/).

Mars is included in the pascalcompiler file.



###help

==============
Use g++ compile all the *.c and *.cpp file together to get a result file pasasm.out

And use  <br>
./pasasm.out < source.pas > generate.asm <br>
to get a  asm file.
