#include<iostream>
#include<cstdlib>
#include<fstream>
#include<list>
#include<time.h>
using namespace std;

class HebbRule {

public:
	int size;
	int inputSize;
	int iterations;
	double **inputs;
	double *weights;
	double eta=0.3;
	double calculateValue(double sum);
	void InitializeWeights();
	void learnNeuron();
	void  testNetwork(int *testTable, char znak, int index);
	int letterID;
	char letter;
	double output;
	HebbRule();
};

HebbRule::HebbRule(){

	fstream plik;
	plik.open("zbior_uczacy1.txt");
	if (plik.good())
	{
		inputSize = 35;
		size = 20;
		inputs = new double*[size];
		for (int i = 0;i < size;i++)
			inputs[i] = new double[inputSize];

		double *result = new double[inputSize];
		weights = new double[inputSize];

		
		for (int k = 0; k < size; k++)
		{
			for (int i = 0; i < inputSize; i++)
			{
				plik >> inputs[k][i];
			}
		}
	}
	else
	{
		cout << "blad otwarcia pliku!";
	}
}

double HebbRule::calculateValue(double sum) {

	if (sum >= 0)
		return 1;
	else
		return 0;
}

void HebbRule::InitializeWeights() {

	for (int i = 0; i < inputSize; i++)
	{
		weights[i] = -1 + (double)rand() / RAND_MAX* (2);
	}
}

void HebbRule::testNetwork(int *testTable, char znak, int index)
{
	double sum = 0;
	for (int i = 0; i < inputSize; i++)
		sum += (testTable[i] * weights[i]);
	cout << "      "  << znak << " :" << calculateValue(sum) << endl;
}

void HebbRule::learnNeuron() {

	InitializeWeights();
	double y = 0;
	double s = 0;
	iterations = 50;

	for (int i = 0; i < iterations; i++)
	{
		for (int j = 0; j <size; j++)
		{
			for (int k = 0; k < inputSize; k++)
			{
				y += (inputs[j][k] * weights[k]);
			}
			s = calculateValue(y);
			for (int k = 0; k < inputSize; k++)
			{
				weights[k] = weights[k]*0.9+eta*s*inputs[j][k];
			}
		}	
	}	
}

int main()
{
	srand(time(NULL));
	HebbRule A,B,C,D,E;
	A.learnNeuron();
	B.learnNeuron();
	C.learnNeuron();
	D.learnNeuron();
	E.learnNeuron();
	int tab3[35] = { 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0 }; //D
	int tab8[35] = { 0, 1, 1, 1, 0, 0, 0, 1, 0, 0 ,0, 0, 1, 0 ,0 ,0, 0 ,1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0 }; //I
	int tab12[35] = { 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1 }; //M
	int tab18[35] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0 }; //S
	int tab1[35] = { 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0 }; //B
	int tab4[35] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1 }; //E

	
	A.testNetwork(tab3, 'D', 2);
	A.testNetwork(tab8, 'I', 8);
	A.testNetwork(tab12, 'M', 12);
	A.testNetwork(tab18, 'S', 18);
	A.testNetwork(tab1, 'B', 1);
	A.testNetwork(tab4, 'E', 4);
	cout << endl;
	B.testNetwork(tab3, 'D', 2);
	B.testNetwork(tab8, 'I', 8);
	B.testNetwork(tab12, 'M', 12);
	B.testNetwork(tab18, 'S', 18);
	B.testNetwork(tab1, 'B', 1);
	B.testNetwork(tab4, 'E', 4);
	cout << endl;
	C.testNetwork(tab3, 'D', 2);
	C.testNetwork(tab8, 'I', 8);
	C.testNetwork(tab12, 'M', 12);
	C.testNetwork(tab18, 'S', 18);
	C.testNetwork(tab1, 'B', 1);
	C.testNetwork(tab4, 'E', 4);
	cout << endl;
	D.testNetwork(tab3, 'D', 2);
	D.testNetwork(tab8, 'I', 8);
	D.testNetwork(tab12, 'M', 12);
	D.testNetwork(tab18, 'S', 18);
	D.testNetwork(tab1, 'B', 1);
	D.testNetwork(tab4, 'E', 4);
	cout << endl;
	E.testNetwork(tab3, 'D', 2);
	E.testNetwork(tab8, 'I', 8);
	E.testNetwork(tab12, 'M', 12);
	E.testNetwork(tab18, 'S', 18);
	E.testNetwork(tab1, 'B', 1);
	E.testNetwork(tab4, 'E', 4);

	getchar();
}
