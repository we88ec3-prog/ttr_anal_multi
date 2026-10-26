
void FUN_0083b3f0(void)

{
  int iVar1;
  int *in_ECX;
  undefined1 local_c [4];
  undefined4 local_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x60))();
  if (0 < iVar1) {
    do {
      local_8 = 0;
      FUN_0083eb60(local_c,&local_8);
      FUN_0083fe70(local_8);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

