#include <iostream>
#include <algorithm>
#include <vector>

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
    int numComponents(ListNode* head, vector<int>& nums) {
        if(head==nullptr||head->next==nullptr) return 1;
        bool conected=false;
        int indice=0;
        int componentes=0;
        int size=nums.size();

        sort(nums.begin(),nums.end());

        for(ListNode* current=head;current!=nullptr;current=current->next){
            if(indice-1!=size){
                if(!nums[indice]>current->val){
                    if(current->val==nums[indice]){
                        conected=true;
                    }
                    else{
                        conected=false;
                        componentes++;
                    }
                    indice++;
                }
                else{
                    conected=false;
                    componentes++;
                }
            }
        }
        return componentes;
    }
};

int main() {
    ListNode x(0);
    ListNode y(1);
    ListNode z(2);
    ListNode a(3);

    x.next=&y;
    y.next=&z;
    z.next=&a;
    a.next=nullptr;

    vector<int> nums(1,0);
    nums.push_back(1);
    nums.push_back(3);

    Solution solucion;
    cout<<solucion.numComponents(&x,nums);
}