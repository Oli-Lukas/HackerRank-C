/**
 * Link: https://www.hackerrank.com/challenges/conditional-statements-in-c/problem
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char *number_name(int number);

int main()
{
  char *n_endptr;
  char *n_str = readline();
  int n = strtol(n_str, &n_endptr, 10);

  if (n_endptr == n_str || *n_endptr != '\0')
    exit(EXIT_FAILURE);
  
  char *result = number_name(n);
  printf("%s\n", result);
  
  return EXIT_SUCCESS;
}

char *readline()
{
  size_t alloc_length = 1024;
  size_t data_length  = 0;
  char *data = malloc(alloc_length);

  while(true)
  {
    char *cursor = data + data_length;
    char *line   = fgets(cursor, alloc_length - data_length, stdin);
    if (!line) break;

    data_length += strlen(cursor);
    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

    size_t new_length = alloc_length << 1;
    data = realloc(data, new_length);

    if (!data) break;

    alloc_length = new_length;
  }

  if (data[data_length - 1] == '\n')
    data[data_length - 1] = '\0';
  
  data = realloc(data, data_length);

  return data;
}

char *number_name(int number)
{
  switch(number)
  {
    case 1:
      return "one";
    case 2:
      return "two";
    case 3:
      return "three";
    case 4:
      return "four";
    case 5:
      return "five";
    case 6:
      return "six";
    case 7:
      return "seven";
    case 8:
      return "eight";
    case 9:
      return "nine";
    default:
      return "Greater than 9";
  }
}
