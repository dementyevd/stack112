#include "Stack112.h"

void main() {
	stack112 s(5);
	/*for (size_t i = 0; i < 10; i++)
	{
		s.push('a');
	}*/
	s.push('a');
	cout << s.top() << endl;
	s.top() = 'k';
	cout << s.top() << endl;
	//cout << s.get_max_size();
}