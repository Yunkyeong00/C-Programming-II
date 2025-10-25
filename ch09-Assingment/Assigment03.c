#include <stdio.h>
#include <ctype.h>

void StrChange();

int main()
{
	StrChange();

	return 0;
}

void StrChange()
{
	int i = 0;
	printf("문자열?: ");
	char str[70];
	gets_s(str, sizeof(str));

	for (i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
		else
		{
			str[i] = tolower(str[i]);

		}
	}
	str[i] = '\0';
	printf("%s", str);
}