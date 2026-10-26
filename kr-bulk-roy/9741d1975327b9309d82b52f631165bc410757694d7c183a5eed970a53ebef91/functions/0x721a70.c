
undefined2 FUN_00721a70(void)

{
  undefined2 uVar1;
  int *in_ECX;
  
  if ((*(int *)in_ECX[8] != 0) && (0 < *(int *)in_ECX[0xc])) {
    return **(undefined2 **)in_ECX[8];
  }
  uVar1 = (**(code **)(*in_ECX + 0x18))();
  return uVar1;
}

