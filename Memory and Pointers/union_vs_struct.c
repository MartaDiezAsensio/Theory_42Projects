#include <stdio.h>
#include <string.h>

union student_u
{
	int		age;
	char	name[20];
	float	grade;
};

struct student_s
{
	int		age;
	char	name[20];
	float	grade;
};

/*When running this program we see that the values of age and 
grade have got corrupted because the final value assigned to 
the variable has occupied the memory location and this is the 
reason why the vaue of str is getting corretly printed and not
the others*/
void	print_union_1()
{
	union student_u student_1;

	student_1.age = 13;
	student_1.grade = 4.9;
	strcpy(student_1.name, "Marco");
	printf("Memory size occupied: %d\n", sizeof(student_1));
	printf("Name of first student: %s\n.", student_1.name);
	printf("Age of first student: %d\n.", student_1.age);
	printf("Grade of first student: %f\n.", student_1.grade);
}

/*Now we are Asigning and printing one variable at a time and thus
varibles don't get desrtoyed.*/
void	print_union_2()
{
	union student_u	student_1;

	student_1.age = 13;
	printf("Age of first student: %d\n.", student_1.age);
	student_1.grade = 3.5;
	printf("Grade of first student: %.01f\n.", student_1.grade);
	strcpy(student_1.name, "Polo");
	printf("Name of first student: %s\n.", student_1.name);
}

/*Because structs allocate memory for each member of the structure,
the ptint_union_1 example from the bggining now will be printed 
correctly.*/
void	print_struct_1()
{
	struct student_s student_1;

	student_1.age = 13;
	student_1.grade = 4.9;
	strcpy(student_1.name, "Marco");
	printf("Memory size occupied: %d\n", sizeof(student_1));
	printf("Name of first student: %s\n.", student_1.name);
	printf("Age of first student: %d\n.", student_1.age);
	printf("Grade of first student: %.01f\n.", student_1.grade);
}
int	main()
{
	print_struct_1();
}


/*C programming language allos usera to define their custom data 
types. There arefive ways to cate custom data: bit-field, structure, 
union, typedef and enumeration.*/

/*Structure: They can hold multiple members of differet data types 
under s single unit. 
The elements of a structure are stored in contiguous memory locations
and can be retrieved and accessed at any time.
Every data object in a structure i a member or field.*/

/*Union: Similar to the structure, except all its membes live at the
same exact location in memory. The union combines objcts of different 
data types. A user can define a union with many members, but only one
member can hold a value at any time. 
The storage space allocated for the union is equal to the total space
required by the most prominent data member of the union.
A union provides an eficient way of using a single memory location for
various tasks.*/