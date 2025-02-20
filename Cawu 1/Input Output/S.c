#include <stdio.h>
int main(){
    char kata[105];
    scanf("%[^\n]", kata);
    printf("#include <stdio.h>\nint main()\n{\n    printf(\"%%s\\n\",\"%s\");\n    return 0;\n}\n", kata);
    return 0;
}