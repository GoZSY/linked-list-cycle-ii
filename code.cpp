/*******************************************************************************
 串长a + n，其中n为循环，当a + b步的慢指针与快指针相遇时，快指针已经走过了k圈。
即a + b + k * n = 2 * (a+b)，求a，得到a = k * n - b。
也就是X走a步，等于Z位置上的指针再走k圈，相遇于Y点。
********************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
     	if(head == NULL)
            return NULL;
        ListNode *f = head;
        ListNode *s = head;
        ListNode *h = head;
        while(f&&f->next)
        {
            s = s->next;
            f = f->next->next;
            if(s==f)
            {
                while(f!=h)
                {
                    f = f->next;
                    h = h->next;
                }
                return h;
            }
        }
        return NULL;
    }
};
