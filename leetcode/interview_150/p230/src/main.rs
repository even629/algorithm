struct Solution;
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
      right: None
    }
  }
}
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;
impl Solution {
    // 中序遍历第k个
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut stack = VecDeque::new();
        let mut p = root;
        let mut count = 0;
        let mut res = 0;
        
        while p.is_some() || !stack.is_empty(){
            if let Some(node) = p{
                stack.push_back(node.clone());
                p = node.borrow().left.clone();
            }else{
                count +=1;
                let curr = stack.pop_back().unwrap();
                if count == k{
                    res = curr.borrow().val;
                }
                p = curr.borrow().right.clone();
            }
        }
        res
    }
}

fn main() {
    println!("Hello, world!");
}
