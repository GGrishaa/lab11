#include <iostream>
#include <deque>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
using  namespace std;

template <typename T>
void input(T &a){
    cout << "How much elements in collection?" << endl;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
}


int main(){
	/*						№0 - base						*/
    deque<int> base1;
    input(base1);
	cout << "base1: ";
	for(auto element : base1){
		cout << element << " ";
	}
	cout << endl;
	deque<int> base2;
	input(base2);
	cout << "base2: ";
	for(auto element : base2){
		cout << element << " ";
	}
	cout << endl;



	cout << endl << "						№1 - algorithms						" << endl;
	cout << "sorting: ";
	if(is_sorted(base1.begin(), base1.end())){
		cout << "base1 is already sorted: ";
	}
	else{
		sort(base1.begin(), base1.end());
	}
	for(auto element : base1){
		cout << element << " ";
	}
	reverse(base1.begin(), base1.end() - 1);
	cout << endl << "reverse sorting excluding last element: ";
	for(auto element : base1){
		cout << element << " ";
	}
	cout << endl << "counting: there are " << count(base2.begin(), base2.end(), 0) << " 0 in base2" << endl;
	cout << "finding: 10 is element " << find(base2.begin(), base2.end(), 10) - base2.begin() << " in base2" << endl;
	vector<int> ones;
	ones.resize(7);
	fill(ones.begin(), ones.end(), 1);
	cout << "auto filled vector: ";
	for(vector<int>::iterator iter = ones.begin(); iter != ones.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;



	cout << endl << "						№2 - inserting						" << endl;
	cout << "back inserter: ";
	copy(base1.begin(), base1.end(), back_inserter(base2));
	for(deque<int>::iterator iter = base2.begin(); iter != base2.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl << "front inserter: ";
	copy(base1.begin(), base1.end(), front_inserter(base2));
	for(deque<int>::iterator iter = base2.begin(); iter != base2.end(); iter++){
	 	cout << *iter << " ";
	}
	cout << endl << "inserter: ";
	copy(base1.begin(), base1.end(), inserter(base2, base2.begin() + 5));
	for(deque<int>::iterator iter = base2.begin(); iter != base2.end(); iter++){
	 	cout << *iter << " ";
	}



	cout << endl << endl << "						№3 - files						" << endl;
	ifstream inpf;
	deque<char> d1;
	d1.resize(10);
	inpf.open("/Users/grigorijmironov/Desktop/c++/example.txt");
	istreambuf_iterator<char> first(inpf);
	istreambuf_iterator<char> last;
	copy(first, last, d1.begin());
	cout << "reading file example.txt: ";
	for(auto element : d1){
		cout << element << " ";
	}
	cout << endl;
	inpf.close();

	ofstream outf;
	deque<char> d2;
	d2.resize(10);
	fill(d2.begin(), d2.end(), 'I');
	outf.open("/Users/grigorijmironov/Desktop/c++/outex.txt");
	ostreambuf_iterator<char> start(outf);
	copy(d2.begin(), d2.end(), start);
	outf.close();
	cout << "we read information from d2 and write it in otex " << endl;



	cout << endl << "						№4 - containers						" << endl;
	vector<int> v;
	deque<int> d;
	input(v);
	d.insert(d.end(), v.begin(), v.end());
	for(deque<int>::iterator iter = d.begin(); iter != d.end(); iter++){
		cout << *iter << " ";
	}



	cout << endl << endl << "						№5 - reversing						" << endl;
	deque<int> base;
	base.resize(base1.size() + base2.size());
	cout << "base: ";
	merge(base1.begin(), base1.end(), base2.begin(), base2.end(), base.begin());
	for(auto element : base){
		cout << element << " ";
	}
	cout << endl << "reversed base: ";
	for(deque<int>::reverse_iterator iter = base.rbegin(); iter != base.rend(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
    return 0;
}