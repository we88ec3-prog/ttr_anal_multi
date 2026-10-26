
void FUN_005f6700(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_1c [4];
  int iStack_18;
  int iStack_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)local_1c;
  if ((*(int *)(param_1 + 0xcc) != 0) && (*(int *)(param_1 + 0xd0) != 0)) {
    (**(code **)(**(int **)(param_1 + 0xcc) + 0x174))(local_1c);
    piVar1 = *(int **)(param_1 + 0xd0);
    uVar4 = ((*(int *)(param_1 + 0xa8) - *(int *)(param_1 + 0xb0)) - iStack_18) + iStack_10;
    uVar4 = ((int)uVar4 < 1) - 1 & uVar4;
    if ((uVar4 != piVar1[0x2e]) && (piVar1[0x2e] = uVar4, (int)uVar4 < piVar1[0x31])) {
      pcVar2 = *(code **)(*piVar1 + 0x128);
      piVar1[0x31] = uVar4;
      (*pcVar2)();
      (**(code **)(*piVar1 + 200))();
    }
    piVar1 = *(int **)(param_1 + 0xd0);
    if ((int)uVar4 < piVar1[0x31]) {
      pcVar2 = *(code **)(*piVar1 + 0x128);
      piVar1[0x31] = uVar4;
      (*pcVar2)();
      (**(code **)(*piVar1 + 200))();
    }
    *(undefined4 *)(*(int *)(param_1 + 0xcc) + 0xcc) =
         *(undefined4 *)(*(int *)(param_1 + 0xd0) + 0xc4);
    iVar3 = *(int *)(*(int *)(param_1 + 0xcc) + 0x44);
    if (iVar3 != 0) {
      iVar3 = *(int *)(iVar3 + 0xd8);
      if (iVar3 == 0) {
        FUN_00471310();
      }
      else if (iVar3 == 1) {
        FUN_004713f0();
      }
    }
    FUN_00745b80();
  }
  __security_check_cookie(local_c ^ (uint)local_1c);
  return;
}

