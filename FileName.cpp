#include<iostream>
#include<memory>
#include<vector>

template<class T,int N,class... Arg>
std::shared_ptr<T> Grobal(const Arg&& ...A) {
	static std::shared_ptr<T> R = std::make_shared<T>(A...);

	return R;
}

#define g Grobal


struct AB {
	int A = 0;
	int B = 0;
};


int main() {
	(*g<int, 0>()) = 12;

	g<AB,0>()->A = 100;

	std::cout << (g<AB, 0>()->A) << std::endl;
	std::cout << (g<AB, 0>()->B) << std::endl;

	std::cout <<"End Of PG." << std::endl;
}