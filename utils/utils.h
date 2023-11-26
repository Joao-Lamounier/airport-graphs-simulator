#ifndef AIRPORT_GRAPHS_SIMULATOR_UTILS_H
#define AIRPORT_GRAPHS_SIMULATOR_UTILS_H

void color(int color);

void timeZoneToUTC(const char *input, char *output, int timeZone);

int timeDifference(const char *h1, const char *h2);

void convertMinutesToHours(char *output, int minutes);

#endif //AIRPORT_GRAPHS_SIMULATOR_UTILS_H
