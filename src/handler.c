#include "../include/handler.h"

int handle_create_event(event_handler handler, void *arg) {
    handler(arg);
}