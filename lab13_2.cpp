#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template <typename ForwardIterator, typename Compare> //템플릿 선언
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) { //버블정렬 구현
	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}

struct compGreater {//오름차순
	bool operator() (int x, int y) const { //operator 구현
		return x < y;
	}
};

struct compLess {//내림차순
	bool operator() (int x, int y) const { //operator 구현
		return x > y;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 }; 

	std::cout << "오름차순 정렬" << std::endl;
	compGreater compGreater; //Functor 생성
	bubble_sort(values.begin(), values.end(), compGreater); //내림차순 정렬
	
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	} //iterator를 이용해 정렬된 결과 출력
	std::cout << std::endl;


	std::cout << "내림차순 정렬" << std::endl;
	compLess compLess; //Functor 생성
	bubble_sort(values.begin(), values.end(), compLess); //오름차순 정렬

	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	} //iterator를 이용해 정렬된 결과 출력
	std::cout << std::endl;

	getchar();
}
