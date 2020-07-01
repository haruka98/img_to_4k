#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("Please drag and drop your images on the \"better.exe\".\n");
		system("Pause");
	} else {
		for(int i = 1; i < argc; i++) {
			char dir_str[255] = "";
			strcat(dir_str, _pgmptr);
			dir_str[strlen(dir_str) - 10] = 0;
			char cmd_str[255] = "";
			strncat(cmd_str, dir_str, 2);
			strcat(cmd_str, " & cd ");
			strcat(cmd_str, dir_str);
			strcat(cmd_str, "waifu2x-caffe_1.2.0.3 & start waifu2x-caffe-cui.exe -m noise -n 3 -p gpu -e png -i ");
			strcat(cmd_str, argv[i]);
			strcat(cmd_str, " -o ");
			char path_str[255] = "";
			int pos = 0;
			for(int j = 0; j < strlen(argv[i]); j++) {
				if(argv[i][j] == '\\') {
					pos = j;
				}
			}
			for(int j = 0; j <= pos; j++) {
				strncat(path_str, &(argv[i][j]), 1);
			}
			strcat(path_str, "better_");
			for(int j = pos + 1; j < strlen(argv[i]); j++) {
				strncat(path_str, &(argv[i][j]), 1);
			}
			strcat(cmd_str, path_str);
			printf(cmd_str);
			system(cmd_str);
			system("Pause");
		}
	}
	return 0;
}
