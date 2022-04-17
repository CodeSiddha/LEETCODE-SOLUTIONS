class ATM {
    private:
     vector<long long> notes;
     vector<long long> money;
public:
    ATM() {
       notes.resize(5 , 0);
       money = {20 , 50 , 100 , 200 , 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0 ; i < 5 ; i++){
            notes[i] += (long long)banknotesCount[i];
        }
    }
    vector<int> withdraw(int amount) {
        vector<int> with(5);
        for(int i = 4 ; i >= 0 ; i--){
            if(amount == 0){
                break;
            }
            if(notes[i] > 0){
                    with[i] = min(notes[i] , amount / money[i]);
                    amount -= 1ll * (money[i] * with[i]);
            }
        }
        if(amount > 0){
            return {-1};
        }else{
            for(int i = 0 ; i < 5 ; i++){
                notes[i] -=(long long)with[i];
            }
        }
        return with;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */