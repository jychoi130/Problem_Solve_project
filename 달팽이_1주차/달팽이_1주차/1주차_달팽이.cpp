#include<cstdio>
#include<cmath>

int main() {
	int day, night, height;
	scanf("%d %d %d", &day, &night, &height);
	if ((height - day) % (day - night) == 0)
		printf("%d\n", (height - day) / (day - night) + 1);
	else 
	printf("%d\n", ((height - day) / (day - night) )+ 2);

	return 0;
}
