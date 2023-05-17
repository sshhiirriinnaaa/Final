#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// y = a+b-c*d/e
#define vvod(num) {			\
	__asm {					\
		__asm lea eax, num	\
		__asm push eax		\
	}						\
};

int main() {
	int a = 0, b = 0, c = 0, d = 0, e = 0, y = 0;
	char stroka1[] = "Enter 5 numbers:";
	char stroka2[] = "%d%d%d%d%d";
	char stroka3[] = "y = %d";
	vvod(stroka1)
		__asm {
		call printf
		add esp, 4
	}
	vvod(e)
		vvod(d)
		vvod(c)
		vvod(b)
		vvod(a)
		vvod(stroka2)
		__asm {
		call scanf
		add esp, 24
		mov eax, c
		imul eax, d
		mov ebx, e
		cdq
		idiv ebx
		mov ebx, a
		add ebx, b
		sub ebx, eax
		mov y, ebx
		push y
	}
	vvod(stroka3)
		__asm {
		call printf
		add esp, 8
	}
	return 0;
}

