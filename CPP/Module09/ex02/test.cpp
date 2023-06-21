#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::vector<int>::iterator it = vec.end();
	vec.insert(it, 54);
	std::vector<int>::iterator ite = vec.end();
	for (std::vector<int>::iterator it = vec.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	return (0);
}
