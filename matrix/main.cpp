#include "m.h"
#include <iostream>

int main() {
	M m;
	m.print();
	M n(2, 2);
	n.print();
	M o(1);
	o.print();
	M p("1 2 3 4 5 6 7 8 9");
	p.print();
	M j = p + M("1 2 3 4 5 6 7 8 9");
	j.print();
	M d = p - o;
	d.print();
	M jorj = p - 2;
	jorj.print();

	return 0;
}