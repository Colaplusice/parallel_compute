#include <iostream>
using namespace std;
void s(char *str, int *t, int n, int num)
{
	if (n == num)
	{
		cout << "{";
		for (int i = 0; i<num; i++)
			if (t[i] == 1)
				cout << str[i];
		cout << "}" << endl;
		return;
	}
	t[n] = 0;
	s(str, t, n + 1, num);
	t[n] = 1;
	s(str, t, n + 1, num);
}
int main()
{
	int num = 3;
	char a[3] = {'a','b','c'};
	int t[3];
	s(a, t, 0, num);
	return 0;
}
