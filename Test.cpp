#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.cpp"
using namespace matrices;

TEST_CASE("Unary minus -SquareMat") {
    SquareMat mat(2);
    mat.update_matrix(0, 0, 1);
    mat.update_matrix(0, 1, -2);
    mat.update_matrix(1, 0, 3);
    mat.update_matrix(1, 1, -4);

    SquareMat neg = -mat;
    CHECK(neg[0][0] == -1);
    CHECK(neg[0][1] == 2);
    CHECK(neg[1][0] == -3);
    CHECK(neg[1][1] == 4);
}

TEST_CASE("Addition and subtraction") {
    SquareMat a(2), b(2);
    a.update_matrix(0, 0, 1);
    a.update_matrix(1, 1, 2);
    b.update_matrix(0, 0, 3);
    b.update_matrix(1, 1, 4);

    SquareMat c = a + b;
    SquareMat d = b - a;
    CHECK(c[0][0] == 4);
    CHECK(c[1][1] == 6);
    CHECK(d[0][0] == 2);
    CHECK(d[1][1] == 2);
}

TEST_CASE("Increment and Decrement") {
    SquareMat mat(2);
    mat.update_matrix(0, 0, 1);

    SquareMat pre = ++mat;
    CHECK(pre[0][0] == 2);

    SquareMat post = mat++;
    CHECK(post[0][0] == 2);
    CHECK(mat[0][0] == 3);

    SquareMat preDec = --mat;
    CHECK(preDec[0][0] == 2);

    SquareMat postDec = mat--;
    CHECK(postDec[0][0] == 2);
    CHECK(mat[0][0] == 1);
}

TEST_CASE("Assignment") {
    SquareMat a(2);
    a.update_matrix(0, 0, 5);
    SquareMat b = a;
    CHECK(b[0][0] == 5);
}

TEST_CASE("Scalar multiplication and matrix multiplication") {
    SquareMat mat(2);
    mat.update_matrix(0, 0, 2);
    mat.update_matrix(1, 1, 3);

    SquareMat result = 2 * mat;
    CHECK(result[0][0] == 4);
    CHECK(result[1][1] == 6);

    SquareMat m2(2);
    m2.update_matrix(0, 0, 1);
    m2.update_matrix(1, 1, 1);
    SquareMat mul = mat * m2;
    CHECK(mul[0][0] == 2);
    CHECK(mul[1][1] == 3);
}

TEST_CASE("Power operator ^") {
    SquareMat mat(2);
    mat.update_matrix(0, 0, 2);
    mat.update_matrix(1, 1, 3);

    SquareMat squared = mat ^ 2;
    CHECK(squared[0][0] == 4);
    CHECK(squared[1][1] == 9);
}

TEST_CASE("Modulo operations") {
    SquareMat a(2), b(2);
    a.update_matrix(0, 0, 10);
    b.update_matrix(0, 0, 3);

    SquareMat mod = a % b;
    CHECK(mod[0][0] == 30);

    SquareMat modScalar = a % 4;
    CHECK(modScalar[0][0] == 2);
}

TEST_CASE("Division") {
    SquareMat mat(2);
    mat.update_matrix(0, 0, 10);

    SquareMat div = mat / 2;
    CHECK(div[0][0] == 5);
}

TEST_CASE("Comparison operators") {
    SquareMat a(2), b(2);
    a.update_matrix(0, 0, 2);
    b.update_matrix(0, 0, 3);

    CHECK(a != b);
    CHECK(b > a);
    CHECK(a < b);
    CHECK(b >= a);
    CHECK(!(a >= b));
}

TEST_CASE("Transpose operator") {
    SquareMat mat(2);
    mat.update_matrix(0, 1, 5);
    ~mat;
    CHECK(mat[1][0] == 5);
}

TEST_CASE("Compound operators") {
    SquareMat a(2), b(2);
    a.update_matrix(0, 0, 1);
    b.update_matrix(0, 0, 2);

    a += b;
    CHECK(a[0][0] == 3);

    a -= b;
    CHECK(a[0][0] == 1);

    a *= b;
    CHECK(a[0][0] == 2);

    a *= 2;
    CHECK(a[0][0] == 4);

    a %= 3;
    CHECK(a[0][0] == 1);

    a %= b;
    CHECK(a[0][0] == 1);
}

TEST_CASE("Determinant operator") {
    SquareMat mat(2);
    mat.update_matrix(0, 0, 1);
    mat.update_matrix(0, 1, 2);
    mat.update_matrix(1, 0, 3);
    mat.update_matrix(1, 1, 4);

    double det = !mat;
    CHECK(det == doctest::Approx(-2));
}

TEST_CASE("Stream operator <<") {
    SquareMat mat(1);
    mat.update_matrix(0, 0, 42);
    std::ostringstream oss;
    oss << mat;
    CHECK(oss.str().find("42") != std::string::npos);
}
