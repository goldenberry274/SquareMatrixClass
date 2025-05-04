#include <iostream>

#include "SquareMat.h"

using namespace matrices;

void create_new_arr(double**& arr, size_t size, double new_elem);

int main(){

    //Creating new square matrix
    size_t size = 3;
    SquareMat mat(size);
    SquareMat matCopy(mat);
    std::cout <<"Printing matrix: \n" << mat << "\n";
    std::cout <<"Printing copy matrix: \n" << matCopy << "\n";
    //Testing get_matrix()
    double** mat_ptr = mat.get_matrix();
    std::cout << "Size given = " << size 
    << " Size of matrix = " << mat.get_size() << '\n';
    //Testing set_square_matrix()
    double** new_ptr;
    create_new_arr(new_ptr, size, 1);
    mat.set_square_matrix(new_ptr, size);
    SquareMat::delete_matrix(mat_ptr, size);
    std::cout <<mat;
    
    SquareMat mat2(size);
    mat2.update_matrix(0,0,1);
    std::cout << "Printing updated matrix\n" <<mat2 << '\n';

    SquareMat mat1Plus2 = mat + mat2;
    std::cout<<"Printing mat1 + mat2\n" << mat1Plus2 << "\n";

    SquareMat mat1Minus2 = mat - mat2;
    std::cout<<"Printing mat1 - mat2\n" << mat1Minus2 << "\n";

    SquareMat mat3(2);
    SquareMat mat4(2);
    mat3[0][0] = 2;
    mat3[1][1] = 3;
    mat4[0][0] = 1;
    mat4[1][1] = 1;
    SquareMat mul = mat3*mat4;
    std::cout << "Mat3 \n" << mat3 << "Mat4\n" << mat4 << "Mat3 * mat4\n" << mul << "\n";
    std::cout << "Mat3 / 3\n" << mat3/3 << "\n";
    std::cout << "Mat3 % 3\n" << mat3%3 << "\n";
    SquareMat mulPower = mat3^2;
    std::cout << "Mat3 ^ 2\n" << mulPower << '\n';
    std::cout << "Mat3 % mat4 (Multiplication of each element by the other correct one)\n" << mat3%mat4 << "\n";
    std::cout << "Determinant of mat3\n" << !mat3 << "\n";
    bool areTheyEqual = mat3==mat4;
    std::cout << "Mat3 == mat4 (Retuns false)\n" << areTheyEqual << "\n";
    areTheyEqual = mat3!=mat4;
    std::cout << "Mat3 != mat4 (Retuns true)\n" << areTheyEqual << "\n";
    areTheyEqual = mat3>=mat4;
    std::cout << "Mat3 >= mat4 (Retuns true)\n" << areTheyEqual << "\n";
    areTheyEqual = mat3>mat4;
    std::cout << "Mat3 > mat4 (Retuns true)\n" << areTheyEqual << "\n";
    areTheyEqual = mat3<=mat4;
    std::cout << "Mat3 <= mat4 (Retuns false)\n" << areTheyEqual << "\n";
    areTheyEqual = mat3<mat4;
    std::cout << "Mat3 < mat4 (Retuns false)\n" << areTheyEqual << "\n";

    SquareMat testingTrans(2);
    testingTrans[0][1] = 1;
    std::cout << "Testing transpose matrix:\n" << testingTrans << "\n"; 
    ~testingTrans;
    std::cout << "Transpose of\n" << testingTrans << "\n";

    SquareMat mat1Plus1 = ++mat;
    std::cout << mat << "++mat\n" << mat1Plus1 << "\n" ;
    mat++;
    std::cout << "mat++" << mat << "\n";

    SquareMat mat1Minus1 = --mat;
    std::cout << mat << "--mat\n" << mat1Minus1 << "\n" ;
    mat++;
    std::cout << "mat--" << mat << "\n";
    for (int i = 0; i < size; i++){
        delete[] new_ptr[i];
    }

    delete[] new_ptr;



    return 0;
}


void create_new_arr(double**& arr, size_t size, double new_elem){
    if (size == 0)
        return;
    arr = new double*[size];
    for (int i = 0; i < size; i++){
        arr[i] = new double[size];
        for (int j = 0; j < size; j++){
            arr[i][j] = new_elem;
        }
    }
}
