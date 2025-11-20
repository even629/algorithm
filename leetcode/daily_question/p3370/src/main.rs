

struct Solution;
impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let mut i = 1_i64;
        while i < n as i64 {
            i = (i << 1) | 1;
        }
        i as i32
    }
}
fn main() {
    println!("Hello, world!");
}
