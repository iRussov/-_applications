#include <iostream>
#include "WF.h"
#include "WFOpt.h"

int main() {
    const char* sc = "no";
    const char* tc = "ono";

    WF wfObject;
    wfObject.Init(sc, tc);
    int distance = wfObject.Distance();

    int rows = wfObject.Rows();
    int columns = wfObject.Columns();

    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << wfObject.Get(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << distance<< " " << Distance(sc, tc);
}