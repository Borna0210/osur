#include <header.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#define MAX_BUF 200

int main()
{
	printf("\n");
	char path[MAX_BUF];
	getcwd(path, MAX_BUF);
	cut(path);
	printf("%s\n", strcat(path, "/Main-program"));

	Split();
	Zagreb();

	return 0;
}

void cut(char *cwd)
{
	int slash_count = 0;
	int i;
	for (i = 0; cwd[i] != '\0'; i++)
	{
		if (cwd[i] == '/')
		{
			slash_count++;
			if (slash_count == 8)
			{
				break;
			}
		}
	}

	// Copy the remaining cwding starting from the 8th slash
	int j;
	for (j = 0; cwd[i + j + 1] != '\0'; j++)
	{
		cwd[j] = cwd[i + j + 1];
	}
	cwd[j] = '\0';
}