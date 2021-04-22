//program to solve Tower of Hanoi series with recursion

void TowerOfHanoi(int n,char beg,char aux,char end)
{
    if(n>=1)
    {
        TowerOfHanoi(n-1,beg,end,aux);
        printf("move %c to %c \n",beg,end);
        TowerOfHanoi(n-1,aux,beg,end);
    }

}


void main()
{
    //number of disk in hanoi tower
    int number_of_disk = 0;
    //three tower
    char first_tower = 'A';
    char second_tower = 'B';
    char third_tower = 'C';
    system("cls");

    printf("Enter number of Disk ");
    scanf("%d",&number_of_disk);
    TowerOfHanoi(number_of_disk,first_tower,second_tower,third_tower);

    system("pause");
}
