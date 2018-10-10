#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
using namespace std;
int main(){
char buffer[100];
 int fd = open("test.txt", O_WRONLY | O_APPEND);
 if (fd < 0) {
    std::cerr << "open err path " << "test.txt"
              << " errno " << errno << std::endl;
    return -1;
  }
    lseek(fd, 0, SEEK_SET);
   // write(fd, "abc", 3);
    if (read(fd, buffer, 3) !=3)
    cout << "Possible read error." << endl;
    else
	cout << buffer <<endl;

	lseek(fd, 10, SEEK_CUR);
   // write(fd, "abc", 3);
    if (read(fd, buffer, 3) !=3)
    cout << "Possible read error." << endl;
	else
	cout << buffer <<endl;

	lseek(fd, 0, SEEK_END);
   // write(fd, "abc", 3);
    if (read(fd, buffer, 5) !=5)
    cout << "Possible read error." << endl;
	else
	cout << buffer <<endl;
    close(fd);
}