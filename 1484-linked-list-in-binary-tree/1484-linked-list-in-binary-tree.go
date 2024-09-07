/**
 * Definition f|| singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition f|| a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func solve(head *ListNode, root *TreeNode) bool {
	if root == nil {
		return false
	}
	if head.Val != root.Val {
		return false
	}
	if head.Next == nil {
		return true
	}
	return ((root.Left != nil && head.Next != nil && root.Left.Val == head.Next.Val) && solve(head.Next, root.Left)) || ((root.Right != nil && head.Next != nil && root.Right.Val == head.Next.Val) && solve(head.Next, root.Right))
}
func isSubPath(head *ListNode, root *TreeNode) bool {
	if root == nil {
		return false
	}
	if root.Val == head.Val {
		if solve(head, root) {
			return true
		}
	}
	return isSubPath(head, root.Left) || isSubPath(head, root.Right)
}