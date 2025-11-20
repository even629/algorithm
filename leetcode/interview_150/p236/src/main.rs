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
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if p.is_none() || q.is_none() || root.is_none() {
            return None;
        }
        let p = p.unwrap();
        let q = q.unwrap();
        // 后序遍历非递归
        let mut stack = VecDeque::new();
        let mut curr = root;
        let mut last = None;
        let mut p_vec = Vec::default();
        let mut q_vec = Vec::default();

        while curr.is_some() || !stack.is_empty() {
            if p_vec.len() > 0 && q_vec.len() > 0 {
                break;
            }
            if let Some(node) = curr {
                stack.push_back(node.clone());
                curr = node.borrow().left.clone();
            } else {
                let top = stack.back().unwrap().clone();
                let top_borrow = top.borrow();

                if top_borrow.right.is_some() && top_borrow.right != last {
                    curr = top_borrow.right.clone();
                } else {
                    // visit top
                    if top_borrow.val == p.borrow().val {
                        // VecDeque contains the path root->curr node
                        p_vec = stack.iter().cloned().collect();
                    } else if top_borrow.val == q.borrow().val {
                        q_vec = stack.iter().cloned().collect();
                    }
                    stack.pop_back();
                    last = Some(top.clone());
                    curr = None;
                }
            }
        }
        let mut index = 0_usize;
        let mut res = None;
        while index < p_vec.len() && index < q_vec.len() {
            if p_vec[index].borrow().val == q_vec[index].borrow().val {
                res = Some(p_vec[index].clone());
            }
            index += 1;
        }
        res
    }
}

fn main() {
    println!("Hello, world!");
}
