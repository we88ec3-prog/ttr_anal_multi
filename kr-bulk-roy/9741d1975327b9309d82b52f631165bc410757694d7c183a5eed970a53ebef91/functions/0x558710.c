
undefined4 FUN_00558710(int param_1,int *param_2,int *param_3,int *param_4)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int local_c;
  code *local_8;
  
  iVar3 = (int)((int)*(char *)(param_1 + 0x10) + ((int)*(char *)(param_1 + 0x10) >> 0x1f & 7U)) >> 3
  ;
  pbVar7 = (byte *)(param_1 + 0x12);
  if ((*(char *)(param_1 + 2) != '\x02') && (*(char *)(param_1 + 2) != '\n')) {
    return 0;
  }
  if (iVar3 == 2) {
    local_8 = FUN_005586c0;
  }
  else if (iVar3 == 3) {
    local_8 = FUN_00558690;
  }
  else {
    if (iVar3 != 4) {
      return 0;
    }
    local_8 = FUN_00558660;
  }
  lVar2 = (ulonglong)(uint)((int)*(short *)(param_1 + 0xc) * (int)*(short *)(param_1 + 0xe)) * 4;
  iVar4 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *param_2 = iVar4;
  local_c = 0;
  if (*(char *)(param_1 + 2) == '\x02') {
    if (0 < (int)*(short *)(param_1 + 0xc) * (int)*(short *)(param_1 + 0xe)) {
      do {
        (*local_8)(iVar4,pbVar7);
        pbVar7 = pbVar7 + iVar3;
        local_c = local_c + 1;
        iVar4 = iVar4 + 4;
      } while (local_c < (int)*(short *)(param_1 + 0xc) * (int)*(short *)(param_1 + 0xe));
    }
  }
  else if ((*(char *)(param_1 + 2) == '\n') &&
          (0 < (int)*(short *)(param_1 + 0xc) * (int)*(short *)(param_1 + 0xe))) {
    do {
      pbVar8 = pbVar7 + iVar3 + 1;
      bVar1 = *pbVar7;
      uVar5 = bVar1 & 0x7f;
      (*local_8)(iVar4,pbVar7 + 1);
      iVar4 = iVar4 + 4;
      if ((*pbVar7 & 0x80) == 0) {
        uVar6 = uVar5;
        if ((bVar1 & 0x7f) != 0) {
          do {
            (*local_8)(iVar4,pbVar8);
            pbVar8 = pbVar8 + iVar3;
            iVar4 = iVar4 + 4;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      else {
        uVar6 = uVar5;
        if ((bVar1 & 0x7f) != 0) {
          do {
            (*local_8)(iVar4,pbVar7 + 1);
            iVar4 = iVar4 + 4;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      local_c = local_c + 1 + uVar5;
      pbVar7 = pbVar8;
    } while (local_c < (int)*(short *)(param_1 + 0xc) * (int)*(short *)(param_1 + 0xe));
  }
  *param_3 = (int)*(short *)(param_1 + 0xc);
  *param_4 = (int)*(short *)(param_1 + 0xe);
  return 1;
}

