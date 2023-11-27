#include "graphcraft.h"
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

static int N, C;
static vector< pair<int, int> > V[100000];

int main() {
    scanf("%d%d", &N, &C);
    for ( int i = 1; i < N; i++ ) {
        int T;
        scanf("%d", &T);
        for ( int j = 0; j < T; j++ ) {
            int A, B;
            scanf("%d%d", &A, &B);
            V[i].push_back(make_pair(A, B));
        }
    }
    printf("%d\n", graphcraft(N, C, V));
}
