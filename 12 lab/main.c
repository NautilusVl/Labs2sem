#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main() {
    struct Time start_time = {RandHourStart(), RandMinStart()};
    struct Time end_time = {RandHourEnd(), RandMinEnd()};
    int total_hours = 0;
    int total_minutes = 0;

    for (int i = 0; i < 7; i++) {
        total_hours += end_time.hours - start_time.hours;
        total_minutes += end_time.minutes - start_time.minutes;
    }

    total_hours += total_minutes / 60;
    total_minutes %= 60;

    printf("time of working for week: %d hours %d minutes\n", total_hours, total_minutes);

    return 0;
}
