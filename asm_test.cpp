#include <iostream>

int main()
{
	int a[4];
	short b[4];
	unsigned int c[4];
	unsigned short d[4];
	char p[4];
	unsigned char q[4];

	_asm
	{
		//	a)
		MOV EAX, dword[a[0]]
		ADD EAX, word[b[0]]
		ADD EAX, word[b[1]]
		SUB EAX, word[b[2]]
		//	b)
		MOV EBX, byte[p[0]]
		ADD EBX, EAX
		ADD EBX, word[d[3]]
		//	c)
		XOR EAX, EAX
		XOR EBX, EBX
		MOV EAX, word[b[0]]
		ADD EAX, byte[p[2]]
		ADD EAX, byte[q[3]]
		//	d)
		XOR EAX, EAX
		MOV EAX, dword[a[0]]
		DIV dword[a[1]]
		//	e)
		XOR EAX, EAX
		XOR EDX, EDX
		MOV EBX, dword[a[0]]
		MOV EAX, dword[a[3]]
		DIV dword[a[2]]
		ADD EBX, EAX
		//	f)
		XOR EAX, EAX
		XOR EBX, EBX
		XOR EDX, EDX
		MOV EAX, dword[a[1]]
		MOV EBX, word[b[0]]
		MUL EBX, word[b[1]]
		ADD EAX, EBX
		XOR EBX, EBX
		//	g)
		XOR EAX, EAX
		MOV EAX, dword[a[0]]
		MOV EBX, dword[a[1]]
		MOV ECX, dword[a[2]]
		DIV ECX
		MOV EAX, EDX
		XOR EBX, EBX
		XOR ECX, ECX
	}
}
