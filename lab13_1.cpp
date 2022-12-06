#include <iostream>

using namespace std;

template <typename T>
int sum(T arg)
{
	return arg;
}

template <typename T, typename ... types>
int sum(T arg, types... args)
{
	return arg + sum(args...);
}

template <typename... args> /*  mysum처럼 재귀호출을 하는게 아니므로 템플릿에 타입 종류도 하나 */
double average(args... nums) /* 함수 인자 종류도 하나도 하나로 했다 */
{
	return sum(nums...) / sizeof...(nums);
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5
	return 0;
}