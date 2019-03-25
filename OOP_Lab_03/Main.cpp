#include <iostream>
using namespace std;
#define ARR_SIZE 100 

class Tsili
{
private:
	int *chysla;
	int *kilkist;
public:
	Tsili() {
		kilkist = new int(0);
		chysla = (int *)malloc(ARR_SIZE * sizeof(int));
		//cout << "\n Виконується конструктор... (без параметрів) \n";
	}

	Tsili(int size, int *arr);
	~Tsili() { delete kilkist; delete[] chysla; cout << "\n Виконується деструктор... \n"; };


	void inputMas(int size, ...);
	void outputMas(void);
	Tsili* assoc(Tsili& obj);
	Tsili* diff(Tsili& obj);
	Tsili* inter(Tsili& obj);

};

Tsili::Tsili(int size, int *arr) {
	kilkist = new int(0);
	chysla = (int *)malloc(ARR_SIZE * sizeof(int));

	int i = 0;
	for (i; i < size; i++)
	{
		*(chysla + i) = *(arr + i);
	}
	*kilkist = i;
}


void Tsili::inputMas(int size, ...) {
	int i;
	int *p = (int *)(&size + 1);
	for (i = 0; i < size; i++)
	{
		chysla[i + *kilkist] = *p++;
	}
	*kilkist = *kilkist + i;
}

void Tsili::outputMas() {
	cout << "Множина: ";
	for (int i = 0; i < *kilkist; ++i) {
		cout << chysla[i] << " ";
	}
	cout << "\n";
}

Tsili* Tsili::assoc(Tsili& obj) {
	int chysla2[ARR_SIZE];

	static int counter = 0;

	int count = *kilkist;
	int count2 = 0;

	for (int i = 0; i < *kilkist; i++)
	{
		int flag = 0;
		for (int j = 0; j < *obj.kilkist; j++)
			if (*(chysla + i) == *(obj.chysla + j))
			{
				flag = 1;
				break;
			}
		if (flag == 0) {

			*(chysla2 + count2) = *(chysla + i);
			count2++;
		}
	}

	return new Tsili(count2, chysla2);
}


Tsili* Tsili::diff(Tsili& obj) {
	int chysla2[ARR_SIZE];
	int count2 = 0;
	for (int i = 0; i < *kilkist; i++)
	{
		int flag = 0;
		for (int j = 0; j < *obj.kilkist; j++)
			if (*(chysla + i) == *(obj.chysla + j))
			{
				flag = 1;
				break;
			}
		if (flag == 0) {
			*(chysla2 + count2) = *(chysla + i);
			count2++;
		};
	}
	return new Tsili(count2, chysla2);

}

Tsili* Tsili::inter(Tsili& obj) {
	int chysla2[ARR_SIZE];

	int count2 = 0;
	for (int i = 0; i < *kilkist; i++)
	{
		for (int j = 0; j < *obj.kilkist; j++)
		{

			if (*(chysla + i) == *(obj.chysla + j))
			{
				*(chysla2 + count2) = *(chysla + i);
				count2++;
			}
		}
	}

	return new Tsili(count2, chysla2);
}


int main()
{
	system("chcp 1251");

	int arr[ARR_SIZE] = { 1, 2, 3, 4 };

	Tsili obj1(4, arr);
	Tsili *obj3 = new Tsili;
	obj3->inputMas(3, 12, 13, 14);
	obj1.inputMas(3, 5, 6, 7);

	obj1.outputMas();
	obj3->outputMas();

	cout << "Різниця : ";
	Tsili* obj4 = obj3->diff(obj1);
	obj4->outputMas();
	cout << "Об'єднання : ";
	Tsili* obj5 = obj1.assoc(*obj4);
	obj5->outputMas();
	cout << "Перетин : ";
	Tsili *obj7 = new Tsili();
	obj7->inputMas(4, 14, 13, 18);
	Tsili* obj6 = obj4->inter(*obj7);
	obj6->outputMas();

	delete obj4;
	delete obj5;
	delete obj7;
	delete obj6;

	getchar();
	getchar();

	return 0;
}