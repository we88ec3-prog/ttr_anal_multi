
int FUN_008bbac0(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar1 = *param_1;
  local_8 = 1;
  if ((in_EAX != -1) && (in_EAX != 0)) {
    return 1;
  }
  iVar7 = 0;
  local_14 = 0;
  if (0 < param_4) {
    do {
      local_8 = FUN_008b97e0(param_2,*(undefined4 *)(param_3 + iVar7 * 4));
      if (local_8 != 0) {
        return local_8;
      }
      iVar2 = FUN_008b9c00(param_2,&local_8);
      if (local_8 != 0) {
        return local_8;
      }
      iVar7 = iVar7 + 1;
      local_14 = local_14 + 6 + iVar2;
    } while (iVar7 < param_4);
  }
  iVar7 = local_14 + 2;
  puVar3 = (undefined4 *)FUN_008baee0(uVar1,iVar7,&local_8);
  if (local_8 == 0) {
    iVar6 = 0;
    *puVar3 = 0x180;
    *(undefined2 *)(puVar3 + 1) = 0;
    iVar2 = 6;
    local_10 = 2;
    local_20 = 1;
    local_18 = 0;
    iVar8 = 2;
    if (0 < param_4) {
      do {
        local_8 = FUN_008b97e0(param_2,*(undefined4 *)(param_3 + local_18 * 4));
        if (local_8 != 0) goto LAB_008bbcdc;
        local_c = FUN_008b9c00(param_2,&local_8);
        if (local_8 != 0) {
          return local_8;
        }
        uVar4 = FUN_008b9ab0(param_2,&local_8);
        if (local_8 != 0) {
          return local_8;
        }
        iVar5 = (int)(uVar4 & 0xffff) >> 8;
        if (iVar5 != 0) {
          if (local_c < 3) {
            local_c = 0;
          }
          else {
            local_c = local_c + -2;
          }
          if (iVar5 == local_20) {
            iVar6 = iVar6 + local_c;
            iVar8 = iVar2;
          }
          else {
            if (iVar7 < local_10 + 3) goto LAB_008bbcdc;
            *(char *)((int)puVar3 + local_10 + 1) = (char)((uint)iVar6 >> 8);
            *(char *)((int)puVar3 + local_10 + 2) = (char)((uint)iVar6 >> 0x10);
            *(char *)(local_10 + (int)puVar3) = (char)iVar6;
            *(char *)((int)puVar3 + local_10 + 3) = (char)((uint)iVar6 >> 0x18);
            iVar8 = local_10;
            if (iVar5 == 5) break;
            if (iVar7 < iVar2 + 6) goto LAB_008bbcdc;
            *(undefined1 *)(iVar2 + (int)puVar3) = 0x80;
            *(char *)(iVar2 + 1 + (int)puVar3) = (char)((uVar4 & 0xffff) >> 8);
            local_10 = iVar2 + 2;
            *(undefined2 *)(local_10 + (int)puVar3) = 0;
            *(undefined2 *)(iVar2 + 4 + (int)puVar3) = 0;
            iVar8 = iVar2 + 6;
            iVar6 = local_c;
            local_20 = iVar5;
          }
          local_8 = 1;
          if (((local_14 < iVar8) || (iVar2 = local_c + iVar8, local_14 < iVar2)) ||
             (local_8 = FUN_008bab70(param_2,iVar8 + (int)puVar3,local_c), local_8 != 0))
          goto LAB_008bbcdc;
        }
        local_18 = local_18 + 1;
        iVar8 = local_10;
      } while (local_18 < param_4);
    }
    if ((iVar2 + 2 <= iVar7) && (*(undefined2 *)(iVar2 + (int)puVar3) = 0x380, iVar8 + 3 <= iVar7))
    {
      *(char *)(iVar8 + (int)puVar3) = (char)iVar6;
      *(char *)(iVar8 + 1 + (int)puVar3) = (char)((uint)iVar6 >> 8);
      *(char *)(iVar8 + 2 + (int)puVar3) = (char)((uint)iVar6 >> 0x10);
      *(char *)(iVar8 + 3 + (int)puVar3) = (char)((uint)iVar6 >> 0x18);
      iVar7 = FUN_008bb920(0,"type1",param_5);
      return iVar7;
    }
LAB_008bbcdc:
    FUN_008b9f80(uVar1,puVar3);
  }
  return local_8;
}

