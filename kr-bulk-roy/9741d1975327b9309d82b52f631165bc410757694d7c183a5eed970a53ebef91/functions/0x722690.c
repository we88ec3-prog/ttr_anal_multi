
undefined2 FUN_00722690(void)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int *in_ECX;
  
  if ((*(int *)in_ECX[8] != 0) && (piVar1 = (int *)in_ECX[0xc], 0 < *piVar1)) {
    *piVar1 = *piVar1 + -1;
    puVar2 = *(undefined2 **)in_ECX[8];
    *(undefined2 **)in_ECX[8] = puVar2 + 1;
    return *puVar2;
  }
  uVar3 = (**(code **)(*in_ECX + 0x1c))();
  return uVar3;
}

