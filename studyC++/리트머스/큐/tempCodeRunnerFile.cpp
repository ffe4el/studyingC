while(q.empty()==false){
        Location2D here=q.front();  //덱의 front 상단 객체 복사
        q.pop(); //덱의 상단 객체 삭제
        cnt++;

        int r=here.row; 
        int c = here.col;
        // printf("(%d, %d)", r,c);    //현재위치 화면 출력
        if(miro[r][c] =='T'){    // 출구를 만났으면 -> 탐색 성공
            cout << cnt <<endl;
            return 0;
        }
        else {      //출구가 아니면
            miro[r][c] ='.'; //현재 위치를 지나옴처리
            if(isValidLoc(n,m,r-1,c,miro)) q.push(Location2D(r-1,c));
            if(isValidLoc(n,m,r+1,c,miro)) q.push(Location2D(r+1,c));
            if(isValidLoc(n,m,r,c-1,miro)) q.push(Location2D(r,c-1));
            if(isValidLoc(n,m,r,c+1,miro)) q.push(Location2D(r,c+1));
        }
    }