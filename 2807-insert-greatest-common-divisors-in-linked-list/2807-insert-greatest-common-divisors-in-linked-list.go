/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
	tmp := head
	for tmp.Next != nil {
		tmp.Next = &ListNode{gcd(tmp.Val, tmp.Next.Val), tmp.Next}
		tmp = tmp.Next.Next
	}
	return head
}