#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
class k_stacks {
public:
	vector<int> arr; // actual array to store contents
	vector<int> top; // to store top element of stack
	vector<int> next; // this will store next available space and also  will store stack top's previous element
	int n, k;
	int free;
	k_stacks(int n, int k) {
		this->n = n;
		this->k = k;
		free = 0;
		for (int i = 0; i < n; i++) {
			arr.push_back(0);
		}
		for (int i = 0; i < k; i++) {
			top.push_back(-1);
		}
		for (int i = 0; i < n; i++) {
			next.push_back(i + 1);
		}
		next[n - 1] = -1; //no spot left in the last
	}
	void push(int k, int item) {
		int insert_at = free;
		free = next[free]; // checking next spot available
		arr[insert_at] = item;
		next[insert_at] = top[k - 1]; // linking to previous element
		top[k - 1] = insert_at; // storing stack top element index of arr
	}
	void print() {
		cout << "arr: ";
		for (auto i : arr) {
			cout << i << " ";
		}
		cout << endl;
		for (auto i : top) {
			cout << i << " ";
		}
	}
	void pop(int k) {
		int poped_index = top[k - 1]; // get the stack top element index
		int poped_item = arr[poped_index]; // pop the item
		arr[poped_index] = 0;
		top[k - 1] = next[poped_index]; // making previous element as top
		next[poped_index] = free; // free the currently poped item space
		free = poped_index;
		cout << "poped item: " <<  poped_item << endl;
	}

};
int main() {
	k_stacks ob(5, 3);
	ob.push(2, 10);
	ob.push(2, 15);
	ob.push(3, 11);
	ob.push(3, 12);
	ob.pop(3);
	ob.print();
	
    
	return 0;
}
