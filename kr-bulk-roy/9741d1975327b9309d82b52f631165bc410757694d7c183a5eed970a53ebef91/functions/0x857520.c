
int * FUN_00857520(int param_1)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int *in_ECX;
  int *piVar4;
  int unaff_EDI;
  
  iVar2 = param_1;
  FUN_00835c70(&param_1);
  do {
    do {
      while( true ) {
        do {
          piVar4 = in_ECX;
          if (piVar4 == *(int **)(in_EAX + 4)) {
            return (int *)0x0;
          }
          if ((piVar4[3] == iVar2) && (piVar4[5] == unaff_EDI)) {
            return piVar4 + 4;
          }
          in_ECX = piVar4;
        } while (*(char *)((int)piVar4 + 0x21) != '\0');
        in_ECX = (int *)piVar4[2];
        if (*(char *)((int)in_ECX + 0x21) != '\0') break;
        cVar1 = *(char *)(*in_ECX + 0x21);
        piVar4 = (int *)*in_ECX;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x21);
          in_ECX = piVar4;
          piVar4 = (int *)*piVar4;
        }
      }
      in_ECX = (int *)piVar4[1];
    } while (*(char *)((int)in_ECX + 0x21) != '\0');
    do {
      piVar3 = in_ECX;
      in_ECX = piVar3;
      if (piVar4 != (int *)piVar3[2]) break;
      in_ECX = (int *)piVar3[1];
      piVar4 = piVar3;
    } while (*(char *)((int)in_ECX + 0x21) == '\0');
  } while( true );
}

