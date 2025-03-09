#include "../include/date.h"

#define VALID_TITLE "test"
#define VALID_CONTEXT "test context"

#define TITLE_LONGER_THAN_MAX "Test TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest Title"
#define CONTEXT_LONGER_THAN_MAX "Test TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest TitleTest Title"

#define TEST_RESULT "\e[0;32m[TEST RESULT]\033[0m method name : %s | expect : %s | result : %d\n"

void title_longer_than_max(void) {
    Date date = { 13, 11, 2025, 11, 11 };
    Event_Response *event = create_event(date, TITLE_LONGER_THAN_MAX, VALID_CONTEXT);
    printf(TEST_RESULT, "title_longer_than_max()", "NULL", event == NULL);
}

void context_longer_than_max(void) {
    Date date = { 13, 11, 2025, 11, 11 };
    Event_Response *event = create_event(date, VALID_TITLE, CONTEXT_LONGER_THAN_MAX);
    printf(TEST_RESULT, "context_longer_than_max()", "NULL", event == NULL);
}

void invalid_day(void) {
    Date date = { 56, 11, 2025, 11, 11 };
    Event_Response *event = create_event(date, VALID_TITLE, VALID_CONTEXT);
    printf(TEST_RESULT, "invalid_day()", "NULL", event == NULL);
}

void invalid_month(void) {
    Date date = { 1, 13, 2025, 11, 11 };
    Event_Response *event = create_event(date, VALID_TITLE, VALID_CONTEXT);
    printf(TEST_RESULT, "invalid_month()", "NULL", event == NULL);
}

void invalid_year(void) {
    Date date = { 1, 12, 0, 11, 11 };
    Event_Response *event = create_event(date, VALID_TITLE, VALID_CONTEXT);
    printf(TEST_RESULT, "invalid_year()", "NULL", event == NULL);
}

void invalid_hour(void) {
    Date date = { 1, 12, 2024, 25, 11 };
    Event_Response *event = create_event(date, VALID_TITLE, VALID_CONTEXT);
    printf(TEST_RESULT, "invalid_hour()", "NULL", event == NULL);
}

void invalid_minutes(void) {
    Date date = { 1, 12, 2024, 11, 60 };
    Event_Response *event = create_event(date, VALID_TITLE, VALID_CONTEXT);
    printf(TEST_RESULT, "invalid_minutes()", "NULL", event == NULL);
}

void valid_event(void) {
    Date date = { 1, 12, 2024, 11, 12 };
    Event_Response *event = create_event(date, VALID_TITLE, VALID_CONTEXT);
    printf(TEST_RESULT, "valid_event()", "Not null", event == NULL);
}

void update_event_success() {
    Date date = { 1, 12, 2024, 11, 12 };
    Event_Response *event = (Event_Response*)malloc(sizeof(Event_Response));
    event = create_event(date, VALID_TITLE, VALID_CONTEXT);
    printf("%s\n", event->json);

    memcpy(event->data->title, "Test Update", TITLE_MAX_LEN * sizeof(char));
    event = update_event(create_json(event->data));
    printf("%s | %s\n", event->data->title, event->json);
}

int main(void) {
    // title_longer_than_max();
    // context_longer_than_max();
    // invalid_day();
    // invalid_month();
    // invalid_year();
    // invalid_hour();
    // invalid_minutes();
    // valid_event();
    // update_event_success();
    return 1;
}