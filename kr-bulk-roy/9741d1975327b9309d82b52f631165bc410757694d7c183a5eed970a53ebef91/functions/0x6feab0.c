
undefined4 * FUN_006feab0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int *in_EDX;
  
  iVar1 = in_EDX[2];
  if (iVar1 == 5) {
    iVar1 = *(int *)(*in_EDX + 8);
  }
  else if (iVar1 == 7) {
    iVar1 = *(int *)(*in_EDX + 8);
  }
  else {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x10) + 0x98 + iVar1 * 4);
  }
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_006f9c10();
    return puVar2;
  }
  return &DAT_00c0bfc8;
}

