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
    pub fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn height(mut node: Option<Rc<RefCell<TreeNode>>>) -> i32 {
            let mut h = 0;
            // 对于一颗完全二叉树，从根节点一直向左走可以算出完全二叉树的高度
            while let Some(n) = node {
                h += 1;
                node = n.borrow().left.clone();
            }
            h
        }

        match root {
            None => 0,
            Some(node) => {
                // 左子树高度
                let left_h = height(node.borrow().left.clone());
                // 右子树高度
                let right_h = height(node.borrow().right.clone());

                if left_h == right_h {
                    // 左子树是满的
                    (1 << left_h) + Self::count_nodes(node.borrow().right.clone())
                } else {
                    // 右子树是满的
                    (1 << right_h) + Self::count_nodes(node.borrow().left.clone())
                }
            }
        }
    }
}

fn main() {
    println!("Hello, world!");
}
