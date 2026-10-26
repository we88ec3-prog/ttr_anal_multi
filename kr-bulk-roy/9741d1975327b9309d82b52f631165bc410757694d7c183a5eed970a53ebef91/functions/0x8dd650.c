
undefined4 FUN_008dd650(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x19c);
  uVar2 = 0xa1;
  if (param_1 + 0x20U <= *(uint *)(param_1 + 0x194)) {
    uVar2 = FUN_008dd4e0();
    uVar2 = FUN_008b7c80(uVar2);
    *(undefined4 *)(iVar1 + 0x54) = uVar2;
    uVar2 = FUN_008dd4e0();
    uVar2 = FUN_008b7c80(uVar2);
    *(undefined4 *)(iVar1 + 0x58) = uVar2;
    uVar2 = FUN_008dd4e0();
    uVar2 = FUN_008b7c80(uVar2);
    *(undefined4 *)(iVar1 + 0x5c) = uVar2;
    uVar2 = FUN_008dd4e0();
    uVar2 = FUN_008b7c80(uVar2);
    *(undefined4 *)(iVar1 + 0x60) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}

