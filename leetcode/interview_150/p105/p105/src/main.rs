use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

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

impl Solution {
    fn build_tree_from_order(
        hash_map: &HashMap<i32, usize>,
        preorder: &Vec<i32>,
        inorder: &Vec<i32>,
        pre_left: usize,
        pre_right: usize,
        in_left: usize,
        in_right: usize,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if pre_left > pre_right {
            return None;
        }

        let root_val = preorder[pre_left];
        let root = Rc::new(RefCell::new(TreeNode::new(root_val)));

        let root_index_inorder = hash_map[&root_val];
        let left_tree_size = root_index_inorder - in_left;

        root.borrow_mut().left = Solution::build_tree_from_order(
            hash_map,
            preorder,
            inorder,
            pre_left + 1,
            pre_left + left_tree_size,
            in_left,
            root_index_inorder - 1,
        );

        root.borrow_mut().right = Solution::build_tree_from_order(
            hash_map,
            preorder,
            inorder,
            pre_left + left_tree_size + 1,
            pre_right,
            root_index_inorder + 1,
            in_right,
        );

        Some(root)
    }

    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut hash_map = HashMap::new();
        for (i, &val) in inorder.iter().enumerate() {
            hash_map.insert(val, i);
        }

        Solution::build_tree_from_order(
            &hash_map,
            &preorder,
            &inorder,
            0,
            preorder.len() - 1,
            0,
            inorder.len() - 1,
        )
    }
}

fn main() {
    let preorder = vec![3, 9, 20, 15, 7];
    let inorder = vec![9, 3, 15, 20, 7];

    let tree = Solution::build_tree(preorder, inorder);
    println!("{:?}", tree);
}
