#include <iostream>
using namespace std;
long possiblePathsRecursive(int M, int N) {
    if (M==0 || N==0) {
        return 0;
    }

    if (M+N==2) {
        return 1;
    }

    return possiblePathsRecursive(M-1, N) + possiblePathsRecursive(M, N-1);
}

long possiblePathsIterative(int M, int N) {
    if(M==0||N==0){
        return 0;
    }
    int Matrix[M][N];
   /* int** Matrix = new int*[N];
    for(int i =0; i<N;++i){
        Matrix[i]=new int[M];
    }*/
    for (int i = 0; i< M; i++){
        for (int j = 0; j<N; j++){
            Matrix[i][j] = 1;
        }
    }
    //reference:https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
    for (int col = 1; col <M; col++) {
        for (int row = 1; row< N; row++)
            Matrix[col][row] =Matrix[col - 1][row] +Matrix[col][row - 1];
    }
    return Matrix[M-1][N-1];

}
