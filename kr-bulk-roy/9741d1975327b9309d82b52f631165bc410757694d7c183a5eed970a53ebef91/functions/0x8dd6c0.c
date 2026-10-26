
undefined4 FUN_008dd6c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x19c);
  uVar2 = 0xa1;
  if (param_1 + 0x18U <= *(uint *)(param_1 + 0x194)) {
    uVar2 = FUN_008dd460();
    *(undefined4 *)(iVar1 + 0x78) = uVar2;
    uVar2 = FUN_008dd460();
    *(undefined4 *)(iVar1 + 0x74) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}

