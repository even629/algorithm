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
use std::cmp::max;
use std::rc::Rc;

impl Solution {
    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_sum = i32::MIN;
        Self::dfs(&root, &mut max_sum);
        max_sum
    }
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, max_sum: &mut i32) -> i32 {
        if let Some(n) = node {
            let n = n.borrow();

            // 左右子树的最大贡献（如果为负则不如不要）
            let left_gain = max(Self::dfs(&n.left, max_sum), 0);
            let right_gain = max(Self::dfs(&n.right, max_sum), 0);

            // 以当前节点为最高点的路径最大和
            let current_path_sum = n.val + left_gain + right_gain;

            // 更新全局最大路径和
            *max_sum = max(*max_sum, current_path_sum);

            // 返回当前节点对父节点的最大贡献（只能选一边）
            return n.val + max(left_gain, right_gain);
        }
        0
    }
}

fn main() {
    println!("Hello, world!");
}
