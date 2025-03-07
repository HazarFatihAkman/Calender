#include "../include/utilities.h"

const char json_replacement[JSON_REPLACEMENT_SIZE] = { '{', '}', '\"' };

char* get_json_data(char *json_data, char *key) {
    if (json_data[0] == '\0' && key[0] == '\0') {
        return NULL;
    }

    for (int i = 0; i < JSON_REPLACEMENT_SIZE; i++) {
        int x = 0;
        for (int j = 0; j <= strlen(json_data); j++) {
            if (json_data[j] != json_replacement[i]) {
                json_data[x++] = json_data[j];
            }
        }
    }

    char *token = strtok(json_data, ",");
    while (token != NULL && token[0] != '\0') {
        if (strstr(token, key)) {
            char *value = strtok(token, ":");
            if (strstr(value, key)) {
                value = strtok(NULL, ":");
            }
            json_data = value;
        }
        token = strtok(NULL, ",");
    }

    return json_data;
}