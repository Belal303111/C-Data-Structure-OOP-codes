#include <iostream>

using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
void print(node* root)
{
    if(root!=NULL)
  {
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    }
}
int count_tree(node*root)
{
    if(root!=NULL)
        return(1+count_tree(root->left)+count_tree(root->right));
    else return 0;
}
void insert_in_tree(node* & root,int x)
{
    if(root==NULL)
    {
    root=new node();
    root->data=x;
    root->left=NULL;
    root->right=NULL;
    }
    else if(root->data<x)
            insert_in_tree(root->right,x);
    else
       insert_in_tree(root->left,x);
}
bool search_tree(node*root,int x)
{
   if(root==NULL) return false;
  else
   {
       if(root->data==x) return true;
       else if(x>root->data) return(search_tree(root->right,x));
       else return(search_tree(root->left,x));
   }
}
int sum(node* root)
{
    if(root==NULL) return 0;
    else{
        return(root->data+sum(root->left)+sum(root->right));
         }
}
int sum_even(node*root)
{
    if(root==NULL) return 0;
    else
    {
        int sum=0;
        if(root->data%2==0) sum+=root->data;
        sum+=sum_even(root->left);
        sum+=sum_even(root->right);
         return sum;
    }
}
int sum_odd(node* root)
{
    if(root==NULL) return 0;
    else {
        int sum=0;
        if(root->data%2!=0) sum+=root->data;
        sum+=sum_odd(root->left);
        sum+=sum_odd(root->right);
        return sum;
    }
}
int sum_left(node*root)
{
   // int sum=0;
   if(root->left==NULL) return 0;
   else{
    return(count_tree(root->left));
      int sum=sum+root->left->data;
      cout<<"SUM:"<<endl;
   }
}
int main()
{
  node*root=NULL;
  int n;
  cout<<"enter the number of the elements that you want add to the tree:";
  cin>>n;
  int s[n];
  cout<<"enter the elements in tree"<<endl;
  for(int i=0;i<n;i++)
  {
      cin>>s[i];
      insert_in_tree(root,s[i]);
  }
  print(root);
 cout<<endl;
 cout<<"sum of even:"<<sum_even(root)<<endl;
 cout<<"sum of Odd:"<<sum_odd(root)<<endl;
 cout<<"sum of left:"<<sum_left(root)<<endl;
 cout<<"the count of tree is:"<<count_tree(root);
    return 0;
}
