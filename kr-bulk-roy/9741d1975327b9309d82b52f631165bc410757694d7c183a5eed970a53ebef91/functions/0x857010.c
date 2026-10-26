
undefined4 FUN_00857010(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  int unaff_EDI;
  
  iVar3 = param_1;
  FUN_00835c70(&param_1);
  while( true ) {
    if (in_ECX == *(int **)(unaff_EDI + 4)) {
      return 0;
    }
    if (((in_ECX[3] == iVar3) && (in_ECX[5] == 0)) && (in_ECX[7] != 0)) break;
    if (*(char *)((int)in_ECX + 0x21) == '\0') {
      piVar2 = (int *)in_ECX[2];
      if (*(char *)((int)piVar2 + 0x21) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x21);
        in_ECX = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          in_ECX = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(in_ECX[1] + 0x21);
        piVar4 = (int *)in_ECX[1];
        piVar2 = in_ECX;
        while ((in_ECX = piVar4, cVar1 == '\0' && (piVar2 == (int *)in_ECX[2]))) {
          cVar1 = *(char *)(in_ECX[1] + 0x21);
          piVar4 = (int *)in_ECX[1];
          piVar2 = in_ECX;
        }
      }
    }
  }
  if (in_ECX[7] != 0) {
    FUN_00891d3d(in_ECX[7]);
    in_ECX[7] = 0;
  }
  FUN_006d71c0(unaff_EDI,&param_1,in_ECX);
  return 1;
}

