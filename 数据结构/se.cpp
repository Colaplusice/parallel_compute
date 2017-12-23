#include <iostream>
using namespace std;
int n = 0;

void swap(char *a, char *b)
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}

void p(char list[], int k, int m)
{
	int i;
	if (k >m)
	{
		for (i = 0; i <= m; i++)
		{
			cout << list[i];

		}
		cout << endl;
		n++;
	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(&list[k], &list[i]);
			p(list, k + 1, m);
			swap(&list[k], &list[i]);
		}
	}
}

int main()
{
	char list[] = "12345";
	p(list, 0, 4);
	cout << ":" << n <<endl;
	return 0;
}
