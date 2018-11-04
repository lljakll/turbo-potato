#include <list>
#include <iostream>

using namespace std;

template<class T>
void printList(const list<T>& lst, char *s) {
	cout << s << ":  ";
	for (typename list<T>::const_iterator i = lst.begin(); i != lst.end(); i++)
		cout << *i << ' ';
	cout << endl;
}

int main() {

	list<int> list1;
	list<int> list2(4, 7);

	for (int i = 0; i < 5; i++) {
		list1.push_back(i);
	}

	printList(list1, "list1");
	printList(list2, "list2");

	list1.merge(list2);

	printList(list1, "list1");

	system("pause");
	return 0;
}
