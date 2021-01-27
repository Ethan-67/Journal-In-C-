#include <stdio.h>
#include <stdlib.h>
#include "journal.h"

int main(void)
{
	for (;;) {
		printf("Enter operation, make entry - e, print entry codes - p, quit - q: ");
		switch (getchar()) {
			case 'e': make_entry();
			break;
			case 'p': read_entries(); 
			break;
			case 'q': return 0; 
			break;
		}

	}
}
