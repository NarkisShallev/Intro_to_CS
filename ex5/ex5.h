#define MAX_STUDENTS 50
#define MAX_NAME 21
#define MAX_COURSES 5
#define MAX_INPUT 201
int InsertUpdateStudent(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES]);
void DeleteStudent(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES]);
void FindStudentMaxGrade(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES]);
void FindAllMaxGrade(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES]);