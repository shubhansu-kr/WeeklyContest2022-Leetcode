// https://leetcode.com/contest/weekly-contest-301/problems/smallest-number-in-infinite-set/

// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
// Implement the SmallestInfiniteSet class:
// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all
// positive integers.
// int popSmallest() Removes and returns the smallest integer contained in the
// infinite set.
// void addBack(int num) Adds a positive integer num back into the infinite set,
// if it is not already in the infinite set.

#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SmallestInfiniteSet
{
    ListNode *head, *rear;
public:
    SmallestInfiniteSet()
    {
        head = new ListNode(1);
        rear = head;
    }

    int popSmallest()
    {
        if (head->val == rear->val) return (head->val)++; 
        ListNode *temp = head;
        int ans = head->val;
        head = head->next;
        delete(temp);
        return ans;
    }

    void addBack(int num)
    {
        if (num >= rear->val || num == head->val) return;
        ListNode *p = new ListNode(num);
        if (num < head->val) {
            p->next = head;
            head = p ;
            return;
        }
        ListNode *temp = head;
        while (temp->next->val <= num) {
            if (temp->next->val == num) {delete(p);return;}
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
};

int main()
{

    return 0;
}