
undefined4 FUN_00500a80(int param_1,undefined4 param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 **ppuVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  ushort *local_50;
  uint local_4c;
  undefined4 *puStack_40;
  undefined4 *puStack_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  puStack_10 = &LAB_009401ce;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  iVar12 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_c = 0;
  uStack_b = 0;
  FUN_00500950(param_1,param_2,&local_38);
  do {
    iVar5 = FUN_00500160(param_1,param_2);
    if (iVar5 != 0) {
      if (local_38 != 0) {
        FUN_0089120c(local_38,uVar4);
      }
      ExceptionList = local_14;
      return 3;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 < 0x14);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0;
  }
  bVar3 = false;
  if ((((DAT_00f9392c == 3) || (DAT_00f9392c == 1)) || (DAT_00f9392c == 7)) ||
     ((DAT_00f9392c == 0x17 || (DAT_00f9392c == 0x18)))) {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_c = 2;
    FUN_00500a00(param_1,param_2,&local_28);
    bVar13 = local_28 != local_24;
    if (local_28 != 0) {
      FUN_0089120c(local_28);
    }
    if (bVar13) {
      bVar3 = true;
    }
  }
  uVar4 = local_34 - local_38 >> 2;
  if (uVar4 == 0) {
    if (!bVar3) {
      if (local_38 != 0) {
        FUN_0089120c(local_38);
      }
      ExceptionList = local_14;
      return 0;
    }
    if (local_38 != 0) {
      FUN_0089120c(local_38);
      ExceptionList = local_14;
      return 5;
    }
  }
  else {
    local_50 = *(ushort **)(param_1 + 0x5ec0);
    uVar10 = *(int *)(param_1 + 0x5ec4) - (int)local_50 >> 1;
    bVar13 = false;
    bVar2 = false;
    local_4c = 0;
    if (uVar10 != 0) {
      do {
        uVar6 = 0;
        if (uVar4 != 0) {
          uVar11 = (uint)*local_50;
LAB_00500c10:
          if (uVar11 != **(uint **)(local_38 + uVar6 * 4)) goto code_r0x00500c17;
          puStack_40 = *(undefined4 **)(*(int *)(param_1 + 0x5eac) + 4);
          puVar8 = (undefined4 *)puStack_40[1];
          cVar1 = *(char *)((int)puVar8 + 0xb5);
          while (cVar1 == '\0') {
            if ((int)puVar8[3] < (int)uVar11) {
              puVar7 = (undefined4 *)puVar8[2];
              puVar8 = puStack_40;
            }
            else {
              puVar7 = (undefined4 *)*puVar8;
            }
            puStack_40 = puVar8;
            puVar8 = puVar7;
            cVar1 = *(char *)((int)puVar7 + 0xb5);
          }
          puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x5eac) + 4);
          if ((puStack_40 == puVar8) || ((int)uVar11 < (int)puStack_40[3])) {
            puStack_3c = puVar8;
            ppuVar9 = &puStack_3c;
          }
          else {
            ppuVar9 = &puStack_40;
          }
          if (*ppuVar9 == puVar8) {
            puVar8 = (undefined4 *)0x0;
          }
          else {
            puVar8 = *ppuVar9 + 4;
          }
          iVar12 = puVar8[2];
          if (iVar12 == 4) {
            if (bVar3) goto LAB_00500d00;
            bVar13 = true;
            goto LAB_00500cb5;
          }
          if (iVar12 != 1) {
            if (iVar12 == 2) {
              bVar2 = true;
            }
            goto LAB_00500cb5;
          }
          if (!bVar3) {
            if (local_38 != 0) {
              FUN_0089120c(local_38);
            }
            ExceptionList = local_14;
            return 2;
          }
          goto LAB_00500d00;
        }
LAB_00500cb5:
        local_50 = local_50 + 1;
        local_4c = local_4c + 1;
      } while (local_4c < uVar10);
    }
    if (!bVar3) {
      if (bVar13) {
        if (local_38 != 0) {
          FUN_0089120c(local_38);
        }
        ExceptionList = local_14;
        return 4;
      }
      if (bVar2) {
        if (local_38 != 0) {
          FUN_0089120c(local_38);
        }
        ExceptionList = local_14;
        return 1;
      }
      if (local_38 != 0) {
        FUN_0089120c(local_38);
      }
      ExceptionList = local_14;
      return 6;
    }
LAB_00500d00:
    if (local_38 != 0) {
      FUN_0089120c(local_38);
    }
  }
  ExceptionList = local_14;
  return 5;
code_r0x00500c17:
  uVar6 = uVar6 + 1;
  if (uVar4 <= uVar6) goto LAB_00500cb5;
  goto LAB_00500c10;
}

