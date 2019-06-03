#include <iostream>
#include <windows.h>
#include <string>
const int k = 10;
using namespace std;
struct item {
	int s, c, v;
};

int inputch (int&);
bool foundWay (bool);
bool checkWay (int, int);
struct item graph[k] =
{ 
	{1,2,1},{ 1,3,1 },{ 2,4,1 },{ 2,5,1 },{ 3,6,1 },
	{ 5,7,1 }, {5,6,1}, { 7,10,1 },{ 6,8,1 },{ 8,9,1 }
};

const int n = 11;
int road[n];
bool incl[n];
int way[n];
int waylen;
int start, finish;
bool found;
int len;
int c_len;

int find (int s, int c) { 
		for (int i = 0; i < k; i++)
			if (graph[i].s == s && graph[i].c == c ||
				graph[i].s == c && graph[i].c == s) return graph[i].v;
}


bool step (int s, int f, int p) {
	int c;
	if (s == f) {
		found = true;
		len = c_len;
		waylen = p;
		for (int i = 0; i < waylen; i++) way[i] = road[i];
	}
	else {
		for (c = 0; c < n; c++) {
			int w = find (s, c);
			if (w && !incl[c] && (len == 0 || c_len + w < len)) {
				road[p] = c;
				incl[c] = true;
				c_len += w;
				step (c, f, p + 1);
				road[p] = 0;
				incl[c] = false;
				c_len -= w;
			}
		}
	}
}

int main ()
{
	setlocale (LC_ALL, "rus");
	for (int i = 0; i < n; i++) {
		road[i] = way[i] = 0; incl[i] = false;
	}
	len = c_len = waylen = 0;
	cout << "Введите начальную точку: ", cin >> start;
	inputch (start);
	cout << "Введите конечую точку:	", cin >> finish;
	inputch (finish);
	road[0] = start;
	incl[start] = true;
	found = false;
	checkWay (start, finish);
	foundWay (found);
	system ("pause");
	return 0;
}


int inputch (int &g)
{
	if (cin.fail () || g < 1 || g>k)
	{
		cin.clear ();
		cin.ignore (cin.rdbuf ()->in_avail ());
		//cout << "ќшибка! \n";
		return false;
	}
	else
	{
		return true;
	}
}

bool foundWay (bool foundf)
{
	if (foundf)
	{
		cout << "Ваш путь:	";
		for (int i = 0; i < waylen; i++) cout << way[i] << " -> "; cout << endl;
		return true;
	}
	else
	{
		cout << "Ошибка! Путь не найден!";
		cout << endl;
		return false;
	}
}

bool checkWay (int start, int finish)
{
	bool st = inputch (start);
	bool fin = inputch (finish);
	if (st && fin)
	{
		found = true;
		step (start, finish, 1);
		return true;
	}
	else {
		found = false;
		return false;

	}
}																																				//sshir (ii);



