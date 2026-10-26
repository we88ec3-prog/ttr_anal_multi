
undefined4 FUN_008dd700(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x19c);
  uVar2 = 0xa1;
  if (param_1 + 0x1cU <= *(uint *)(param_1 + 0x194)) {
    uVar2 = FUN_008dd460();
    *(undefined4 *)(iVar1 + 0x84) = uVar2;
    uVar2 = FUN_008dd460();
    *(undefined4 *)(iVar1 + 0x88) = uVar2;
    uVar2 = FUN_008dd460();
    *(undefined4 *)(iVar1 + 0x8c) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}

