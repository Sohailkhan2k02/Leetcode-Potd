class Spreadsheet {
public:
    vector<vector<int>> matrix;
    Spreadsheet(int rows) {
        matrix.resize(rows, vector<int>(26, 0));
    }
    pair<int, int> getCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }
    void setCell(string cell, int value) {
        auto [row, col] = getCell(cell);
        matrix[row][col] = value;
    }
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    int getValue(string formula) {
        for(int i = 1; i < formula.length(); ++i) {
            if(formula[i] == '+') {
                string cell1 = formula.substr(1, i-1);
                string cell2 = formula.substr(i+1);
                int val1, val2;
                if(isalpha(cell1[0])) {
                    auto [row, col] = getCell(cell1);
                    val1 = matrix[row][col];
                } else val1 = stoi(cell1);
                if(isalpha(cell2[0])) {
                    auto [row, col] = getCell(cell2);
                    val2 = matrix[row][col];
                } else val2 = stoi(cell2);
                return val1 + val2;
            }
        }
        return 0;
    }
};
