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
class k_queue {
public:
	vector<int> arr;
	vector<int> front;
	vector<int> rear;
	vector<int> next;
	int n, qn;
	int free;
	k_queue(int n, int qn) {
		this->n = n;
		this->qn = qn;
		free = 0;
		for (int i = 0; i < n; i++) {
			arr.push_back(0);
			next.push_back(i + 1);
		}
		next[n - 1] = -1;
		for (int i = 0; i < qn; i++) {
			front.push_back(-1);
			rear.push_back(-1);
		}
	}
	void enqueue(int item, int qn) {
    // we need to insert item at free space
		int insert_at = free;
		free = next[free]; //set next free space
		if (front[qn - 1] == -1) front[qn - 1] = insert_at; // if q is empty, set first element as front
		else {
      // link previous element with current element so that we can track next element
			next[rear[qn - 1]] = insert_at;
		}
		next[insert_at] = -1; //set current index at next equal to -1. it means no next element in current index
		rear[qn - 1] = insert_at; // set current index as rear of queue
		arr[insert_at] = item; // set the item in main array
	}
	int dequeue(int qn) {
		if (front[qn - 1] == -1) {
			cout << "queu is empty" << endl;
		}
		int poped_index = front[qn - 1]; //get the where we need to pop
		front[qn -1] = next[poped_index]; //set next element of poped_index as front
		next[poped_index] = free; //free up poped index 
		free = poped_index; // make poped_index as new free
		int item = arr[poped_index];
		arr[poped_index] = 0;
		return item;
	}
	void display() {
		cout << "main arr: ";
		for (auto i : arr) cout << i << " ";
		cout << endl;
		cout << "top: ";
		for (auto i : front) cout << i << " ";
		cout << endl;
		cout << "rear: ";
		for (auto i : rear) cout << i << " ";
		cout << endl;
	}
};
int main() {
	k_queue ob(5, 3);
	ob.enqueue(22, 2);
	ob.display();
	ob.enqueue(10, 2);
	ob.display();
	ob.enqueue(5, 2);
	ob.display();
	ob.dequeue(2);
	ob.display();

   
	return 0;
}
