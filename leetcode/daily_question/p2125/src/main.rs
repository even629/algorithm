struct Solution;

impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let n = bank.len();
        let mut curr_num = 0;
        let mut first = 0;
        let mut last_num = 0;
        let mut res = 0;

        while first != n - 1 {
            if bank[first].contains('1') {
                break;
            } else {
                first += 1;
            }
        }
        if first == n {
            return 0;
        }
        last_num = bank[first].chars().filter(|&ch| ch == '1').count();

        for i in first + 1..n {
            curr_num = bank[i].chars().filter(|&ch| ch == '1').count();
            if curr_num > 0 {
                res += last_num * curr_num;
                last_num = curr_num;
            }
        }

        res as i32
    }
}

fn main() {
    println!("Hello, world!");
}
