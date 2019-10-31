/* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}
var addTwoNumbers = function (l1, l2) {
    let sum = 0, node;
    if (l1 && l1.val) sum += l1.val;
    if (l2 && l2.val) sum += l2.val;
    if (!l1 && !l2) return null;
    let f = sum % 10, s = Math.floor(sum / 10);
    node = new ListNode(f);
    if ((!l1 || !l1.next) && (!l2 || !l2.next)) {
        console.log('IN')
        if (s) node.next = new ListNode(s);
    } else {
        if (l1.next && s) l1.next.val += s;
        else if (l2.next && s) l2.next.val += s;
        node.next = addTwoNumbers(l1.next, l2.next);
    }

    return node;
};

function getNumber(l) {
    if (!l.next) return l.val;
    else return l.val + '' + getNumber(l.next);
}
let a;
a = new ListNode(4);
let b;
b = new ListNode(6);

console.log(getNumber(a));
console.log(getNumber(b));
console.log(getNumber(addTwoNumbers(a, b)));
