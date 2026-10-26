
void FUN_00854860(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_FS_OFFSET;
  int local_3c;
  int local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090e0b8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_14;
  iVar4 = (param_3 - param_1) / 0x18;
  iVar1 = (param_2 - param_1) / 0x18;
  iVar2 = iVar1;
  local_3c = iVar4;
  while (iVar3 = iVar2, iVar3 != 0) {
    iVar2 = local_3c % iVar3;
    local_3c = iVar3;
  }
  if ((local_3c < iVar4) && (0 < local_3c)) {
    iVar4 = param_1 + local_3c * 0x18;
    do {
      iVar2 = iVar4 + iVar1 * 0x18;
      iVar3 = param_1;
      iVar5 = iVar4;
      if (iVar2 != param_3) {
        iVar3 = iVar2;
      }
      do {
        iVar2 = iVar3;
        FUN_0062d9b0(iVar5);
        local_20 = *(undefined4 *)(iVar5 + 0x10);
        local_1c = *(undefined4 *)(iVar5 + 0x14);
        local_c = 0;
        FUN_004738a0(iVar2);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
        FUN_004738a0(local_30);
        *(undefined4 *)(iVar2 + 0x10) = local_20;
        local_c = 0xffffffff;
        *(undefined4 *)(iVar2 + 0x14) = local_1c;
        if (local_30[0] != 0) {
          FUN_0089120c(local_30[0]);
        }
        iVar3 = (param_3 - iVar2) / 0x18;
        if (iVar1 < iVar3) {
          iVar3 = iVar2 + iVar1 * 0x18;
        }
        else {
          iVar3 = param_1 + (iVar1 - iVar3) * 0x18;
        }
        iVar5 = iVar2;
      } while (iVar3 != iVar4);
      iVar4 = iVar4 + -0x18;
      local_3c = local_3c + -1;
    } while (0 < local_3c);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}

