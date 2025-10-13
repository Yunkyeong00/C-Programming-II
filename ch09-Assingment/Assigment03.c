#include <stdio.h>
#include <ctype.h>

int main()
{
	int i = 0;
	printf("¹®ÀÚ¿­? ");
	char str[70];
	gets_s(str, sizeof(str));

	for (i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i]))
		{
			str[i]=toupper(str[i]);
		}
		else
		{
			str[i]=tolower(str[i]);
			
		}
	}
	str[i]='\0';
	printf("%s", str);
}