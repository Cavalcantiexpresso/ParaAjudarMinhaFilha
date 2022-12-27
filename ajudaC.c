#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void triagePatient(char *name, int age, char *infectiousDiseaseSuspected) {
  // Convert the infectious disease suspected input to uppercase
  for (int i = 0; i < strlen(infectiousDiseaseSuspected); i++) {
    infectiousDiseaseSuspected[i] = toupper(infectiousDiseaseSuspected[i]);
  }

  // Determine which room the patient should be sent to
  char *room;
  if (strcmp(infectiousDiseaseSuspected, "YES") == 0) {
    room = "YELLOW";
  } else if (strcmp(infectiousDiseaseSuspected, "NO") == 0) {
    room = "WHITE";
  } else {
    printf("Please respond to the infectious disease suspected question with YES or NO\n");
    return;
  }
  printf("Send the patient to the %s room\n", room);

  // Determine if the patient has priority
  bool priority = false;
  if (age >= 65) {
    priority = true;
  } else {
    printf("Enter the patient's gender: ");
    char gender[10];
    scanf("%s", gender);
    for (int i = 0; i < strlen(gender); i++) {
      gender[i] = toupper(gender[i]);
    }
    if (strcmp(gender, "FEMALE") == 0 && age > 10) {
      printf("Is the patient pregnant? ");
      char pregnancy[10];
      scanf("%s", pregnancy);
      for (int i = 0; i < strlen(pregnancy); i++) {
        pregnancy[i] = toupper(pregnancy[i]);
      }
      if (strcmp(pregnancy, "YES") == 0) {
        priority = true;
      }
    }
  }
  printf("Patient %s priority\n", priority ? "has" : "does NOT have");
}

int main(void) {
  // Example usage
  triagePatient("John", 30, "yes");
  return 0;
}

