#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
using namespace std;
int main(){
  char buffer1[100]={0};
    char buffer2[100]={0};
/*FILE *fp, *fp2;
if ((fp = fopen("test.txt", "w"))==NULL) {
printf("Cannot open file.\n");
exit(1);
}
fp2 = dup(fp);*/

int fp2;
 int fd = open("test.txt", O_RDONLY);
 if (fd < 0) {
    std::cerr << "open err path " << "test.txt"
              << " errno " << errno << std::endl;
    return -1;
  }
  lseek(fd, 2, SEEK_SET);
fp2 = dup(fd);
//lseek(fp2, 1, SEEK_SET);
//write(fd, "abc", 3);
  if (read(fd, buffer1, 2) !=2)
    cout << "Possible read error." << endl;
  else
  cout << buffer1 <<endl;

 if (read(fp2, buffer2, 2) !=2)
    cout << "Possible read error." << endl;
  else
  cout << buffer2 <<endl;
if ( strcmp(buffer1,buffer2)==0)
  cout << "duplicate and source file descriptor share a common pointer to the current position in the file" << endl;
}