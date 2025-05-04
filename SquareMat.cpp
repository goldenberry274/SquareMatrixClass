#include <iostream>
#include <cmath>

#include "SquareMat.h"

namespace matrices{

    bool element_check(double** arr, size_t size){
        if (arr == nullptr)
            return false;
        for (int i = 0; i < size; i++){
            if (arr[i] == nullptr)
                return false;
        }
        return true;
    }
    SquareMat::SquareMat(size_t size_of_matrix) : mat_size(size_of_matrix) {
        if (mat_size == 0){
            square_matrix = nullptr;
            return;
        }

        square_matrix = new double*[mat_size];
        for (int i = 0; i < mat_size; i++){
            square_matrix[i] = new double[mat_size];
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = 0.0;
            }
        }
    }
    SquareMat::SquareMat(const SquareMat& src) : mat_size(src.get_size()){
        

        /*if (square_matrix != nullptr){
            for (int i = 0; i < mat_size; i++){
                delete[] square_matrix[i];
            }
            delete[] square_matrix;
        }*/

        
        square_matrix = new double*[mat_size];
        for (int i = 0; i < mat_size; i++){
            square_matrix[i] = new double[mat_size];
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = src.square_matrix[i][j];
            }
        }
    }

    SquareMat::~SquareMat(){
        if (nullptr == square_matrix)
            return;
        for (int i = 0; i < mat_size; i++){
            delete[] square_matrix[i];
        }
        delete[] square_matrix;
    }

    size_t SquareMat::get_size() const{
        if (nullptr == square_matrix)
            return 0;
        return mat_size;
    }

    void SquareMat::set_square_matrix(double** new_square_matrix, size_t size){
        if (size == 0 || size != mat_size)
            throw "Invalid argument";

        if (square_matrix != nullptr){
            for (int i = 0; i < mat_size; i++){
                delete[] square_matrix[i];
            }
            delete[] square_matrix;
        }

        square_matrix = new double*[mat_size];
        for (int i = 0; i < size; i++){
            square_matrix[i] = new double[mat_size];

            for (int j = 0; j < size; j++){
                square_matrix[i][j] = new_square_matrix[i][j];
            }
        }
    }
    void SquareMat::update_matrix(size_t collumn, size_t row, double new_elem){
        if (collumn >= mat_size || row >= mat_size)
            throw "Invalid Argument";

        square_matrix[collumn][row] = new_elem;
    }

    double** SquareMat::get_matrix() const{
        if (nullptr == square_matrix)
            return square_matrix;
        
        double** copy_of_matrix = new double*[mat_size];
        for (int i = 0; i < mat_size; i++){
            copy_of_matrix[i] = new double[mat_size];
            for (int j = 0; j < mat_size; j++){
                copy_of_matrix[i][j] = square_matrix[i][j];
            }
        }
        return copy_of_matrix;
        
    }

    void SquareMat::delete_matrix(double** matrix, size_t size){
        if (matrix == nullptr)
            return;
        for (int i = 0; i < size; i++){
            if (matrix[i] != nullptr)
                delete[] matrix[i];
        }
        delete[] matrix;
    }

    SquareMat SquareMat::operator+ (const SquareMat& mat2) {
        if (mat2.square_matrix == nullptr || mat2.get_size() != mat_size)
            throw "Illegal Argument";
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1Plus2(mat2.get_size());

        for (int i = 0; i < mat_size; i++){
            if (square_matrix[i] == nullptr || mat2.square_matrix[i] == nullptr)
                continue;
            for (int j = 0; j < mat_size; j++){
                mat1Plus2.square_matrix[i][j] = square_matrix[i][j] + mat2.square_matrix[i][j];
            }
        }
        return mat1Plus2;

    }

    SquareMat SquareMat::operator-(const SquareMat& mat2) {
        if (mat2.square_matrix == nullptr || mat2.get_size() != mat_size)
            throw "Illegal Argument";
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1Minus2(mat2.get_size());
        
        for (int i = 0; i < mat_size; i++){
            
            for (int j = 0; j < mat_size; j++){
                mat1Minus2.square_matrix[i][j] = square_matrix[i][j] - mat2.square_matrix[i][j];
            }
        }
        return mat1Minus2;

    }
    SquareMat& SquareMat::operator-(){
        
        if (nullptr == square_matrix)
            throw "Invalid argument";
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }    
        
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = - square_matrix[i][j];
            }
        }  
        return (*this);
    }
    /*
    SquareMat SquareMat::operator- (SquareMat matrix){
        if (nullptr == square_matrix)
            return;
        SquareMat opposite_sign_mat(matrix.get_size());
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                opposite_sign_mat.square_matrix[i][j] = - square_matrix[i][j];
            }
        }  
        return opposite_sign_mat;  
    }*/

    SquareMat SquareMat::operator/(double divider){
        if (divider == 0)
            throw "Invalid argument";
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1DivideBYScalar(mat_size);
        
        for (int i = 0; i < mat_size; i++){

            for (int j = 0; j < mat_size; j++){
                mat1DivideBYScalar.square_matrix[i][j] = square_matrix[i][j] / divider;
            }
        }

        return mat1DivideBYScalar;
    }

    
    SquareMat operator* (double scalar, const SquareMat& mat) {
        
        if (!element_check(mat.square_matrix, mat.get_size())){
            throw "Invalid argument";
        }
        SquareMat mat1TimesScalar(mat.get_size());

        for (int i = 0; i < mat.get_size(); i++){
            for (int j = 0; j < mat.get_size(); j++){
                mat1TimesScalar.square_matrix[i][j] = scalar * mat.square_matrix[i][j]; 
            }
        }

        return mat1TimesScalar;
    }
    
    SquareMat SquareMat::operator*(const SquareMat& mat2){
        if (mat2.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1TimesMat2(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){

                for (int k = 0; k < mat_size; k++){
                    mat1TimesMat2.square_matrix[i][j] += square_matrix[i][k] * 
                                                        mat2.square_matrix[k][j];
                }
            }
        }

        return mat1TimesMat2;
        
    }

    SquareMat SquareMat::operator^(const size_t mult){
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }
        SquareMat matToPowerOfScalar(mat_size);

        if (mult == 0){
            for (int i = 0; i < mat_size; i++){
                for (int j = 0; j < mat_size; j++){
                    matToPowerOfScalar.square_matrix[i][j] = 1;
                }
            }
            return matToPowerOfScalar;
        }

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                matToPowerOfScalar.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        for (int i = 1; i < mult; i++){
            matToPowerOfScalar *= matToPowerOfScalar;
        }

	    return matToPowerOfScalar;
    }
    SquareMat SquareMat::operator% (const SquareMat& mat2) {
        if (mat2.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1TimeMat2(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                mat1TimeMat2.square_matrix[i][j] = square_matrix[i][j] * mat2.square_matrix[i][j];
            }
        }
            
        return mat1TimeMat2;
    }

    SquareMat SquareMat::operator% (int scalar){
        if (scalar == 0)
            throw "Invalid argument";

        SquareMat mat1ModuluScalar(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                mat1ModuluScalar.square_matrix[i][j] = fmod(square_matrix[i][j], static_cast<double>(scalar));
            }
        }

        return mat1ModuluScalar;
    }

    std::ostream& operator<<(std::ostream& os, const SquareMat& mat){
        if (nullptr == mat.square_matrix){
            std::cout << "Empty matrix";
            return os;
        }
        if (!element_check(mat.square_matrix, mat.mat_size)){
            throw "Invalid argument";
        }
        

        for (int i = 0; i < mat.mat_size; i++){
            for (int j = 0; j < mat.mat_size; j++){
                os << mat.square_matrix[i][j] << " ";
            }
            os << '\n';
        }

        return os;
    }

    bool SquareMat::operator==(const SquareMat& mat2){
        if (nullptr == mat2.square_matrix || mat2.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                if (square_matrix[i][j] != mat2.square_matrix[i][j])
                    return false;
            }
        }

        return true;
    }

    bool SquareMat::operator!=(const SquareMat& mat2){
        if (nullptr == mat2.square_matrix || mat2.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }        
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                if (square_matrix[i][j] != mat2.square_matrix[i][j])
                    return true;
            }
        }

        return false;
    }

    bool SquareMat::operator>(const SquareMat& mat2){
        if (nullptr == mat2.square_matrix || mat2.mat_size != mat_size)
            return false;
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }    
        double sum1 = 0;
        double sum2 = 0;    
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                sum1 += square_matrix[i][j];
                sum2 += mat2.square_matrix[i][j];
            }
        }

        return sum1 > sum2;
    }

    bool SquareMat::operator>=(const SquareMat& mat2){
        if (nullptr == mat2.square_matrix || mat2.mat_size != mat_size)
            return false;
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }        
        double sum1 = 0;
        double sum2 = 0;    
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                sum1 += square_matrix[i][j];
                sum2 += mat2.square_matrix[i][j];
            }
        }

        return sum1 >= sum2;
    }

    bool SquareMat::operator<(const SquareMat& mat2){
        if (nullptr == mat2.square_matrix || mat2.mat_size != mat_size)
            return false;
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }        
        double sum1 = 0;
        double sum2 = 0;    
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                sum1 += square_matrix[i][j];
                sum2 += mat2.square_matrix[i][j];
            }
        }
        return sum1 < sum2;
    }

    bool SquareMat::operator<=(const SquareMat& mat2){
        if (nullptr == mat2.square_matrix || mat2.mat_size != mat_size)
            return false;
        if (!element_check(mat2.square_matrix, mat2.mat_size)){
            throw "Invalid argument";
        }        
        double sum1 = 0;
        double sum2 = 0;    
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                sum1 += square_matrix[i][j];
                sum2 += mat2.square_matrix[i][j];
            }
        }

        return sum1 <= sum2;
    }

    void SquareMat::operator~() {
        if (!element_check(square_matrix, mat_size)) {
            throw "Invalid argument";
        }
    
        for (int i = 0; i < mat_size; ++i) {
            for (int j = i + 1; j < mat_size; ++j) {
                std::swap(square_matrix[i][j], square_matrix[j][i]);
            }
        }
    }
    SquareMat& SquareMat::operator++(){
        if (square_matrix == nullptr)
            throw "Invalid argument";
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }        
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] += 1.0;
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator++(int){
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    SquareMat& SquareMat::operator--(){
        if (square_matrix == nullptr)
            throw "Invalid argument";
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }
        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] += -1.0;
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator--(int){
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }
        SquareMat temp(*this);
        --(*this);
        return temp;
    }
    
    SquareMat SquareMat::operator+=(const SquareMat& mat){
        if (mat.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat.square_matrix, mat.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1Plus2(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = square_matrix[i][j] + mat.square_matrix[i][j];
                mat1Plus2.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        return mat1Plus2;
    }

    SquareMat SquareMat::operator-=(const SquareMat& mat){
        if (mat.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat.square_matrix, mat.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1Minus2(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = square_matrix[i][j] - mat.square_matrix[i][j];
                mat1Minus2.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        return mat1Minus2;
    }

    SquareMat SquareMat::operator*=(const SquareMat& mat){
        if (mat.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat.square_matrix, mat.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1Times2(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = square_matrix[i][j] * mat.square_matrix[i][j];
                mat1Times2.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        return mat1Times2;
    }

    SquareMat SquareMat::operator*=(const double scalar){
        
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1TimesScalar(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = square_matrix[i][j] * scalar;
                mat1TimesScalar.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        return mat1TimesScalar;
    }

    SquareMat SquareMat::operator%=(const SquareMat& mat){
        if (mat.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat.square_matrix, mat.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1Modulu2(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = fmod(square_matrix[i][j],mat.square_matrix[i][j]);
                mat1Modulu2.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        return mat1Modulu2;
    }

    SquareMat SquareMat::operator%=(const double scalar){
        
        if (!element_check(square_matrix, mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1Modulu2(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                square_matrix[i][j] = fmod(square_matrix[i][j], scalar);
                mat1Modulu2.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        return mat1Modulu2;
    }

    SquareMat SquareMat::operator/=(const SquareMat& mat){
        if (mat.mat_size != mat_size)
            throw "Invalid argument";
        if (!element_check(mat.square_matrix, mat.mat_size)){
            throw "Invalid argument";
        }
        SquareMat mat1DividedByScalar(mat_size);

        for (int i = 0; i < mat_size; i++){
            for (int j = 0; j < mat_size; j++){
                if (mat.square_matrix[i][j] == 0)
                    throw "Invalid argument";
                square_matrix[i][j] = square_matrix[i][j] / mat.square_matrix[i][j];
                mat1DividedByScalar.square_matrix[i][j] = square_matrix[i][j];
            }
        }

        return mat1DividedByScalar;
    }

    double operator!(const SquareMat& mat){
        if (!element_check(mat.square_matrix, mat.mat_size)){
            throw "Invalid argument";
        }
        double det = 1.0;
        double** mat_copy = mat.get_matrix();
        for (int i = 0; i < mat.mat_size; i++) {
            int pivot = i;
            for (int j = i + 1; j < mat.mat_size; j++) {
                if (std::abs(mat_copy[j][i]) > std::abs(mat_copy[pivot][i]))
                pivot = j;
            }

            if (pivot != i) {
            for (int k = 0; k < mat.mat_size; k++) {
                std::swap(mat_copy[i][k], mat_copy[pivot][k]);
            }
            det *= -1;
            }

            if (mat_copy[i][i] == 0) {
                return 0;
            }

            det *= mat_copy[i][i];
            for (int j = i + 1; j < mat.mat_size; j++) {
                double factor = mat_copy[j][i] / mat_copy[i][i];
                for (int k = i + 1; k < mat.mat_size; k++) {
                    mat_copy[j][k] -= factor * mat_copy[i][k];
                }
            }
        }
        SquareMat::delete_matrix(mat_copy, mat.mat_size);
        return det;
    }

    double* SquareMat::operator[](size_t row){
        if (row >= mat_size || square_matrix[row] == nullptr)
            throw "Invalid argument";
        return square_matrix[row];
    }

    const double* SquareMat::operator[](size_t row) const{
        if (row >= mat_size || square_matrix[row] == nullptr)
            throw "Invalid argument";
        return square_matrix[row];
    }
}
