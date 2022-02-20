#include <iostream>
#include<queue>
using namespace std;
 
int main() {
    queue<int>q;
    q.push(1);
    q.push(2);
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.empty();
    
	// your code goes here
	return 0;
}
