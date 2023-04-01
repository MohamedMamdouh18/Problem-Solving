/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0)
            return null;
        return solve(lists, 0, lists.length - 1);
    }

    public ListNode solve(ListNode[] lists, int l, int r) {
        if (r == l)
            return lists[l];
        int mid = (l + r) >> 1;
        ListNode a = solve(lists, l, mid);
        ListNode b = solve(lists, mid + 1, r);
        return merge(a, b);
    }

    public ListNode merge(ListNode a, ListNode b) {
        if (a == null || b == null)
            return (a != null) ? a : b;

        ListNode ans = new ListNode(0);
        ListNode temp = ans;

        while (a != null && b != null) {
            if (a.val > b.val) {
                temp.next = b;
                b = b.next;
            } else {
                temp.next = a;
                a = a.next;
            }
            temp = temp.next;
        }

        temp.next = (b != null) ? b : a;

        return ans.next;
    }
}
