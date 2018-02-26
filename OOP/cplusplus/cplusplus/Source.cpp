#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int find(vector<int> v, int value)
{
	auto it = find_if(v.begin(), v.end(), [value](int &x) {return x == value; });
	if (it == v.end())
		return -1;
	else
		return distance(v.begin(), it);
}



/*int main() {
	std::vector<int> foo = { 25,15,5,-5,-15 };
	/*std::vector<int> bar(foo.size());

	// copy only positive numbers:
	auto it = std::copy_if(foo.begin(), foo.end(), bar.begin(), [](int i) {return !(i<0); });
	bar.resize(std::distance(bar.begin(), it));  // shrink container to new size

	std::cout << std::distance(bar.begin(), it);
	std::cout << "bar contains:";
	for (int& x : bar) std::cout << ' ' << x;
	std::cout << '\n\n';*/

/*	cout << find(foo, 25) << "\n"
		<< find(foo, -15) << "\n"
		<< find(foo, 16) << "\n\n";

	for_each(foo.begin(), foo.end(), [](int &x) {cout << x << " "; });
	cout << "\n";

	system("pause");
	return 0;
}*/