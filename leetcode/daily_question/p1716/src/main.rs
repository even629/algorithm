struct Solution;

impl Solution {
    pub fn total_money(n: i32) -> i32 {
        let week = n / 7;
        let day = n % 7;

        // 1,2   (1+2)*2/2

        28 * week + 7 * (week - 1) * week / 2 + (week + 1 + week + day) * day / 2
    }
}

fn main() {
    println!("Hello, world!");
}
