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
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;
impl Solution {
    fn build_tree_from_order(
        hash_map: &HashMap<i32, usize>,
        inorder: &Vec<i32>,
        postorder: &Vec<i32>,
        inorder_left: usize,
        inorder_right: usize,
        postorder_left: usize,
        postorder_right: usize,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let root_val = postorder[postorder_right];
        let root_index_inorder = hash_map[&root_val];
        let root = Rc::new(RefCell::new(TreeNode::new(root_val)));
        let root_left_subtree_size = root_index_inorder - inorder_left;
        if (root_left_subtree_size > 0) {
            root.borrow_mut().left = Solution::build_tree_from_order(
                hash_map,
                inorder,
                postorder,
                inorder_left,
                root_index_inorder - 1,
                postorder_left,
                postorder_left + root_left_subtree_size - 1,
            );
        }
        if (inorder_right - root_index_inorder > 0) {
            root.borrow_mut().right = Solution::build_tree_from_order(
                hash_map,
                inorder,
                postorder,
                root_index_inorder + 1,
                inorder_right,
                postorder_left + root_left_subtree_size,
                postorder_right - 1,
            );
        }

        Some(root)
    }
    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut hash_map: HashMap<i32, usize> = HashMap::new();
        for (index, &val) in inorder.iter().enumerate() {
            hash_map.insert(val, index);
        }
        Solution::build_tree_from_order(
            &hash_map,
            &inorder,
            &postorder,
            0,
            inorder.len() - 1,
            0,
            postorder.len() - 1,
        )
    }
}

fn main() {
    println!("Hello, world!");
}
