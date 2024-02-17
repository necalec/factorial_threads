
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void factorial(int min, int max, unsigned __int64& result)
{
	for (int i = min; i < max; i++)
	{
		result *= i;
	}
}

int main(int argc, char* argv[])
{
	int size_factorial;
	cout << "print size of factorial, 0 == break program" << endl;
	cin >> size_factorial;
	if (size_factorial == 0) {
		cout << "Factorial of " << size_factorial << " is: " << 1 << endl;
	}

	while (size_factorial != 0)
	{
		int size_case = size_factorial / 3;
		int case1 = (size_factorial % 3) + size_case + 1;
		int case2 = size_case;
		int case3 = size_case--;

		vector <unsigned __int64> results(3, 1);

		thread thr1(factorial, 1, case1, ref(results[0]));
		thread thr2(factorial, case1, case1 + case2, ref(results[1]));
		thread thr3(factorial, case1 + case2, size_factorial + 1, ref(results[2]));

		thr1.join();
		thr2.join();
		thr3.join();

		unsigned long long total_result = results[0] * results[1] * results[2];
		cout << "Factorial of " << size_factorial << " is: " << total_result << endl;

		cout << "print size of factorial, 0 == break program" << endl;
		cin >> size_factorial;
	}

	return 0;
}