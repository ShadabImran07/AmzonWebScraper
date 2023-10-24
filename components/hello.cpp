/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> ans;
        ListNode* curr=head;
        while(curr!=NULL){
            ans.push_back(curr->val);
            curr=curr->next;
        }
        int n=ans.size();
        while(k>0){
            int temp1=ans[n-1];
            for(int i=n-2;i>=0;i--){
                swap(ans[i+1],ans[i]);
            }
            ans[0]=temp1;
        }
        ListNode* curr1=head;
        int i=0;
        while(curr1!=NULL){
            curr1->val=ans[i++];
            curr1=curr1->next;
        }
        return head;
    }

int main()
{
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    // ListNode *ans=rotateRight(head,2);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }

    cout<<"Hello World";

    return 0;
}
