#ifndef HANDLER_H
#define HANDLER_H

typedef void (*event_handler)(void*);

int handle_event(event_handler, void*);
int handle_notify(event_handler, void*);
int handle_calender(event_handler, void*);

#endif