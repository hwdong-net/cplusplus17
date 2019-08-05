#if 0

int main() {
#if 0
	int i = 42; void *p = &i; long *lp = &i;
#endif 
#if 1
	int v[] = { 1,2,3,4 };
	v0 = 10.5;
	int i = v[3] + 10;
	v[2] = v[0] - i;	
	i = v[4];

#endif 
}
#endif 

#if 0
int main() {
	int a[5] = {};	
	int b[6] = {};
	int* x = a;
	int* const y = a;
	b = x;
	x = b;
	y = b;
	return 0;
}
#endif 