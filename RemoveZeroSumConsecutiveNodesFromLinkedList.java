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
    // Let's use Java's GC!!
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode front = new ListNode(0, head), curr = front;
        Map<Integer, ListNode> map = new HashMap<>();
        int sum = 0;
        while (curr != null) {
            sum += curr.val;
            map.put(sum, curr);
            curr = curr.next;
        }
        curr = front;
        sum = 0;
        while (curr != null) {
            sum += curr.val;
            if (map.containsKey(sum)) {
                curr.next = map.get(sum).next;
            }
            curr = curr.next;
        }
        return front.next;
    }
}
