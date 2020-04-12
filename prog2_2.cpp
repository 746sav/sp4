#include <iostream>
#include <unistd.h>

using namespace std;

int main(int args, char *argv[])

{
	int i = 0;
	while (argv[++i] != NULL)
		cout << argv[i] << endl;
	cout << "CREATOR: Smokotina A.V." << endl;
	return 1;
}
