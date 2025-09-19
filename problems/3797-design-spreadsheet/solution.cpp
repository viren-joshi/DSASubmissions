class Spreadsheet {
public:
    map<string, int> data;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        data[cell] = value;
    }
    
    void resetCell(string cell) {
        data[cell] = 0;
    }
    
    int getValue(string formula) {
        int i = 1;
        string o1, o2;
        int op1, op2;
        while(formula[i] != '+') {
            o1+=formula[i];
            i++;
        }
        i++;
        while(i<formula.size()) {
            o2+=formula[i];
            i++;
        }

        if(isalpha(o1[0])) {
            op1 = data[o1];
        } else {
            op1 = stoi(o1);
        }

        if(isalpha(o2[0])) {
            op2 = data[o2];
        } else {
            op2 = stoi(o2);
        }

        return op1 + op2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
