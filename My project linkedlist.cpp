#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
  void addfirst(node* & head, int x) //1
{
   node * p;
   p = new node();  //p is points to a new node
   p->data = x;
   p->next = NULL;
   p->next = head; 
   head = p;
}
void print(node* head)  //9
{
    node* run;
    run = head;
    cout << "the data is" << endl;
    while (run != NULL)
    {
        cout << run->data << " ";
        run = run->next;
    } cout << endl;
}
void addlast(node*& head, int x)  //2
{
    node* p;
    p = new node();
    p->data = x;
    p->next = NULL;
    if (head != NULL)
    {
        node* run;
        run = head;
        while (run->next != NULL) //we want to add after the last element in the list to that we want to stop on the last element that=run->next
            run = run->next; //as run++
        run->next = p; //run became point to the value of the node that p is pointing to it 
    }
    else head = p;
}
int sumlist(node* head)
{
    node* run;
    run = head;
    int sum = 0;
    while (run != NULL)
    {
        sum += run->data;
        run = run->next;
    }
    return sum;
}
int count(node* head)
{
    node* run;
    run = head;
    int c = 0;
    while (run != NULL)
    {
        c++;
        run = run->next;
    }
    return c;
}
bool search(node* head, int x) //this function of search return boolean
{
    node* run;
    run = head;
    while (run != NULL)
    {
        if (run->data == x) return true;
        else run = run->next;
    }return false;
}
node* another_search(node* head, int x) //this function of search return node
{
    node* run;
    run = head;
    while (run != NULL)
    {
        if (run->data == x) return run;
        else run = run->next;
    }
    return NULL;
} //another function of search
void concate(node* h1, node* h2)  
{
    if (h1 != NULL)
    {
        node* run;
        run = h1;
        while (run->next != NULL)
            run = run->next;
        run->next = h2;
    }
    else h1 = h2;
}
void sort(node* head) //this is a sequntial sort and it is less efficient
{
    node* minnode = head;
    node* run = head;
    while (run != NULL)
    {
        while (minnode->next != NULL)
        {
            if (minnode->next->data < minnode->data) swap(minnode->data, minnode->next->data);
            minnode = minnode->next;
        } 
        run = run->next;
        minnode = head;
    }
}
void reverse(node* head1,node* &head2) 
{
    node* run = head1;
     head2 = NULL;
    while (run != NULL)
    {
        addfirst(head2, run->data);
        run = run->next;
    }
}
bool palindrome(node* head)
{
    node* r1 = head;
    node* r2 = head;
    node* r3 = NULL;
    reverse(r1,r3);
    while (r3 != NULL)
    {
        if (r3->data == r2->data)
        {
            r3 = r3->next;
            r2 = r2->next;
        }
        else return false;
    }
    return true;
}
void deletefirst(node* &head)
{
    if (head == NULL)
        cout << "the list is empty" << endl;
    else if (head->next == NULL)
        head = NULL;
    else
    {
        node* p = NULL;
        p = head;
        head = head->next;
        delete (p);
        //cout << "after delete the first element ";
    }
}
void deletelast(node*& head) //this function still under the building
{
    if (head == NULL)  cout << "the list is empty \n";
    else if (head->next == NULL) 
        head = NULL;
    else
    {
        node* run = head;
        while (run->next->next != NULL) //run->next->next to ensure that there are two nodes at least in the list
            run = run->next;
        node* p = run->next;
        run->next = NULL;
        delete(p);
        cout << "after delete the last element ";
    }
}
void merge(node* head1, node* head2,node* &head3)
{
    head3=NULL;
    node* r1 = head1;
    node* r2 = head2;
    while (r1 != NULL && r2!= NULL)
    {
        if (r1->data < r2->data)
        {
            addlast(head3, r1->data);
            r1 = r1->next;
        }
        else if (r2->data < r1->data)
        {
            addlast(head3, r2->data);
            r2 = r2->next;
        }
        else {//r1->data = r2->data
            addlast(head3, r1->data);
            r1 = r1->next;
            r2 = r2->next;
        }
    }
    while (r1!= NULL)
    {
        addlast(head3, r1->data);
        r1 = r1->next;
    }
        while (r2 != NULL)
        {
            addlast(head3, r2->data);
            r2 = r2->next;
        }
}
//the code of merge is finished but you need to revesion it
void addafter_value(node* head, int x,int y)//x is the number that we will add after it,y is the number that we will add it  //3
{
    node* r1 = head;
    node* r2 = head;
    node* p ;
    p = new node();
    p->next = NULL;
    p->data = y; 
    if (head == NULL) cout << "the list is empty" << endl;
    while (r1->data != x && r1->next != NULL)
    {
        r1 = r1->next;  //r1 will stop on the node that we will add after it
        r2 = r2->next;
    }
    if (r1->next != NULL)
    {
        r2 = r2->next;  //run 2 is on the node that we will add before it
        r1->next = p;
        p->next = r2;
    }
    else cout << "not found the value" << endl;
}
void addbefore_value(node* head, int x, int y) //4
{
    node* r1 = head;
    node* r2 = head;
    node* p;
    p = new node();
    p->next = NULL;
    p->data = y;
    while (r1->next->data != x && r1->next != NULL)
    {
        r1 = r1->next;
        r2 = r2->next;
    }
    if (r1->next != NULL)
    {
     r2 = r2->next;  //run2 is on the node that we will add before it
     r1->next = p;
     p->next = r2;
 }
    /*else if (r1 == head)
    {
        r2 = r2->next;
        head->next = p;
        p->next = r2;
    }*/
    else cout << "not found the value" << endl;
}
//repeet add after value , add before value
int max_value(node* head)  //12
{
    node* run;
    //run = new node;
    run = head;
    int max = head->data;
    while (run != NULL)//if we do the condition is run->next!=NULL the programe will skip the last value in the list & won't compare it with the privios value
    {
        if (run->data>max)   max = run->data;
            run = run->next;
    }
    return max;
}
void H_leader(node* head)
{
    node* r1 = head;
    node* r2 = head;
    while (r1->next != NULL)
    {
        if (r1->data < r1->next->data)
        {
            int i = 1, j = 1;
            while (r2 != NULL && r2->data != r1->next->data)
            {
                if (r2->data < r1->next->data) i++;
                // else break;
                j++; r2 = r2->next;
            }
            if (i == j) cout << r1->next->data<<" ";
            r2 = head;
        }
         r1 = r1->next;
    }

}
void sum_after(node* head)
{
    node* r1 = head;
    node* r2 = head;
    int i = 1;
    while (r2->next != NULL)
    {
        int sum = 0;
        r1 = r1->next;
        while (r1 != NULL)
        {
            sum += r1->data;
            r1 = r1->next;
        } cout<<"the sum after element ["<<i<<"] is:" << sum << " \n";
        r2 = r2->next;
        r1 = r2;
        i++;
    }
}
bool detect(node* head)
{
    node* run=head;
    while (run->next != NULL)
    {
        if (run->data < run->next->data) run = run->next;
        else return false;
    }
    return true;
}
void delete_after_element(node* head,int x)
{
    if (head == NULL) cout << "empty";
    else if (head->next == NULL) cout << "only one element in the list";
    else {
        node* run = head;
        while (run->next != NULL && run->data != x)
            run = run->next;
        if (run->next != NULL) {
            run->next = run->next->next;
            cout << "\t delete after \n";
        }
        else cout << "not found the element or the element is the last node, ";
    }
}
void delete_before_element(node* head, int x)
{
    if (head == NULL) cout << "empty";
    else if (head->next == NULL) cout << "only one element in the list";
    else {
        node* run = head;
        node* run2 = head;
       // int i = 0;
       // int n = count(head);
        while (run->next->next != NULL && run->next->next->data != x)
            run = run->next;
        if (run->next->next != NULL)
            run->next = run->next->next;
        else cout << "not found the element or the element is the first element ";
    }
}
void mid(node* head) //this function print the middel elements
{
    node* run = head;
    int n = count(head);
    if (n % 2 != 0)
    {
        for (int i = 0; i < n / 2; i++)
            run = run->next;
        cout << "the middle element is:" << run->data;
    }
    else {
        for (int i = 0; i < (n / 2)-1; i++)
            run = run->next;
        cout << "there is two middle elements :" << run->data<<" ";
        run = run->next;
        cout << run->data;
    }
}
void delete_element(node* head, int x)
{
    if (head == NULL) cout << "empty ";
    else if (head->data == x) 
    {
       // node* p = NULL;
       // p = head;
        head = head->next;
       // delete (p);
    }
    else {
        node* run=head;
        while (run->next != NULL && run->next->data != x)
            run = run->next;
        if (run->next != NULL) run->next = run->next->next;
    }
}
//delete_element still under the building show it on a doctor
void move_key(node* head, int x)
{
    node* run2 = head;
    
        while (run2->next != NULL)
        {
            node* run1 = run2;
            if (head->data == x) { 
                head = head->next;
                addlast(head, x);
            }
            else{
            while (run1->next != NULL && run1->next->data != x)
                run1 = run1->next;
            if (run1->next != NULL) {
                run1->next = run1->next->next;
                addlast(head, x);
            }
        }
            run2 = run2->next;
    }
    
}
// number 19 in the sheet show this function on a doctor
void insert_list(node* head, node* head2,node* &head3) //this function insert list in the middel of another list
{
     head3 = NULL;
    if (head == NULL && head2 == NULL) head3 = NULL;
    else if (head == NULL) head3 = head2;
    else if (head2 == NULL) head3 = head;
    else {
        node* run = head;
        node* run2 = head2;
        int n = count(head);
        for (int i = 0; i <= n / 2; i++)
        {
            addlast(head3, run->data);
            run = run->next;
        }
        while (run2 != NULL)
        {
            addlast(head3, run2->data);
            run2 = run2->next;
        }
        for (int i = (n / 2)+1; i < n; i++)
        {
            addlast(head3, run->data);
            run = run->next;
        }
    }
}
node* rotate(node* head, int k)
{
    node* run = head;
    node* head2 = NULL;
    int i = 0;
    while (run != NULL)
    {
        while (i < k)
        {
            run = run->next;  i++;
        }
        addlast(head2, run->data);
        run = run->next;
    }i = 0;
    run = head;
    while (i<k)
    {
        addlast(head2, run->data);
        run = run->next;
        i++;
    }
    return head2;
}
void another_sort(node* head)
{ //this function of sort like bubble sort but this but the smallest element in the first 
    node* start=head;
    while (start->next != NULL)
    {
        node* min = start;
        node* run = start;
        while (run != NULL)
        {
            if (min->data > run->data) swap(run->data, min->data);
            else run = run->next;
        }
        start = start->next;
    }
}
void selection_sort(node* head)
{
    node* start = head;
    while(start->next != NULL)
    {
        node* run = start;
        node* min = start;
        while (run != NULL)
        {
            if (run->data < min->data) min = run;
            run = run->next;
        }
        swap(start->data, min->data);
        start = start->next;
    }
}
//these are two types of sort and there are more effecient from the sequential sort that is above
int main()
{
    node* head = NULL;
    node* head2 = NULL;
    int s, n;
    cout << "please enter the number of the elements:";
    cin >> n;
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        addlast(head, s);
    }
    print(head);
    int x;
    cout << "enter the key:";
    cin >> x;
    head2 = rotate(head, x);
    cout << "after rotate ";
    print(head2);
}
