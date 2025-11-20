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
use std::rc::Rc;
impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        // 深度优先遍历
        let mut stack = Vec::new();

        if let Some(p) = root {
            stack.push((p, 0));
        } else {
            return false;
        }

        while let Some((node, val)) = stack.pop() {
            // visit node
            let node_ref = node.borrow();
            let curr_sum = node_ref.val + val;
            if node_ref.left.is_none() && node_ref.right.is_none() {
                if target_sum == curr_sum {
                    return true;
                }
            }

            if let Some(right) = node_ref.right.clone() {
                stack.push((right, curr_sum));
            }
            if let Some(left) = node_ref.left.clone() {
                stack.push((left, curr_sum));
            }
        }

        false
    }
    pub fn recursive_has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        if let Some(node) = root {
            let node_ref = node.borrow();
            let curr_val = node_ref.val;
            if node_ref.left.is_none() && node_ref.right.is_none() {
                return target_sum == node_ref.val;
            }
            return Solution::recursive_has_path_sum(node_ref.left.clone(), target_sum - curr_val)
                || Solution::recursive_has_path_sum(node_ref.right.clone(), target_sum - curr_val);
        }
        false
    }
}
fn main() {
    println!("Hello, world!");
}
