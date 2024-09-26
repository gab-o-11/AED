#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* menor_inicio=new ListNode();
        ListNode* mayor_inicio=new ListNode();
        ListNode* menor_final=new ListNode();
        ListNode* mayor_final=new ListNode();
        for(ListNode* current = head; current != nullptr; current = current->next){
            if(current->val<x) {
                if (menor_final==nullptr) {
                    menor_inicio=current;
                    menor_final=current;
                }
                else {
                    menor_final->next=current;
                    menor_final=menor_final->next;
                }
            }
            if(current->val>=x) {
                if(mayor_final==nullptr) {
                    mayor_inicio=current;
                    mayor_final=current;
                }
                else {
                    mayor_final->next=current;
                    mayor_final=mayor_final->next;
                }
            }
        }
        menor_final->next=mayor_inicio;
        return menor_inicio;
    }
};

int main() {
    ListNode* head=new ListNode();

}