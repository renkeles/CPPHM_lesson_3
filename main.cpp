#include <iostream>
#include <list>
#include <vector>

template <class T>
void printList(std::list<T> &f_list){
    for(auto n : f_list){
        std::cout << n << "\t";
    }
    std::cout << std::endl;
}
template <class T>
void insertList(std::list<T> &f_list, int it = 1){
    for(; it > 0; --it){
        int count = 0;
        float sum = 0.0;
        for(float n : f_list){
            sum += n;
            ++count;
        }
        f_list.push_back(sum / count);
    }
}

template <class T>
class Matrix{
private:
    T** M;
    int row;
    int col;
public:
    Matrix(){
        row = col = 0;
        M = nullptr;
    }

    Matrix(int _row, int _col){
        if(_row > 0 && _col > 0){
            row = _row;
            col = _col;
        }else{
            row =  col = 0;
            std::cout << "Wrong matrix size\n";
            return;
        }

        M = (T**) new T*[row];
        for(int x{0}; x < row; ++x){
            M[x] = (T*) new T[col];
        }

        for(int x{0}; x < row; ++x){
            for(int y{0}; y < col; ++y){
                M[x][y] = 0;
            }
        }
    }

    T get(int x, int y){
        if(row > 0 && col > 0) return M[x][y];
        else return 0;
    }

    int getSizeRow(){
        if(row < 0) return 0;
        else return row;
    }

    int getSizeCol(){
        if(col < 0) return 0;
        else return col;
    }

    void set(int x, int y, T value){
        if((x < 0) || (x >= row)) {
            std::cout << "Wrong matrix X size\n";
            return;
        }
        if((y < 0) || (y >= col)){
            std::cout << "Wrong matrix Y size\n";
            return;
        }
        M[x][y] = value;
    }

    void printMatrix(){
        if(row >= 0 && col >= 0){
            for(int x{0}; x < row; ++x){
                for(int y{0}; y < col; ++y){
                    std::cout << M[x][y] << "\t";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }else{
            std::cout << "Wrong matrix size\n";
            return;
        }
    }

    void fillRandValueMatrix(){
        for(int x{0}; x < row; ++x){
            for(int y{0}; y < col; ++y){
                set(x,y, rand() % 10);
            }
        }
    }

    T searchDet(){
        if(row <= 0 || col <= 0){
            std::cout << "Wrong matrix size\n";
            return 0;
        }
        if(row != col){
            std::cout << "Only for square matrix\n";
            return 0;
        }else if(row == 1){
            return M[0][0];
        }else if(row == 2){
            return M[0][0] * M[1][1] - M[0][1] * M[1][0];
        }else if(row == 3){
            return
                M[0][0] * M[1][1] * M[2][2] +
                M[2][0] * M[0][1] * M[1][2] +
                M[1][0] * M[2][1] * M[0][2] -
                M[2][0] * M[1][1] * M[0][2] -
                M[0][0] * M[2][1] * M[1][2] -
                M[1][0] * M[0][1] * M[2][2];
        }else if(row > 3){
            std::cout << "Only for 3x3 max matrix\n";
            return 0;
        }
    }

    ~Matrix(){
        if(col > 0){
            for(int x{0}; x < row; ++x){
                delete[] M[x];
            }
        }

        if(row > 0) delete[] M;

    }

};


class MyIter{
private:
    const std::vector<int> &m_values;
public:
    MyIter(const std::vector<int> &values) : m_values(values){}

    auto begin() const -> decltype(m_values.begin()) {
        return m_values.begin();
    }
    auto end() const -> decltype(m_values.end()){
        return m_values.end();
    }
    auto begin() -> decltype(m_values.begin()) {
        return m_values.begin();
    }
    auto end() -> decltype(m_values.end()){
        return m_values.end();
    }


};


void task_1(){
    std::list<float> f_list;
    f_list = {1.4, 2.8, 3.1, 4.3}; // 1.4 2.8 3.1 4.3 2.9
    printList(f_list);
    insertList(f_list);
    printList(f_list);
}

void task_2(){
    Matrix<int> matrix{3,3};
    matrix.printMatrix();

    /*
    //  11	-3
    // -15	-2
    //det = -67

    matrix.set(0,0,11);
    matrix.set(1,1, -2);
    matrix.set(0,1,-3);
    matrix.set(1,0,-15);
    */

    /*
    //  1  -2	3
    //  4	0	6
    // -7	8	9

    //det = 204

    matrix.set(0,0,1);
    matrix.set(0,1, -2);
    matrix.set(0,2,3);
    matrix.set(1,0,4);
    matrix.set(1,1,0);
    matrix.set(1,2, 6);
    matrix.set(2,0,-7);
    matrix.set(2,1,8);
    matrix.set(2,2,9);
    */

    matrix.fillRandValueMatrix();
    matrix.printMatrix();
    std::cout << "det = " << matrix.searchDet();
}

void task_3(){
    std::vector<int> values = { 1, 2, 3, 4 };
    for(int v : MyIter(values)){
        std::cout << v << "\t";
    }
}

int main() {
    //task_1();
    //task_2();
    task_3();




    return 0;
}
