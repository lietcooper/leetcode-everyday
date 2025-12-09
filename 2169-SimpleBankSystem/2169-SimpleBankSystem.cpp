// Last updated: 12/8/2025, 11:25:51 PM
class Bank {
private:
    vector<long long> acnt;
public:
    Bank(vector<long long>& balance) {
        for (long long amnt : balance) acnt.push_back(amnt);
    }

    bool transfer(int account1, int account2, long long money) {
        if (money < 0) return false;
        if (withdraw(account1, money)) {
            if (deposit(account2, money)) return true;
            else deposit(account1, money);
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (money < 0) return false;
        if (account < 1 || account > acnt.size()) return false;
        // if (money == 0) return false;
        acnt[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (money < 0) return false;
        if (account < 1 || account > acnt.size()) return false;
        if (acnt[account - 1] < money) return false;
        else {
            acnt[account - 1] -= money;
            return true;
        }
    }

};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */