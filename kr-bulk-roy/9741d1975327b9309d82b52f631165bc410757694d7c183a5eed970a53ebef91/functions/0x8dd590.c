
undefined4 FUN_008dd590(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x19c);
  uVar2 = 0xa1;
  if (param_1 + 0x28U <= *(uint *)(param_1 + 0x194)) {
    *(undefined1 *)(iVar1 + 0x40) = 1;
    uVar2 = FUN_008dd500();
    *(undefined4 *)(iVar1 + 0x30) = uVar2;
    if ((uint)-param_1 < 9 || param_1 == -9) {
      uVar2 = thunk_FUN_008dd490();
      *(undefined4 *)(iVar1 + 0x38) = uVar2;
      uVar2 = thunk_FUN_008dd490();
      *(undefined4 *)(iVar1 + 0x34) = uVar2;
      uVar2 = thunk_FUN_008dd490();
      *(undefined4 *)(iVar1 + 0x3c) = uVar2;
      uVar2 = thunk_FUN_008dd490();
      *(undefined4 *)(iVar1 + 0x48) = uVar2;
      uVar2 = thunk_FUN_008dd490();
      *(undefined4 *)(iVar1 + 0x4c) = uVar2;
      *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(&DAT_00be9358 + param_1 * -4);
      return 0;
    }
    uVar2 = 0;
    *(undefined4 *)(iVar1 + 0x30) = 0x10000;
    *(undefined4 *)(iVar1 + 0x38) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
    *(undefined4 *)(iVar1 + 0x3c) = 0x10000;
    *(undefined4 *)(iVar1 + 0x48) = 0;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined4 *)(iVar1 + 0x44) = 1;
  }
  return uVar2;
}

