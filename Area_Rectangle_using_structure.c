#include <stdio.h>


//point
struct point
{
    int x,y;
};

//Rectangle coordinate
struct Rectangle
{
    struct point upper_left;
    struct point lower_right;
};

//length and width of rectangle
int area(struct Rectangle r)
{
    int lenght,breadth;
    lenght = r.lower_right.x - r.upper_left.x;
    breadth = r.upper_left.y - r.lower_right.y;
    return lenght * breadth;
}


main()
{
    struct Rectangle rect;

    printf("Enter the coordinate of upper left of rectangle ");
    scanf("%d%d",&rect.upper_left.x,&rect.upper_left.y );

    printf("Enter the coordinate of lower right of rectangle ");
    scanf("%d%d",&rect.lower_right.x,&rect.lower_right.y);

    printf("Area of Rectangle is %d\n",area(rect));
}
