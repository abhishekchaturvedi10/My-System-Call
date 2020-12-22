/* Name: Your Abhishek Chaturvedi
   Roll_Number: 2019401 */

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define sh_task_info 548

int main()
{  
	printf("\n-------Invoking Test For 'sh_task_info' System Call-------\n\n");

	int pid; char filename[100];

	printf("Enter the PID: ");
	scanf("%d", &pid);

	printf("Enter the filename: ");
	scanf("%s", filename);

	long int status = syscall(sh_task_info, pid, filename); 
	
	if(status == 0) printf("\nCorrect input. System call 'sys_task_info' returned %d\n", 0);
	else printf("\nIncorrect input. System call 'sys_task_info' returned %d\n", 1);
	
	if(status == 0) 
		printf("System Call 'sh_task_info' executed correctly. Use 'dmesg' command to check processInfo and 'dmesg|tail' to check kernel output.\n\n");
	
	else {

		printf("System call 'sh_task_info' did not execute correctly.\n");
		perror("Error ");
		printf("Error No.: %d\n\n", errno);
	}
	
	return 0;
}
