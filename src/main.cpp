//
// Created by nannullna on 2021/04/26.
//
#include <iostream>

int main() {

    int seq1Length = 16;
    int seq2Length = 16;

    int NT = 16;
    int DIVIDE = 4;
    int N_CHUNKS = NT * DIVIDE;

    for (int t = 0; t < NT; t++) {

        int counts = 0;

        std::cout << "====== Thread " << t << " ======" << std::endl;

        int ei = 0;
        int ej = 0;

        for (int p = 0; p < 2 * N_CHUNKS - 1; p++) {

            std::cout << "phase: " << p << std::endl;

            for (int ej = t; ej <= p; ej += NT) {

                ei = p - ej;

                if (ei >= N_CHUNKS || ej >= N_CHUNKS) {
                    // boundary condition
                    continue;
                }

                std::cout << "t" << t << " - " << ei << ", " << ej << std::endl;
                counts++;

            }

        }

        std::cout << "Total calculation done by thread " << t << ": " << counts << std::endl;

    }

}