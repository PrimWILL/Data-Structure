#include "dir_file.h"
#include "utils.h"

void open_file(char* fname, FILE** input) {
	assert(fname != NULL);

	if (access(fname, F_OK) == -1) {
		fprintf(stderr, "The '%s' file does not exists\n",  fname);
		exit(1);
	}

	*input = fopen(fname, "r");

	if (input == NULL) {
		fprintf(stderr, "The '%s' file did not open\n", fname);
		exit(1);
	}

}

// This parse_str_to_list() split string to the tokens, and put the tokens in token_list.
// The value of return is the number of tokens.

int parse_str_to_list(const char* str, char*** token_list) {
	int num_token;
	int cnt = 0;
	int newline = 0;
	printf("2");
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

	// token 개수 세기
	for(int i = 0; i < newline; i++){
		num_token += slash[i];
	}

	// token_list에 2차원 배열 동적할당
	*token_list = calloc(newline + 1, sizeof(char**));
	for(int i = 0; i < newline + 1; i++){
		token_list[i] = calloc(10, sizeof(char*));
	}

	// str문자열 내용을 잘라서 token_list에 넣기
	char *ptr = strtok(string, "/\n");
	int i = 0;
	int j = 0;
    while (ptr != NULL)     
    {
		token_list[i][j] = ptr;
        j++;                       // 인덱스 증가

		if(j == slash[i]){
			j = 0;
			i++;
		}

        ptr = strtok(NULL, " ");   // 다음 문자열을 잘라서 포인터를 반환
    }
	return num_token;
}

void free_token_list(char** token_list, int num_token) {
	int index;

	for (index = 0; index < num_token; index++) {
		free(token_list[index]);
	}

	free(token_list);
}

