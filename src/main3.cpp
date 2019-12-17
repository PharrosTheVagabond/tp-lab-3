#include "datetime.h"
#include <iostream>

int main() {
	DateTime foo(10, 12, 2018);
	DateTime bar;
	DateTime foo2(foo);
	std::cout << foo.getToday() << "; " << bar.getToday() << std::endl;
	std::cout << foo.getFuture(732) << "; " << bar.getPast(6) << std::endl;
	std::cout << foo.getDifference(bar) << "; " << foo.getDifference(foo2) << std::endl;
	return 0;
}