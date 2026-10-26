
int FUN_008d4660(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 100);
  local_8 = FUN_008d3f00();
  if ((local_8 != 0) || (local_8 = FUN_008babe0(), local_8 != 0)) {
    return local_8;
  }
  uVar8 = FUN_008b9a00();
  uVar9 = uVar8 >> 2 & 1;
  if (uVar9 == 0) {
    sVar3 = FUN_008b9990();
    sVar4 = FUN_008b9990();
    sVar5 = FUN_008b9990();
    sVar6 = FUN_008b9990();
    uVar7 = FUN_008b9990();
    *(undefined2 *)(param_1 + 0x130) = uVar7;
  }
  else {
    sVar3 = FUN_008b9960();
    sVar4 = FUN_008b9960();
    sVar5 = FUN_008b9960();
    sVar6 = FUN_008b9960();
    uVar7 = FUN_008b9960();
    *(undefined2 *)(param_1 + 0x130) = uVar7;
  }
  local_c = (int)sVar4;
  local_10 = (int)sVar5;
  local_14 = (int)sVar6;
  local_18 = (int)sVar3;
  FUN_008baca0();
  if ((uVar8 & 0xffffff00) == 0) {
    local_20 = (local_14 - local_10) + 1;
    iVar11 = ((local_c - local_18) + 1) * local_20;
    iVar10 = FUN_008bc7d0(uVar1,8,0,iVar11,0,&local_8);
    if (local_8 != 0) {
      return 0x40;
    }
    local_8 = FUN_008babe0();
    if (local_8 == 0) {
      iVar12 = 0;
      if (local_10 <= local_14) {
        local_10 = local_10 << 8;
        iVar2 = local_18;
        do {
          for (; iVar2 <= local_c; iVar2 = iVar2 + 1) {
            if (uVar9 == 1) {
              sVar3 = FUN_008b9960();
            }
            else {
              sVar3 = FUN_008b9990();
            }
            if (sVar3 != -1) {
              *(short *)(iVar10 + 4 + iVar12 * 8) = sVar3;
              *(int *)(iVar10 + iVar12 * 8) = local_10 + iVar2;
              iVar12 = iVar12 + 1;
            }
          }
          local_10 = local_10 + 0x100;
          local_20 = local_20 + -1;
          iVar2 = local_18;
        } while (local_20 != 0);
      }
      FUN_008baca0();
      iVar10 = FUN_008bc7d0(uVar1,8,iVar11,iVar12,iVar10,&local_8);
      if (local_8 == 0) {
        *(int *)(param_1 + 0x128) = iVar12;
        *(int *)(param_1 + 300) = iVar10;
        return 0;
      }
    }
    FUN_008b9f80(uVar1,iVar10);
    return local_8;
  }
  return 3;
}

