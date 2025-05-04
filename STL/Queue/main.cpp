#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;

void print(priority_queue<int> &pq){
    while(!pq.empty()){
        cout<<pq.top()<<" "<<endl;
        pq.pop();
    }
    cout<<endl;
}

void print_back(deque<int> q){
    cout<<" Deque elements back ";
    while(!q.empty()){
        cout<<q.back()<<" ";
        q.pop_back();
    }
    cout<<endl;
}

void print_front(deque<int> &q){
    cout<<" Deque elements front ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}

void print_stack(stack<string> &s){
    cout<<"Stack elements"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" "<<endl;
        s.pop();
    }
    cout<<endl;
}

struct last_k_numbers_sum_stream{
    int k;
    deque<int> q;
    last_k_numbers_sum_stream(int K){
        k = K;
    }
    int sum(int s){
        q.push_back(s);
        if(q.size()>k){
            q.pop_front();
            return q[0]+q[1]+q[2]+q[3];
        } else {
            return 0;
        }
    }
};


int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"Last element in queue"<<q.back()<<endl;
    while(!q.empty()){
        cout<<" front() "<<q.front()<<" ";
        q.pop();
    }

    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(2);
    pq.push(7);

    print(pq);//7,5,3,2


    deque<int> deq;
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);
    deq.push_front(10);
    deq.push_front(0);

    deque<int> copy = deq;
    print_back(deq);
    print_front(deq);
    cout<<"size = "<<copy.size()<<endl;
    cout<<"copy[0] = "<<copy[0]<<endl;

    stack<string> s;
    s.push("string1");
    s.push("string2");
    s.push("string3");

    print_stack(s);

    last_k_numbers_sum_stream processor(4);

    int num;
    while(cin>>num)
        cout<<processor.sum(num)<<endl;

    pair<int, string> p1;
    p1.first = 0;
    p1.second = "string1";

    pair<int, string> p2 = make_pair(1, "string");

    tuple<char, int, string> t1 = make_tuple('c', 10, "str");
    cout<<get<0>(t1)<<" "<<endl;
    char c;
    int i;
    string str;
    tie(c, i, str) = t1;

    return 0;
}