// Definition for a binary tree node.
struct Solution;
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        // 深度优先遍历
        let mut stack = VecDeque::new();
        let mut sum = 0;
        if let Some(node) = root {
            let val = node.borrow().val;
            stack.push_back((node, val));
        } else {
            return 0;
        }
        while let Some((node, val)) = stack.pop_back() {
            let node_ref = node.borrow();
            if node_ref.left.is_none() && node_ref.right.is_none() {
                sum += val;
            }
            if let Some(right) = node_ref.right.clone() {
                let right_val = right.borrow().val;
                stack.push_back((right, val * 10 + right_val));
            }

            if let Some(left) = node_ref.left.clone() {
                let left_val = left.borrow().val;
                stack.push_back((left, val * 10 + left_val));
            }
        }
        sum
    }
}

fn main() {
    println!("Hello, world!");
}
