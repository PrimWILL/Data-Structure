#include "utils.h"
#include "dir_file.h"

int main(int argc, char **argv) {	
	char buff[MAX_BUFFER_SIZE];
	int num_token;
	char **token_list, *dir_fname, *file_fname;
	directory_t *dir, *root_dir;
	FILE *file_input, *dir_input;

	if (argc != 3) {
		fprintf(stderr, "Usage: pa0_b <file_input file> <dir_input file>\n");
		exit(1);
	}

	file_fname = argv[1];
	dir_fname = argv[2];

	open_file(file_fname, &file_input); // file_input 열기
	open_file(dir_fname, &dir_input);   // dir_input 열기

	root_dir = create_dir("root"); 
    /*
    directory_t* create_dir(char* name) {
        directory_t *dir;

        dir = (directory_t*)malloc(sizeof(directory_t));

        assert(name != NULL);
        assert(dir != NULL);
        
        memcpy(dir->name, name, MAX_NAME_SIZE);
        
        dir->num_file = 0;
        dir->num_dir = 0;	

        return dir;

    }*/
	
	// Parse the string written in file_input and create a hierarchical structure of directories and files.
	while (fgets(buff, MAX_BUFFER_SIZE, file_input) != NULL) {
		token_list = NULL;
		num_token = 0;

		num_token = parse_str_to_list(buff, &token_list);
        // file_input을 '/' 또는 개행문자로 단위로 하여 tokenize
        // 그 결과로 만들어진 token을 token_list에 저장

		make_dir_and_file(root_dir, token_list, num_token);
        // root_dir 디렉토리를 시작
        // token_list에 있는 token을 이용해 디렉토리와 파일들의 계층적 구조로 만듦

		free_token_list(token_list, num_token);
        // token_list 함수 메모리 해제
        /*
        void free_token_list(char** token_list, int num_token) {
            int index;

            for (index = 0; index < num_token; index++) {
                free(token_list[index]);
            }

            free(token_list);
        }*/     
	}

	// Find the location of directory written in dir_input and print the file in it.
	while (fgets(buff, MAX_BUFFER_SIZE, dir_input) != NULL) {	
		token_list = NULL;
		dir = NULL;
		num_token = 0;

		num_token = parse_str_to_list(buff, &token_list);
        // dir_input을 '/' 또는 개행문자로 단위로 하여 tokenize
        // 그 결과로 만들어진 token을 token_list에 저장

		dir = find_target_dir(root_dir, token_list, num_token);
        /*
        directory_t* find_target_dir(directory_t* root_dir, char** token_list, int num_token) {
            directory_t *current_dir, *child_dir;
            char *token;
            char path[MAX_BUFFER_SIZE];
            int index;

            memset(path, 0, MAX_BUFFER_SIZE); // path를 MAX_BUFFER_SIZE만큼 0으로 초기화
            
            current_dir = root_dir;

            for (index = 0; index < num_token; index++) {
                strcat(path, "/");  // path에 "/" 붙이기 
                token = token_list[index];
                child_dir = find_dir(current_dir, token);

                if (child_dir == NULL) {
                    fprintf(stderr, "Not found '%s' directory in %s\n", token, path);
                    return NULL;
                }

                current_dir = child_dir;
                strcat(path, token); // path에 token(=token_list[index]) 붙이기	
                child_dir = NULL;
            }

            return current_dir;
        }
        */

		if (dir == NULL) {
			free_token_list(token_list, num_token); 
			continue;
		}

		print_file_on_dir(dir);
        /*
        void print_file_on_dir(directory_t* dir) {
            int index = 0;

            for (index = 0; index < dir->num_file; index++)
                printf("%s\n", dir->file_list[index]->name);	
        }*/
		
		free_token_list(token_list, num_token);
    }

	free_dir_and_file(root_dir);

	fclose(file_input);
	fclose(dir_input);

	return 0;	
}

