#include <cstdio>
#include <string>
#define MAX_CHAR_PER_LINE 1000

class Line{
    char data[MAX_CHAR_PER_LINE];
public:
    Line(const char *line=""){strcpy(data, line);}
    void read(FILE *fp = stdin){fgets(data,MAX_CHAR_PER_LINE,fp);}
    void display(FILE *fp = stdout){fprintf(fp,"%s",data);}
    bool hasData(char* str){return strcmp(str,data)==0;}
};

inline void error(char *str){
    fprintf(stderr, "%s\n", str);
    exit(1);
};

class Node : public Line{
    Node* link;
public:
    Node(const char *str="") : Line(str), link(NULL){}
    Node* getLink() {return link;}
    void setLink(Node* next) {link = next;}
    
    void insertNext(Node *n){
        if(n!= NULL){
            n->link = link;
            link =n;
        }
    }

    Node * removeNext(){
        Node* removed = link;
        if(removed != NULL)
            link = removed -> link;
        return removed;
    }
};

class LinkedList{
protected:
    Node org; //헤드 노드
public :    
    LinkedList() : org("head node"){}
    ~LinkedList() {clear();}
    void clear() {while(!isEmpty()) delete remove(0);}
    Node * getHead() {return org.getLink();}
    bool isEmpty() {return getHead()==NULL;}

    Node * getEntry(int pos){
        Node* n = &org;
        for(int i=-1; i<pos; i++, n=n->getLink())
            if(n==NULL) break;
        return n;
    }

    void insert(int pos, Node *n){
        Node* prev = getEntry(pos-1);
        if(prev != NULL){
            prev -> insertNext(n);
        }
    }

    Node* remove(int pos){
        Node* prev = getEntry(pos-1);
        return prev->removeNext();
    }

    Node* find(char *str){
        for(Node *p=getHead(); p!=NULL; p=p->getLink())
            if(p->hasData(str)) return p;
        return NULL;
    }

    void replace(int pos, Node *n){
        Node* prev = getEntry(pos-1);
        if(prev != NULL){
            delete prev -> removeNext();
            prev->insertNext(n);
        }
    }

    int size(){
        int count = 0;
        for(Node *p = getHead(); p!=NULL; p=p->getLink())
            count++;
        return count;
    }

    void display(){
        printf("[단순연결리스트 항목 수 = %2d] : ", size());
        for(Node *p=getHead(); p!=NULL; p=p->getLink())
            p-> display();
        printf("\n");
    }
};

class LineEditor : public LinkedList{
public : 
    void Display(FILE *fp = stdout){
        int i=0;
        for(Node *p = getHead(); p!=NULL; p=p->getLink(), i++){
            fprintf(stderr, "%3d: ", i);
            p -> display(fp);
        }
    }

    void InsertLine(){
        int position;
        char line[MAX_CHAR_PER_LINE];
        printf(" 입력행 번호 : ");
        scanf("%d", &position);
        printf(" 입력행 내용 : ");
        fflush(stdin);
        fgets(line, MAX_CHAR_PER_LINE, stdin);

        insert(position, new Node(line));
    }

    void DeleteLine(){
        printf(" 삭제행 번호 : ");
        int position;
        scanf("%d", &position);

        remove(position);
    }

    void ReplaceLine(){
        int position;
        char line[MAX_CHAR_PER_LINE];
        printf(" 변경행 번호 : ");
        scanf("%d", &position);
        printf(" 변경행 내용 : ");
        fflush(stdin);
        fgets(line, MAX_CHAR_PER_LINE, stdin);

        replace(position, new Node(line));
    }

    // void LoadFile(char *fname){
    //     FILE *fp = fopen(fname, "r");
    //     if(fp != NULL){
    //         char line[MAX_CHAR_PER_LINE];
    //         while(fgets(line, MAX_CHAR_PER_LINE, fp)){
    //             insert(size(), new Node(line));
    //         }
    //         fclose(fp);
    //     }
    // }

    // void StoreFile(char *fname){
    //     FILE *fp = fopen(fname, "w");
    //     if(fp != NULL){
    //         Display(fp);
    //         fclose(fp);
    //     }
    // }

    void FindReplace(){
        char line[MAX_CHAR_PER_LINE];
        fflush(stdin);
        fgets(line, MAX_CHAR_PER_LINE, stdin);

    }
};

void Usage() {
    printf("[메뉴선택] i-입력,d-삭제,r-변경,p-출력,l-파일읽기,s-저장,q-종료=> "); 
}

int main(){
    LineEditor editor;
    char command;
    do{
        Usage();
        command = getchar();
        switch(command){
            case 'd': editor.DeleteLine(); break; // 한 행 삭제 
            case 'i': editor.InsertLine(); break; // 한 행 삽입 
            case 'r': editor.ReplaceLine(); break; // 한 행 변경 
            case 'f' : editor.FindReplace(); break; //찾아 바꾸기
            case 'p': editor.Display(); break; 
            case 'q': break;
        }
        fflush(stdin); //입력버퍼 지우기
    }while(command != 'q');
    return 0;
}