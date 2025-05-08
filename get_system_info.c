#include <stdlib.h>
#include <stdio.h>

void get_system_status(char* buffer, size_t size){
    FILE *fp = popen("uptime", "r");
    if(fp == NULL) {
        perror("open failure!");
        snprintf(buffer, size, "Error!");
        return;
    }
    fgets(buffer, size, fp);
    pclose(fp);
}

int get_top_info(char* buffer, size_t size){
    FILE *fp = popen("top -b -n1 | head -n 5", "r");
    if(fp == NULL) {
        perror("open failure!");
        snprintf(buffer, size, "Error!");
        return;
    }
    int byte_read = fread(buffer, 1, size - 1, fp);
    pclose(fp);
    return byte_read;
}