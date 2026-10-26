
undefined4 FUN_005c7150(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_005c7190();
  if (iVar1 != 0) {
    FUN_0082ef00(&param_1);
    if (in_ECX != *(int *)(iVar1 + 0xc)) {
      return *(undefined4 *)(in_ECX + 0x10);
    }
  }
  return 0;
}

