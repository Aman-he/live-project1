#include <stdio.h>
#include <time.h>

void time_now()
{
	time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);
    printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon +1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
 } 

void name()
{
	
}

int main ()
{
    time_now();
    printf("用户已进入校园\n");
	printf("----------------------------------\n");
	printf("用户已退出校园\n");
	time_now();
}
//
