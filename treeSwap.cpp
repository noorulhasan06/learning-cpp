#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int data;
    int depth;
    node* left;
    node* right;
    node(int data, node* left, node* right, int depth){ this->data = data; this->left = left; this->right = right; this->depth = depth; }
};

void swap(node* root, int k){
    if(root){
        if((root->depth)%k == 0){
            swap(root->left,k);
            swap(root->right,k);
            node* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
    }
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main() {
    node* root = new node(1,NULL,NULL,1);
    queue<node*> q;
    int n;
    cin>>n;
    int l,r;
    node *tmp, *tmp2 ;
    q.push(root);
    int depth = 1;
    for(int i=0; i<n; i++){
        tmp = q.front();
        q.pop();
        cin>>l>>r;
        if(l != -1){
            tmp2 = new node(l,NULL,NULL,tmp->depth+1);
            tmp->left = tmp2;
            q.push(tmp2);
        }
        if(r != -1){
            tmp2 = new node(l,NULL,NULL,tmp->depth+1);
            tmp->right = tmp2;
            q.push(tmp2);
        }
    }
    int d,k;
    cin>>d;
    for(int i=0; i<d; i++){
        cin>>k;
        swap(root,k);
        inorder(root);
        cout<<endl;
    }
    
    return 0;
}

