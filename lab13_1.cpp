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

template <typename... args> /*  mysumó�� ���ȣ���� �ϴ°� �ƴϹǷ� ���ø��� Ÿ�� ������ �ϳ� */
double average(args... nums) /* �Լ� ���� ������ �ϳ��� �ϳ��� �ߴ� */
{
	return sum(nums...) / sizeof...(nums);
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5
	return 0;
}