#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	// for (int i = 0; i<=100; i++) {
	// 	cout<<i<<"\t\t"<<9.00/5.00*i+32<<endl;
	// }

	// int a;
	// cin>>a;
	// if (a<=1) cout<<"too low number, enter a>1"
	// for (int i=0; pow(4,i)<a; i++){
	// 	if (!(pow(4,i+1)<a)) cout<<i<<endl;
	// }

	// int n,step1, step2;
	// cin>>n;
	// for (int i=0; i<n-2;i++){
	// 	if (i==0) {
	// 		step1 = 0;
	// 		step2 = 1;
	// 		cout<<step1<<"\t"<<step2<<"\t";
	// 	}
	// 	int step = step1+step2;
	// 	step1 = step2;
	// 	step2 = step;
	// 	cout<<step<<"\t";
	// }

	// int num = 1234;
	// cin >> num;
	// int result = 0;
	// for (int i = 10; (num / (i / 10)) != 0; i *= 10)
	// {
	// 	cout << (num % i) / (i / 10) * i << "\t";
	// 	// cout << ((num % i) / (i / 10)) * i;
	// 	// result += ((num % i) / (i / 10)) * i;
	// }
	// cout << endl
	// 	 << result;
	unsigned i = 0;
	for (int i = 2;; i++)
	{
		cout << i;
		if (i > 4)
			break;
	}
	cout << i;
}