#include "MutantStack.hpp"

template <typename Iterator>
void print(Iterator beg, Iterator end)
{
	if (beg != end)
		std::cout << *beg++;
	while (beg != end)
		std::cout << ", " << *beg++;
	std::cout << std::endl;
}

int main()
{
	{
		std::cout << "--- 1 ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(4);

		std::cout << "stack (→) : ";
		print(mstack.begin(), mstack.end());
		std::cout << "stack (←) : ";
		print(mstack.rbegin(), mstack.rend());
		std::cout << "top : " << mstack.top() << std::endl;
		std::cout << "size : " << mstack.size() << std::endl;
		
		mstack.pop();
		std::cout << "* pop *" << std::endl;
		std::cout << "stack (→) : ";
		print(mstack.begin(), mstack.end());
		
		MutantStack<int>::iterator it = mstack.begin();
		++it;
		--it;
		
		std::cout << "--- 2 ---" << std::endl;
		const MutantStack<int> s(mstack);
		std::cout << "stack (→) : ";
		print(s.begin(), s.end());
	}
	{
		std::cout << "--- 3 ---" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		lst.push_back(4);

		std::cout << "list : ";
		print(lst.begin(), lst.end());
	}
}
