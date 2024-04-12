#include "Tree.h"
#include <iostream>

int main(){
	Tree<int> t(10);
	t.add_node(nullptr, 4);
	t.add_node(nullptr, 2);
	t.add_node(t.get_node(nullptr,1),12);
	t.add_node(nullptr, 3);

	std::cout << t.get_node(nullptr, 0)->val << '\n'
		<< t.get_node(nullptr, 1)->val << ' '
		<< t.get_node(t.get_node(nullptr,1), 0)->val << '\n'
		<< t.get_node(nullptr, 2)->val << "\n\n";
	
	t.delete_node(nullptr, 0);

	std::cout << t.get_node(nullptr, 0)->val << '\n'
		<< t.get_node(nullptr, 1)->val << "\n\n";

	TreeNode<int>* node = t.find([](int a) -> bool {return bool(a == 2);});
	std::cout << t.get_node(node, 0)->val << "\n\n";
	
	t.insert(nullptr, 1, 10);
	std::cout << t.get_node(nullptr, 0)->val << '\n'
		<< t.get_node(nullptr, 1)->val << '\n'
		<< t.get_node(nullptr, 2)->val << "\n\n";

	t.sort(nullptr, nullptr);
	std::cout << t.get_node(nullptr, 0)->val << '\n'
		<< t.get_node(nullptr, 1)->val << '\n'
		<< t.get_node(nullptr, 2)->val << "\n\n";

	std::cout << t.count();
	return 0;
}
