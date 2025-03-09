#include "../include/utilities.h"

const char json_replacement[JSON_REPLACEMENT_SIZE] = { '{', '}', '\"' };

char* get_json_data(char *json_data, const char *key) {
    if (json_data[0] == '\0' && key[0] == '\0') {
        return NULL;
    }
    char *token = malloc(JSON_MAX_SIZE * sizeof(char)),
         *temp = malloc(JSON_MAX_SIZE * sizeof(char)),
         *response = malloc(JSON_MAX_SIZE * sizeof(char));

    strcpy(temp, json_data);

    for (int i = 0; i < JSON_REPLACEMENT_SIZE; i++) {
        int x = 0;
        for (int j = 0; j <= strlen(temp); j++) {
            if (temp[j] != json_replacement[i]) {
                temp[x++] = temp[j];
            }
        }
    }

    token = strtok(temp, ",");

    while (token != NULL && token[0] != '\0') {
        if (strstr(token, key)) {
            response = strtok(token, ":");
            if (strstr(response, key)) {
                response = strtok(NULL, ":");
            }
        }
        token = strtok(NULL, ",");
    }

    return response;
}