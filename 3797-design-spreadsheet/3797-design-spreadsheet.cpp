class Spreadsheet {
public:
    vector<vector<int>> matrix;
    Spreadsheet(int rows) {
        matrix.resize(rows, vector<int>(27,0));
    }
    
    void setCell(string cell, int value) {
        string a = cell.substr(1);
        int col = cell[0]-'A';
        int row = stoi(a);
        matrix[row-1][col] = value;
    }
    
    void resetCell(string cell) {
        string a = cell.substr(1);
        int col = cell[0]-'A';
        int row = stoi(a);
        matrix[row-1][col] = 0;
    }
    
    int getValue(string formula) {
        string value1="", value2="";
        int n = formula.size();
        int i=1;
        while(i<n){
            while(i<n && formula[i]!= '+'){
                value1 += formula[i];
                i++;
            }
            i++;
            while(i<n){
                value2+=formula[i];
                i++;
            }
        }
        int row1=-1, col1=-1;
        string ro1;
        if(value1[0]>='A'&& value1[0]<='Z') {
            col1 = value1[0]-'A';
            ro1 = value1.substr(1);
            row1 = stoi(ro1);
        }
        int row2 = -1, col2 = -1;
        string ro2;
        if(value2[0]>='A'&& value2[0]<='Z') {
            col2 = value2[0]-'A';
            ro2 = value2.substr(1);
            row2 = stoi(ro2);
        }
        int num1 = -1, num2=-1;
        if(row1 == -1) num1 = stoi(value1);
        else num1 = matrix[row1-1][col1];

        if(row2 == -1) num2 = stoi(value2);
        else num2 = matrix[row2-1][col2];

        return num1+num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */