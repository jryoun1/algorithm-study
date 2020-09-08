#include<iostream>
#include<vector>

using namespace std;

struct inputData {
	int L;
	int P;
	int V;
};

vector<inputData> input;
int l, p, v;
inputData tmpInput;


int Solution(int i)
{	
	int tmp = input[i].V % input[i].P;
	if (tmp > input[i].L)
		return input[i].V / input[i].P * input[i].L + input[i].L;
	else
		return input[i].V / input[i].P * input[i].L + tmp;

}

int main()
{
	
	
	do  {		
		cin >> l>> p>> v;
		tmpInput.L = l;
		tmpInput.P = p;
		tmpInput.V = v;
		input.push_back(tmpInput);
	} while (l != 0 && p != 0 && v != 0);

	for (int i = 0; i < input.size() - 1; i++)
	{
		printf("Case %d: %d\n", i + 1, Solution(i));
	}


	return 0;
}