#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fstream>


using namespace std;

void proc(char p[], char str_2[], int size)
{
	pid_t pid;
	switch (pid = fork())
	{
		case -1:
			perror("fork");
			exit(1);
		case 0:
			int flag = strcmp(p, str_2);
			if ( flag == 0)
			{
				//nice(-10);
				cout << "///Done!///" << endl;
			}
			exit(getpid());
	}
	
}

void search (string str, char str_2[], int size)
{
	int count = 0;
	char *s = new char[str.size() + 1];
	strcpy(s, str.c_str());
	char *p = strtok(s, " ");
	while (p != NULL)
	{
		ofstream file("home/file2.txt");
		file.write("",0);
		
		if (file.is_open())
		{
			file << p;
		}
		//cout << p << endl;
		
		proc(p, str_2, size);
		p = strtok(NULL, " ");
	}

	delete[] s;
	
}


int main()
{
	string str, str_2;

	char temp;
	ifstream text_file("home/file.txt");
	if (text_file.is_open())
	{
		text_file.unsetf(ios::skipws);
		while (text_file >> temp)
			str += temp;
	}
	else
		return 0;
	cout << str << endl;
	cout << "Enter the search word: ";
	cin >> str_2;
	int size = str_2.length();
	char *s = new char[str_2.size() + 1];
	strcpy(s, str_2.c_str());	

	search(str, s, size);

	text_file.close();
	execl("prog2_2"," ", "Thanks for using", NULL);
	return 0;
}
