#include <iostream>

using namespace std;

template <class t>  //Generic Type

class Stack{
 int top;
 t items[100];
 public:
     Stack(){ //constructor
       top=-1;
       }
    void push(t x) //add a new element to the stack
    {
        if(top==99) cout<<"End of stack";
        else{
        top++;
      items[top]=x;
        }
    }
    void pop() //delete the end element of the stack
    {
        top--;
    }
    t getTopElement()
    {
       t x= items[top];
        return x;
    }
    int getTopIndex() //get the index of the top
    {
        return top;
    }
    bool isEmpty()
    {
        return (top==-1); //return false if top=-1  else return true
    }
    t getAll() //get all elements by referse to its place in the memory (you need a container to store it in the main)
    {
      return *items;
    }
    int size() //the size of the stack
    {
        return top;
    }
    void printAll() //print all elements in the stack
    {
     int x=top+1;
     while(x--)
            cout<<items[x]<<" ";
    }
    t getElement(int index) //get element by index
    {
        return items[index];
    }
    void popElement(int index) //delete element by index
    {
        int i=index;
        while(i<=top)
        {
            items[i]=items[i+1];
         i++;
        }
        top--;
    }
};

int main()
{
    Stack<float> s;
    int n,x;
    cout<<"Enter the number of the elements:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the number please:";
        cin>>x;
        s.push(x);
    }
    cout<<"Are the Stack empty?:"<<s.isEmpty()<<endl;
   cout<<s.getTopElement()<<endl;

    int i=0;
    while(i<=s.size())
    {
        cout<<s.getElement(i)<<" ";
        i++;
    }
    cout<<endl;
    s.printAll();
    s.popElement(3);
    cout<<endl;
    s.printAll();
    cout<<endl;
    cout<<"the index of the top:"<<s.getTopIndex();
    return 0;
}
