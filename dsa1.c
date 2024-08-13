#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct calElement {
    int date;
    char* day;
    char* activity;
};

struct calElement* create() {
    struct calElement* calendar;
    calendar = (struct calElement*) malloc(sizeof(struct calElement) * 7);
    return calendar;
}

void read(struct calElement* calendar) {
    char day[10];
    char activity[25];
    int i, date;
    for (i = 0; i < 7; i++) {
        printf("Enter the day: ");
        scanf("%s", day);
        calendar[i].day = (char*)malloc(strlen(day) + 1);
        strcpy(calendar[i].day, day);
        
        printf("Enter the date: ");
        scanf("%d", &date);
        calendar[i].date = date;
        
        printf("Enter the description of the activity: ");
        scanf(" %[^\n]", activity);  // This format string captures the entire line until a newline is encountered.
        calendar[i].activity = (char*)malloc(strlen(activity) + 1);
        strcpy(calendar[i].activity, activity);
    }
}

void display(struct calElement* calendar) {
    int i;
    printf("\nYour Calendar:\n");
    printf("Day\t\tDate\t\tActivity\n\n");
    for (i = 0; i < 7; i++) {
        printf("%s\t\t%d\t\t%s\n", calendar[i].day, calendar[i].date, calendar[i].activity);
    }
}

int main() {
    struct calElement* calendar;
    calendar = create();
    read(calendar);
    display(calendar);
    free(calendar);
    
    return 0;
}
