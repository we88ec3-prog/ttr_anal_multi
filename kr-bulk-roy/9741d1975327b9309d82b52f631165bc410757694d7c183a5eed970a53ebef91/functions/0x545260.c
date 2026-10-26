
int FUN_00545260(short param_1)

{
  int iVar1;
  int *in_EDX;
  
  iVar1 = 0;
  while( true ) {
    in_EDX = in_EDX + 3;
    if ((*in_EDX != 0) && (*(short *)(*in_EDX + 4) == param_1)) break;
    iVar1 = iVar1 + 1;
    if (2 < iVar1) {
      return -1;
    }
  }
  return iVar1;
}

