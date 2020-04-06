#include <stdio.h>
int main(int argc, char const *argv[]) {
  int total_l = 0;
  int width = 23;
  for(int i = 0; i < argc; i++){
    int current = printf("%s", argv[i]);
    printf("%*i\n",width - current,current);
    total_l += current;
  }
  printf("%s", "Total length " );
  printf("%*i\n", width - 13, total_l);

  double average_l = total_l / argc;
  printf("%s", "Average length " );
  printf("%*s",width - 19, "");
  printf("%0.2f\n",average_l);
  return total_l;
}
