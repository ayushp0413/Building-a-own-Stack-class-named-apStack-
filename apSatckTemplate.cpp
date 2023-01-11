#include <iostream>
#define MAX_SIZE 100
using namespace std;
template <class T>
class apStack
{
    T x[100];
    int SIZE=100;
    int top;
    public:
    apStack();
    apStack(T data);
    apStack(const apStack &other);
    apStack& operator=(const apStack &other);
    apStack operator +(apStack &other);
    void push(T data);
    T pop();
    int isEmpty();
    int isFull();
    void swap(apStack &other);
    int getSize();
};
template <class T>
apStack<T>:: apStack()
{
    this->top=SIZE;
}
template <class T>
apStack<T>:: apStack(T data)
{
   this->top=SIZE;
   this->push(data);
}
template <class T>
apStack<T>::apStack(const apStack<T> &other)
{
    int e;
    this->top=SIZE;
    for(e=SIZE-1;e>=other.top;e--)
    {
        this->x[e]=other.x[e];
    }
    this->top=other.top;
}
template <class T>
apStack<T>& apStack<T>::operator=(const apStack<T> &other)
{
    int e;
    this->top=SIZE;
    for(e=SIZE-1;e>=other.top;e--)
    {
        this->x[e]=other.x[e];
    }
    this->top=other.top;
    return *this;
}
template <class T>
apStack<T> apStack<T>:: operator +(apStack<T> &other)
{
    apStack temp,k;
    while(!other.isEmpty())
    {
        temp.push(other.pop());
    }
    while(!this->isEmpty())
    {
        temp.push(this->pop());
    }
    while(!temp.isEmpty())
    {
        k.push(temp.pop());
    }
    
    return k;
}
template <class T>
void apStack<T>:: push(T data)
{
    if(top==0) return;
    this->x[--top]=data;
}
template <class T>
T apStack<T>:: pop()
{
    if(top==SIZE)return 0;
    T data;
    data=x[top++];
    return data;
}
template <class T>
int apStack<T>::isEmpty()
{
    return this->top==SIZE;
}
template <class T>
int apStack<T>::isFull()
{
    return this->top==0;
}
template <class T>
void apStack<T>::swap(apStack &other)
{
    apStack t1,t2;
    while(!this->isEmpty())
    {
        t1.push(this->pop());
    }
    while(!other.isEmpty())
    {
        t2.push(other.pop());
    }
    while(!t1.isEmpty())
    {
        other.push(t1.pop());
    }
    while(!t2.isEmpty())
    {
        this->push(t2.pop());
    }
}
template <class T>
int apStack<T>::getSize()
{
    return (SIZE-top);
}
int main()
{
    apStack<int> s;
    cout<<"Initial Size :"<<s.getSize()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
        cout<<"Size after pushing  :"<<s.getSize()<<endl;
    // while(!s.isEmpty())
    // {
    //  cout<<s.pop()<<endl;
    // }
    cout<<"---------------"<<endl;
    apStack<int> s1;
    s1.push(100);
    s1.push(200);
    s1.push(300);
    // while(!s1.isEmpty())
    // {
        // cout<<s1.pop()<<endl;
    // }
    cout<<"----------------------"<<endl;
    apStack<int> s3;
    s3=s+s1;
    while(!s3.isEmpty())
    {
        cout<<s3.pop()<<endl;
    }
    return 0;
}