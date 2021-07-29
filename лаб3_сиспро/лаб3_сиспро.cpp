#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;

/*8)
b ^ 2 / a + 5,	если	a > b; 
= -5,	если	a = b;
(a *b - b) / b,	если	a < b;
*/

int main()
{
	
		int a, b, null = 0, ofs = 0, result;

		cout << "Enter a> ";
		cin >> a;
		cout << "Enter b> ";
		cin >> b;
		__asm
		{
			mov ecx, a; ecx = a
			mov ebx, b; ebx = b
			cmp ecx, ebx
			jg l_bigger; если a > b
			jl l_smaller; если a < b
			mov eax, -5; eax = -5

			jmp END

			l_bigger:
				
			or ecx, ecx; проверка а деления на 0
				jz er_z
				mov eax, ebx; eax = b
				imul eax; eax = b * b
				jo errorOF

				jz er_z
				cdq
				idiv ecx; b* b / a
				add eax, 5; b* b / a
				jmp END


				l_smaller:
			or ebx, ebx
				jz er_z
				mov eax, a; eax = a
				imul ebx; a* b
				jo errorOF
				sub eax, ebx;a* b - b

				jz er_z
				cdq
				idiv ebx; (a* b - b)/b
				
				jmp END


			jmp e1;
		er_z:
		mov null, 1;
	e1:

		jmp e2;
		errorOF:
		mov edx, ofs;
		inc edx;
	mov ofs, edx;
	e2:
		
				END:
			mov result, eax;
		}
		if (ofs == 1)
			cout << endl << "Out of size\n" << endl;
		else if (null == 1)
			cout << "Division by zero\n" << endl;

		else 
			cout << "Result asm> " << result << endl;

		
	return 0;
}