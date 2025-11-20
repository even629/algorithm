struct Bank {
    balance_vec: Vec<i64>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {
    fn new(balance: Vec<i64>) -> Self {
        Self {
            balance_vec: balance,
        }
    }

    fn transfer(&mut self, account1: i32, account2: i32, money: i64) -> bool {
        let account1 = (account1 - 1) as usize;
        let account2 = (account2 - 1) as usize;
        if self
            .balance_vec
            .get(account1 as usize)
            .is_none_or(|&balance| balance < money)
            || self.balance_vec.get(account2).is_none()
        {
            return false;
        }
        self.balance_vec[account1] -= money;
        self.balance_vec[account2] += money;
        true
    }

    fn deposit(&mut self, account: i32, money: i64) -> bool {
        let account = (account - 1) as usize;
        if self.balance_vec.get(account).is_none() {
            return false;
        }
        self.balance_vec[account] += money;
        true
    }

    fn withdraw(&mut self, account: i32, money: i64) -> bool {
        let account = (account - 1) as usize;
        if self
            .balance_vec
            .get(account)
            .is_none_or(|&balance| balance < money)
        {
            return false;
        }
        self.balance_vec[account as usize] -= money;
        true
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * let obj = Bank::new(balance);
 * let ret_1: bool = obj.transfer(account1, account2, money);
 * let ret_2: bool = obj.deposit(account, money);
 * let ret_3: bool = obj.withdraw(account, money);
 */
fn main() {}
