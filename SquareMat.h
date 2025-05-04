#include <iostream>

namespace matrices{
    
    class SquareMat{
    
        protected:
            const size_t mat_size;
            double** square_matrix;
    
        public:
            //If the entered size is 0 then the matrix is considered empty, and thus square_matrix is set to nullptr
            SquareMat(size_t size_of_matrix = 3);
            SquareMat(const SquareMat& src);
            ~SquareMat();

            void set_square_matrix(double** new_square_matrix, size_t size);
            void update_matrix(size_t collumn, size_t row, double new_elem);
            size_t get_size() const;
            /*Returns a deep copy of the double** square_matrix.
             Since a deep copy is returned, it must also be deleted using delete_matrix.
            */
            double** get_matrix() const;
            static void delete_matrix(double** matrix, size_t size);

            SquareMat operator+ (const SquareMat& mat2) ;
            SquareMat operator- (const SquareMat& mat2) ;
            SquareMat& operator++();
            SquareMat operator++(int);
            SquareMat& operator--();
            SquareMat operator--(int);
            SquareMat operator=(const SquareMat& mat2);
            //SquareMat operator- (SquareMat matrix);
            SquareMat& operator-();
            friend SquareMat operator* (double scalar, const SquareMat& mat) ;
            SquareMat operator* (const SquareMat& mat2);
            SquareMat operator^ (const size_t mult);
            SquareMat operator% (const SquareMat& mat2) ;
            SquareMat operator% (int scalar);
            SquareMat operator/ (double divider) ;
            friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
            //Equal/Unequal operators. The same as == and != but for the matrices
            bool operator==(const SquareMat& mat2);
            bool operator!=(const SquareMat& mat2);
            //Strictly bigger, bigger-equal to, strictly smaller, smaller-equal to
            bool operator>(const SquareMat& mat2);
            bool operator>=(const SquareMat& mat2);
            bool operator<(const SquareMat& mat2);
            bool operator<=(const SquareMat& mat2);

            //Transpose operator ~
            void operator~();

            //+=, -=, *=, /=, %= adjusted for the square matrix class
            SquareMat operator-=(const SquareMat& mat);
            SquareMat operator+=(const SquareMat& mat);
            SquareMat operator*=(const SquareMat& mat);
            SquareMat operator*=(const double scalar);
            SquareMat operator/=(const SquareMat& mat);
            SquareMat operator%=(const SquareMat& mat);
            SquareMat operator%=(const double scalar);

            //Determinant operator
            friend double operator!(const SquareMat& mat);

            //Access operator [] (works with [][])
            double* operator[](size_t row);
            const double* operator[](size_t row) const;
    };
}