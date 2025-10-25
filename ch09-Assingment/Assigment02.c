#include <stdio.h>
#include <string.h>

int main()
{
	
	StrRemove();

	return 0;


}

void StrRemove()
{
	int j = 0;
	printf("문자열? ");
	char str[70];
	gets_s(str, sizeof(str));

	printf("공백문자 제거후: ");

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';

	printf("%s", str);
}