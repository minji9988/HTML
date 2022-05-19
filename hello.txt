char ch;

FILE* fp; *ofp;           // 파일 한 개를 더 개방하는 거니까 ofp 추가 선언. 출력용으로 선언함
fp = fopen("a.txt", "r"); // fopen함수를 통해서 a.txt란 파일을 read 모드로 해서 개방해라(찾아라)

if(fp == NULL)           // 개방이 잘 됐는지 체크하는 것, Null이면 파일이 없는 것
{
    printf("file not found"); //파일이 없으면 없다고 알려주고
    exit(1);                      // 실행종료하기
}

ofp = fopen("b.txt", "w"); //a.txt에서 읽어와서 read모드로 오픈했잖아?
                           // b.txt로 다시 write 모드로 오픈할 거다. 

                           // b.txt가 현재 디렉터리에 없으면 null을 반환하는 게 아니라
                           // 빈 파일을 한 개 생성 시켜서 open을 해준다.

ch = fgetc(fp);
while(ch != -1)
{
    fputc(ch, ofp);        //출력할 문자 ch를 준다. ofp 파일과 연결되어 있는 게 b.txt다. 
                           // 거기에 hdd 생성되어 있을 것이고 
    ch = fgetc(fp);        // fp는 a.txt로부터 입력받은 문자를 출력하라 
}                          // a.txt에 있는 파일의 내용을 b.txt로 복사하는 것이다. 

fclose(ofp);