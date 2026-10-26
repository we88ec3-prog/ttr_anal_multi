
undefined2 FUN_00432500(void)

{
  undefined2 *puVar1;
  short sVar2;
  int *in_ECX;
  
  sVar2 = (**(code **)(*in_ECX + 0x18))();
  if (sVar2 == -1) {
    return 0xffff;
  }
  *(int *)in_ECX[0xc] = *(int *)in_ECX[0xc] + -1;
  puVar1 = *(undefined2 **)in_ECX[8];
  *(undefined2 **)in_ECX[8] = puVar1 + 1;
  return *puVar1;
}

