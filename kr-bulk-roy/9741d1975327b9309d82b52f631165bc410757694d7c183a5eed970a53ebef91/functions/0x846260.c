
undefined4 FUN_00846260(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int in_ECX;
  
  iVar2 = param_1;
  param_1 = 0xa2500000;
  FUN_0082ef00(&param_1);
  if (((in_ECX != *(int *)(in_EAX + 0x38)) && (*(int *)(in_ECX + 0x10) != 0)) &&
     (iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + 0x30), iVar2 < iVar1)) {
    if ((*(int *)(in_EAX + 0xa0) - *(int *)(in_EAX + 0x9c) & 0xfffffffcU) == 0) {
      FUN_0077f820(iVar1);
      param_1 = 0;
      FUN_00848190(iVar1);
    }
    *(undefined4 *)(*(int *)(in_EAX + 0x9c) + iVar2 * 4) = param_2;
    return 1;
  }
  return 0;
}

