struct Solution;

impl Solution {
    pub fn count_valid_selections(nums: Vec<i32>) -> i32 {
        let mut scheme = 0;
        let mut vec: Vec<i32> = Vec::with_capacity(nums.len()); // 计算前缀和
        let mut last = 0;
        for &val in nums.iter() {
            last = last + val;
            vec.push(last);
        }

        let total = if let Some(&sum) = vec.last() { sum } else { 0 };

        for (index, &val) in nums.iter().enumerate() {
            if val == 0 {
                let left_sum = if let Some(&sum) = vec.get(index - 1) {
                    sum
                } else {
                    0
                };
                let right_sum = if let Some(&sum) = vec.get(index) {
                    total - sum
                } else {
                    0
                };
                if left_sum == right_sum {
                    scheme += 2;
                } else if left_sum == right_sum + 1 || right_sum == left_sum + 1 {
                    scheme += 1;
                }
            }
        }
        scheme
    }
}

fn main() {
    println!("Hello, world!");
}
