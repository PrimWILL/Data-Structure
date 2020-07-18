#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void str(char*** list){
    *list = calloc(3,sizeof(char**));
    for(int i = 0; i < 3; i++){
        list[i] = calloc(8, sizeof(char*));
    }
    char *pstring = "/hello\n/home/directory/\n/home/hello\n/home/directory/\n/home/\n//happy/hom.c";
    char string [100];
    int i;
    for(i = 0; pstring[i] != '\0'; i++){
        printf("%c ", pstring[i]);
        string[i] = pstring[i];
    }

    printf("\n");
    string[i] = '\0';
    char *ptr = strtok(string, "/\n");  
	ptr = strtok(NULL, "/\n");
    while (ptr != NULL)     
    {
		int i = 0;
        int j = 0;
        list[i][j] = ptr;
        j++;
        printf("%s\n", list[i][j]);                     // 인덱스 증가
        if(ptr = '\n') i++;
        ptr = strtok(NULL, " ");   // 다음 문자열을 잘라서 포인터를 반환
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            list[i][j] = string;
            printf("%s", list[i][j]);
        }
        printf("\n");
    }
    
}

void copy(char** list){
    char *pstring = "/hello\n/home/directory/\n/home/hello\n/home/directory/\n/home/\n//happy/hom.c";
    char string [100];
    int i;
    for(i = 0; pstring[i] != '\0'; i++){
        printf("%c ", pstring[i]);
        string[i] = pstring[i];
    }

    printf("\n");
    string[i] = '\0';
    printf("%s\n", string);
    // char string[100] = "/hello\n/home/directory/\n/home/\n//happy/hom.c";
    char *ptr = strtok(string, "/\n");  
    i = 0;
    while (ptr != NULL)
    {
        
		list[i] = ptr;
        // printf("%d\n", i);
        printf("%d %s\n", i,list[i]);
        i++;
        ptr = strtok(NULL, "/\n");   // 다음 문자열을 잘라서 포인터를 반환
    }
}*/
int parse_str_to_list(const char* str, char*** token_list) {
	int num_token;
	int cnt = 0;
	int newline = 0;
	for(int i = 0; str[i] != NULL; i++) {
		if(str[i] == '\n') {
			newline++; // 파일 경로 개수 세기
		}
	}
    
	// str문자열 내용을 string문자배열에 복사
    char string[1024]; 
	int x;
    for(x = 0; str[x] != '\0'; x++){
        string[x] = str[x];
    }
    string[x] = '\0';
    printf("strcpy\n");
    printf("%s\n", string);


	// 한 줄 당 token 개수 세기
	int slash[newline];
    for(int i = 0; i < newline; i++){
        slash[i] = 0;
    }
	for(int i = 0, j = 0; string[i + 1] != NULL; i++){
			if((string[i] == '/') && (string[i + 1] != '\n') && (string[i + 1] != '\0')) { slash[j]++; }
			else if(((string[i] == '/') && ((string[i + 1]) == '\n'))) {
                j++;
                i++;
            }
			else if(string[i] == '\n') {
                j++;
            }
	}
    for(int i = 0; i < newline; i++){
        printf("%d ", slash[i]);
    }
	printf("slash\n");


	// token 개수 세기
	for(int i = 0; i < newline; i++){
		num_token += slash[i];
	} printf("token\n");
    printf("%d\n", num_token);

	// token_list에 2차원 배열 동적할당
	*token_list = calloc(newline + 1, sizeof(char**));
	for(int i = 0; i < newline + 1; i++){
		token_list[i] = calloc(10, sizeof(char*));
	} printf("calloc\n");

	// str문자열 내용을 잘라서 token_list에 넣기
	char *ptr = strtok(string, "/\n");
	int i = 0;
	int j = 0;
    while (ptr != NULL)     
    {
		token_list[i][j] = ptr;
        j++;                       // 인덱스 증가
        printf("%d %s\n", i, token_list[i][j]);

		if(j == slash[i]){
			j = 0;
			i++;
		}
        ptr = strtok(NULL, " ");   // 다음 문자열을 잘라서 포인터를 반환
    }
    printf("strtok\n");
	return num_token;
}
int main(void){
    char** list = NULL;
    char string[150] = "/hello\n/home/directory/\n/home/\n/happy/hom.c\n/primwill/user/string/hey.pdf\n/pledgemo/hahaha/brand/new/stars/\n";
    parse_str_to_list(string, &list);
    printf("11111%s\n", list[0]);
    free(list);
    return 0;
}