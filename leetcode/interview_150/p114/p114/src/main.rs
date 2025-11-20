// Definition for a binary tree node.
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
pub struct Solution;

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        // 先序遍历
        let mut stack = Vec::new();
        let mut vec = Vec::new();
        let mut p = root.clone();

        // 先序遍历
        while let Some(node) = p {
            vec.push(node.clone());
            // 把右子节点压入栈中
            if let Some(right) = node.borrow().right.clone() {
                stack.push(right);
            }
            // 左子节点压入栈中，如果左子节点为空则退栈，否则p = Some(left)
            if let Some(left) = node.borrow().left.clone() {
                p = Some(left);
            } else {
                p = stack.pop();
            }
        }
        for i in 0..vec.len() {
            let node = vec[i].clone();
            node.borrow_mut().left = None;
            if i + 1 < vec.len() {
                node.borrow_mut().right = Some(vec[i + 1].clone());
            } else {
                node.borrow_mut().right = None;
            }
        }
    }
}

fn main() {
    println!("Hello, world!");
}
