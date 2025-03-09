#ifndef DATE_H
#define DATE_H

// Validation
#define TITLE_MAX_LEN 50
#define CONTEXT_MAX_LEN 200
#define DAY_MAX 31
#define MONTH_MAX 12
#define HOUR_MAX 24
#define MINUTES_MAX 59

#define INVALID "\033[0;31m[INVALID]\033[0m %s : %s\n"

#include "utilities.h"
#include <time.h>
#include <string.h>

typedef struct {
    int day, month, year, hour, minutes;
} Date;

typedef struct {
    char title[TITLE_MAX_LEN], context[CONTEXT_MAX_LEN];
    int is_completed, id;
    Date date;
} Event;

typedef struct {
    Event *data;
    char *json;
} Event_Response;

int *cache_size;
Event_Response **Cache_Event;

Event_Response *create_event(Date, char[TITLE_MAX_LEN], char[CONTEXT_MAX_LEN]);
Event_Response *update_event(char*);
Event_Response *delete_event(int);
char* create_json(Event *e);
#endif