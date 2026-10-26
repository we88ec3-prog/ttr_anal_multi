
void FUN_005637e0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) &&
     (piVar1 = *(int **)(in_ECX + 0x10), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x68))(1,0x3f800000);
    *(ushort *)((int)piVar1 + 0xe2) = *(ushort *)((int)piVar1 + 0xe2) & 0x7fff;
  }
  return;
}

