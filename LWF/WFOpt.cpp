#include "WFOpt.h"
#include <algorithm>

int Distance(const char* s, const char* t) {
    int M = strlen(s);
    int N = strlen(t);

    int* p1 = new int[N];
    int* p2 = new int[N];

    for (int j = 0; j < N; j++) {
        p1[j] = j;
    }

    for (int i = 1; i <= M; i++) {
        p2[0] = i; 
		
        for (int j = 1; j < N; j++) {
            int penalty = (s[i - 1] == t[j - 1]) ? 0 : 1;
            p2[j] = std::min({ p1[j] + 1, p2[j - 1] + 1, p1[j - 1] + penalty });
        }

        std::swap(p1, p2);
    }

    int distance = p2[N - 1]; 

    delete[] p1;
    delete[] p2;

    return distance;
}
