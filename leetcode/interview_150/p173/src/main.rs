#![allow(unused)]

use std::cell::RefCell;

use std::collections::VecDeque;
// Definition for a binary tree node.
use std::rc::Rc;

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
struct BSTIterator {
    next: usize,
    vec: Vec<Rc<RefCell<TreeNode>>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut bst_iter = BSTIterator {
            next: 0,
            vec: Vec::new(),
        };
        let mut stack = VecDeque::new();

        let mut p = root;
        // 中序遍历
        while p.is_some() || !stack.is_empty() {
            if let Some(node) = p {
                stack.push_back(node.clone());
                p = node.borrow().left.clone();
            } else {
                let node = stack.pop_back().unwrap();
                bst_iter.vec.push(node.clone());
                p = node.borrow().right.clone();
            }
        }
        bst_iter
    }

    fn next(&mut self) -> i32 {
        if let Some(node) = self.vec.get(self.next) {
            self.next += 1;
            node.borrow().val
        } else {
            i32::MIN
        }
    }

    fn has_next(&self) -> bool {
        self.vec.len() > self.next
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */

fn main() {
    // let obj = BSTIterator::new(root);
    // let ret_1: i32 = obj.next();
    // let ret_2: bool = obj.has_next();
}
