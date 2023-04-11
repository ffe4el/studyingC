//int형 2차원 배열 동적 할당 함수
int** alloc2DInt(int rows, int cols){
    if(rows<=0 || cols <=0) return 0;

    int ** mat = new int* [rows]; //포인터 변수를 저장할 배열
    
    //행렬의 각 행에 해당하는 배열의 주소를 저장하기 위한 배열 mat를 동적으로 할당.
    for(int i=0 ; i <rows ; i++){
        mat[i] = new int [cols]; //실제 각 행의 데이터를 저장할 배열
        return mat;
    }
}

//int형 2차원 배열 동적 해제 함수
void free2DInt(int **mat, int rows, int cols=0){
    if(mat != 0){
        for(int i=0; i<rows; i++){
            delete [] mat[i];
        }
        delete [] mat;
    }
}

