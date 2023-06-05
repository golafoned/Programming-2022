#include <iostream>
#include <string>
using namespace std;
enum DogBreeds
{
	SHPIC,
	HASKY,
	TAKSA,
	MOPS
};

void add_breed(DogBreeds *array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		array[i] = DogBreeds(rand() % 3);
	}
}

void print_breeds(DogBreeds *array_breeds, int n)
{
	for (int i = 0; i < n; ++i)
	{
		switch (array_breeds[i])
		{
		case 0:
			cout << "Breed -- Shpic" << endl;
			break;
		case 1:
			cout << "Breed -- HASKY" << endl;
			break;
		case 2:
			cout << "Breed -- TAKSA" << endl;
			break;
		case 3:
			cout << "Breed -- MOPS" << endl;
			break;
		default:
			cout << "There isnt breed" << endl;
			break;
		}
	}
}

// DogBreeds str_to_dogbreeds(string a) {
// 	toupper(a)
// }

int main()
{
	int n;
	cout << "Enter n: " << endl;
	cin >> n;
	DogBreeds *array_breeds = new DogBreeds[n];
	add_breed(array_breeds, n);
	print_breeds(array_breeds, n);

	string breed;
	cout << "Input breed name " << endl;
	getline(cin, breed);
}