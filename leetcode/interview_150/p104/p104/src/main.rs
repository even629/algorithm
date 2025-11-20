use std::cell::RefCell;
use std::rc::Rc;

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
struct Solution;

use std::collections::VecDeque;

impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut depth = 0_i32;
        let mut length = 0;
        let mut que = VecDeque::new();

        if let Some(root) = root {
            que.push_back(root);
        } else {
            return 0;
        }

        while !que.is_empty() {
            length = que.len();
            for _ in 0..length {
                if let Some(node) = que.front() {
                    let node = Rc::clone(node); 
                    let node_ref = node.borrow();

                    // 先处理再 pop_front
                    if let Some(left) = &node_ref.left {
                        que.push_back(Rc::clone(left));
                    }
                    if let Some(right) = &node_ref.right {
                        que.push_back(Rc::clone(right));
                    }

                    
                    que.pop_front();
                }
            }

            depth += 1;
        }
        depth
    }
}
fn main() {}
