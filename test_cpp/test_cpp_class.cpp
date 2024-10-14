#include <ctime>
#include <iostream>

class Test
{
	void priv();
	public:
		static int 	a;
		int 		b;

		Test (void);
		Test ( int _a );
		~Test (void);
		void pub();
};

int Test::a = 0;

Test::Test() : b(a) {
	priv();
	a++;
}
Test::Test(int _a) {
	b = _a;
	priv();
	a++;
}
Test::~Test() {
	std::cout << "Salut dectructor " << b << std::endl;
}

void	Test::priv()
{
	std::cout << "Salut priv " << b << std::endl;
	
}
void	Test::pub()
{
	std::cout << "Salut pub" << std::endl;
	priv();
}

int main(void)
{
	Test t;
	Test t1;
	Test *t2 = new Test();
	Test t3;
	Test *t4 = new Test(38);
	Test t5;

	t.pub();
	std::cout << t.b << std::endl;
	std::cout << t1.b << std::endl;
	std::cout << t2->b << std::endl;
	std::cout << t3.b << std::endl;
	std::cout << t4->b << std::endl;
	std::cout << t5.b << std::endl;

	delete t2;
	delete t4;
	return (0);
}