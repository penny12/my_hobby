#include <iostream>
#include <dirent.h>
#include <errno.h>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

// template<typename A, typename B> void test(A a, B b)
// {
//   cout << "a: " << a << "  b:" << b << endl;
// }

int main()
{
  DIR *dir;
  struct dirent *ent;
  if((dir = opendir("./")) != NULL)
  {
    while((ent = readdir(dir)) != NULL) {
      if(!(!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")))
        cout << ent->d_name << " " << flush;
    }
    cout << endl;
    closedir(dir);
  }
  else
  {
    perror("");
    exit(1);
  }
}
