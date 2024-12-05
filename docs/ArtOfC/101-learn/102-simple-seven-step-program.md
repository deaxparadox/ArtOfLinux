# C program in seven simple steps

### Table of contents

1. Define the program objectives.
2. Design the program
3. Write the code
4. Compile
5. Run the program
6. Test and debug the program
7. Maintain and modify the program


### Step 1: Define the Program Objectives

You should start with a clear idea of what you want to program to do.

### Design the Program

After the deciding the program objective, you should code how the program will go about it. What should the user interface be like (GUI or terminal).

### Write the code

Now that you have a clear design for your program, you can begin to implement it by writing the code. That is, you translate your program design into the C language.

You use your test editor to create what is called *source code* file. The file contains the C rendition of your program design.

Open your code editor and create a source code file *simple_code.c*, and write the following code:

```c
#include <stdio.h>

int main() {
    int dogs;
    
    printf("How many dogs do you have?\n");
    scanf("%d", &dogs);
    printf("So you have %d dogs!\n", dogs);

    return 0;
}
```