#include <iostream>

int main() {
    std::vector<float> X {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<float> Y {1, 3, 2, 5, 7, 8, 8, 9, 10, 12};
    float B_1;
    float B_0;
    std::vector<std::vector<float>> Z(10);
    Z[0] = X;
    Z[1] = Y;

    Linear_Regression <float,float> Reg_Class;
    Reg_Class.fit(Z);
    std::cout<<"\n";
    std::cout<< "Estimated Coefficients:\nb_0 = { "<< Reg_Class.b_0 << " }  \
          \nb_1 = { "<< Reg_Class.b_1 <<" }" <<std::endl;
    return 0;
}
