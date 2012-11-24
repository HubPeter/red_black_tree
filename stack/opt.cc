#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
	stack<int> s;
	s.push( 9 );
	s.push( 10 );
	s.push( 12 );
	int n = s.top();
	cout<<n<<endl;
	return 0;
}
