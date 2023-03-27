int main(){
	int i = 5; //101   1010
	int j = 4; //100

	printf("i = %d\n", i);
	printf("j = %d\n\n", j);

	printf("ET:%d\n", (i & j));
	printf("OU:%d\n", (i | j));
	printf("XOR:%d\n", (i ^ j));
	
	printf(">>: %d\n", i>>1);
	printf("<<: %d\n", i<<5);
	return (0);
}
