#include "declare.h"
#include "symbolTable.h"

#include <cstdio>
#include <iostream>

using namespace lwd;
using namespace std;

void asm_init() {
	cout <<
".macro print_int (%x)\n\
	li $v0, 1\n\
	add $a0, $zero, %x\n\
	syscall\n\
.end_macro\n\n\
.macro print_char (%x)\n\
	li $v0, 11\n\
	add $a0, $zero, %x\n\
	syscall\n\
.end_macro\n\n\
.macro print_str (%str)\n\
	.data\n\
		myLabel: .asciiz %str\n\n\
	.text\n\
	li $v0, 4\n\
	la $a0, myLabel\n\
	syscall\n\
.end_macro" << endl;

	cout << "addi $sp, $sp,   -100" << endl;
	cout << "add  $fp, $zero, $sp" << endl;
}

void asm_clean() {
	cout << "addi $sp, $sp, 100" << endl;
}

int main(int argc, char *argv[]) {
	//extern int yydebug;
	//yydebug = 1;	

	if(yyparse()) {
		fprintf(stderr, "\n");
		return 1;
	}
	fprintf(stderr, "parse complete\n");

	program *root = savedRoot;
	if(!root->semanticCheck(gtable.insertScope())) {
		fprintf(stderr, "semantic error.\n");
		return 1;
	}
	fprintf(stderr, "semantic check complete.\n");

	asm_init();
	cout << root->cgen() << endl;
	//asm_clean();

	return 0;
}
