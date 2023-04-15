#include <iostream>
#include <vector>

using namespace std;

enum BookType
{
	ART,
	TECH
};

class Book
{
	const string _author;
	const string _name;
	const BookType _type;
public:
	Book(const string& author, const string& name, BookType type) : _author(author), _name(name), _type(type) {}
	BookType GetType() const { return _type; }
	string GetAuthor() const { return _author; }
	string GetName() const { return _name; }
	void Print() const
	{
		cout << _author << " " << _name << " ";
		if (_type == ART)
			cout << "(Art)";
		else if (_type == TECH)
			cout << "(Tech)";
		cout << endl;
	}
};

void kolvo(const vector<Book*>& library)
{
	int art_q = 0;
	int tech_q = 0;

	for (int i = 0; i < library.size(); i++)
	{
		switch (library[i]->GetType())
		{
		case ART:
			art_q++;
			break;
		case TECH:
			tech_q++;
			break;
		}
	}
	cout << "Art Books: " << art_q << endl;
	cout << "Tech Books: " << tech_q << endl;
}

//Без свитча:
//void kolvo(const vector<Book*>& library)
//{
// int art_q = 0;
// int tech_q = 0;

// for (int i = 0; i < library.size(); i++)
// {
// if (library[i]->GetType() == ART)
// art_q++;
// else if (library[i]->GetType() == TECH)
// tech_q++;
// }
// cout « "Art Books: " « art_q « endl;
// cout « "Tech Books: " « tech_q « endl;
//}


int main()
{
	vector<Book*> library =
	{
	new Book("Jane Austen", "Pride and Prejudice", ART),
	new Book("Richard Bronson and Gabriel B. Costa", "Linear Algebra an Introduction Second Edition", TECH),
	new Book("Fyodor Dostoyevsky", "Crime and Punishment", ART)
	};

	for (int i = 0; i < library.size(); i++)
	{
		if (library[i]->GetAuthor().empty() || library[i]->GetName().empty())
		{
			delete library[i];
			library[i] = nullptr;
		}
		else
		{
			library[i]->Print();
		}
	}

	kolvo(library);

	for (int i = 0; i < library.size(); i++)
	{
		delete library[i];
	}

	return 0;
}