#include "../include/date.h"

static int validate_event(char title[TITLE_MAX_LEN], char context[CONTEXT_MAX_LEN]);
static int validate_date(Date date);

const char* event_keys[EVENT_KEY_SIZE] = { "id", "day", "month", "year", "hour", "minutes", "title", "context", "is_completed" };

Event_Response* create_event(Date date, char title[TITLE_MAX_LEN], char context[CONTEXT_MAX_LEN]) {
    if (validate_date(date) && validate_event(title, context)) {
        Event_Response *r = (Event_Response*)malloc(sizeof(Event_Response));
        Event *event = (Event*)malloc(sizeof(Event));

        srand(time(NULL));
        event->id = rand();
        event->date = date;

        memcpy(event->title, title, TITLE_MAX_LEN * sizeof(char));
        memcpy(event->context, context, CONTEXT_MAX_LEN * sizeof(char));

        r->json = (char*)malloc(JSON_MAX_SIZE * sizeof(char));
        memcpy(r->json, create_json(event), JSON_MAX_SIZE * sizeof(char));

        r->data = (Event*)malloc(sizeof(Event));
        r->data = event;
        return r;
    }
    else {
        return NULL;
    }
}

Event_Response* update_event(char* json_data) {
    printf("%s\n", json_data);
    char *values[EVENT_KEY_SIZE];
    for (int i = 0; i < EVENT_KEY_SIZE; i++) {
        values[i] = get_json_data(json_data, event_keys[i]);
    }

    //TODO : CHECK BUG
    Event_Response *r = (Event_Response*)malloc(sizeof(Event_Response));

    r->data = (Event*)malloc(sizeof(Event));
    r->json = (char*)malloc(JSON_MAX_SIZE * sizeof(char));
    r->data->id = atoi(values[0]);
    r->data->date.day = atoi(values[1]);
    r->data->date.month = atoi(values[2]);
    r->data->date.year = atoi(values[3]);
    r->data->date.hour = atoi(values[4]);
    r->data->date.minutes = atoi(values[5]);

    memcpy(r->data->title, values[5], strlen(values[5]) * sizeof(char));
    memcpy(r->data->context, values[6], strlen(values[6]) * sizeof(char));

    r->data->is_completed = atoi(values[7]);

    memcpy(r->json, json_data, strlen(r->json) * sizeof(int));

    free(values);
    return r;
}

Event_Response* delete_event(int id) {
    return NULL;
}

static int validate_event(char title[TITLE_MAX_LEN], char context[CONTEXT_MAX_LEN]) {
    int title_len = 0;
    while (title[title_len] != '\0') {
        title_len++;
    }

    if (title[0] == '\0' || title_len > TITLE_MAX_LEN) {
        printf(INVALID, "title", "empty or longer than MAX LENGHT");
        return 0;
    }

    int context_len =  0;
    while (context[context_len] != '\0') {
        context_len++;
    }

    if (context[0] == '\0' || context_len > CONTEXT_MAX_LEN) {
        printf(INVALID, "context", "empty or longer than MAX LENGHT");
        return 0;
    }

    return 1;
}

static int validate_date(Date date) {
    if (date.day == 0 || date.day > DAY_MAX) {
        printf(INVALID, "day", "0 or higher than MAX");
        return 0;
    }

    if (date.month == 0 || date.month > MONTH_MAX) {
        printf(INVALID, "month", "0 or higher than MAX");
        return 0;
    }

    if (date.year == 0) {
        printf(INVALID, "year", "should not be 0");
        return 0;
    }

    if (date.hour == 0 || date.hour > HOUR_MAX) {
        printf(INVALID, "hour", "should not be 0 or higher than MAX");
        return 0;
    }

    if (date.minutes > MINUTES_MAX) {
        printf(INVALID, "minutes", "higher than MAX");
        return 0;
    }
}

char* create_json(Event *e) {
    char *r = (char*)malloc(JSON_MAX_SIZE * sizeof(char));

    sprintf(r, EVENT_JSON,
        e->id, e->date.day, e->date.month,
        e->date.year, e->date.hour, e->date.minutes,
        e->title, e->context, e->is_completed);

    return r;
}
