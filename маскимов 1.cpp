#include <iostream>
using namespace std;

class foostring
{
	char* buf;

public:
	
	foostring(const char* buf)
	{
		int size = length(buf);
		this->buf = new char[size];
		for (int i = 0; i < size - 1; i++)
		{
			this->buf[i] = buf[i];
		}
		this->buf[size - 1] = '\0';
	}

	~foostring()
	{
		delete[] buf;
	}

	void show()
	{
		cout << buf;
		
	}

	int length()
	{
		int i = 0;
		while (buf[i] != '\0')
		{
			i++;
		}
		i++;
		return i;
	}

	int length(const char* buf)
	{
		int i = 0;
		while (buf[i] != '\0')
		{
			i++;
		}
		i++;
		return i;
	}

	bool compare(foostring &str)
	{
		if (length() == str.length())
			return true;
		else
			return false;
	}

	bool compare(const char *str)
	{
		if (length() == length(str))
			return true;
		else
			return false;
	}


	void add(foostring &str)
	{
		int i = 0;
		int j = 0;
		char* temp = new char[this->length() + str.length()];
		while (buf[i] != '\0')
		{
			temp[i] = buf[i];
			i++;
		}
		temp[i] = ' ';
		i++;
		while (str.buf[j] != '\0')
		{
			temp[i] = str.buf[j];
			j++;
			i++;
		}
		temp[i] = '\0';
		delete[] buf;
		buf = temp;
		temp = nullptr;
	}

	void add(const char *str)
	{
		int i = 0;
		int j = 0;
		char* temp = new char[length() + length(str)];
		while (buf[i] != '\0')
		{
			temp[i] = buf[i];
			i++;
		}
		temp[i] = ' ';
		i++;
		while (str[j] != '\0')
		{
			temp[i] = str[j];
			i++;
			j++;
		}
		temp[i] = '\0';
		delete[] buf;
		buf = temp;
		temp = nullptr;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	foostring hi("Hello");
	foostring world("world");
	foostring world1("world1");
	cout << "Вариант 1:   ";
	hi.show();
	cout << '\t' << hi.length() << endl;
	cout << "Вариант 2:   ";
	hi.show();
	cout << '\t';
	world.show();
	cout << '\t';
	cout << hi.compare(world) << '\t';
	hi.show();
	cout << '\t';
	world1.show();
	cout << '\t';
	cout << hi.compare(world1) << endl;
	cout << "Вариант 3:   ";
	hi.show();
	cout << '\t';
	world.show();
	cout << '\t';
	cout << hi.compare("world") << '\t';
	hi.show();
	cout << '\t';
	world1.show();
	cout << '\t';
	cout << hi.compare("world1") << endl;
	cout << "Вариант 4:   ";
	hi.show();
	cout << '\t';
	world.show();
	cout << '\t';
	hi.add(world);
	hi.show();
	cout << endl;
	cout << "Вариант 5:   ";
	world.show();
	cout << '\t';
	world1.show();
	cout << '\t';
	world.add("world1");
	world.show();
	cout << endl;
}