
int FUN_008c9c10(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  ushort uVar11;
  int iVar12;
  uint local_14;
  undefined4 *local_10;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_2 + 0x1c);
  local_10 = (undefined4 *)0x0;
  uVar2 = FUN_008b9ab0(param_2,&local_8);
  uVar8 = (uint)uVar2;
  if (local_8 != 0) {
    return local_8;
  }
  if (*(ushort *)(param_1 + 0x108) < uVar8) {
    return 3;
  }
  iVar4 = FUN_008bc7d0(uVar1,2,0,uVar8,0,&local_8);
  if ((local_8 == 0) && (local_8 = FUN_008babe0(param_2,uVar8 * 2), local_8 == 0)) {
    iVar12 = 0;
    if (uVar8 != 0) {
      do {
        uVar3 = FUN_008b9960(param_2);
        *(undefined2 *)(iVar4 + iVar12 * 2) = uVar3;
        iVar12 = iVar12 + 1;
      } while (iVar12 < (int)uVar8);
    }
    FUN_008baca0(param_2);
    uVar9 = 0;
    iVar12 = 0;
    local_14 = 0;
    if (uVar8 != 0) {
      do {
        uVar5 = (uint)*(ushort *)(iVar4 + iVar12 * 2);
        if ((0x101 < uVar5) && (uVar5 = uVar5 - 0x101, (int)uVar9 < (int)uVar5)) {
          uVar9 = uVar5 & 0xffff;
          local_14 = uVar9;
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < (int)uVar8);
    }
    local_10 = (undefined4 *)FUN_008bc7d0(uVar1,4,0,uVar9,0,&local_8);
    if (local_8 == 0) {
      uVar11 = 0;
      uVar7 = 0;
      uVar8 = uVar9;
      if ((short)uVar9 != 0) {
        do {
          uVar7 = (ushort)uVar8;
          iVar12 = FUN_008b9850(param_2);
          puVar10 = local_10;
          if (param_3 <= iVar12) {
            if (uVar11 < uVar7) goto LAB_008c9e28;
            break;
          }
          uVar8 = FUN_008b9a40(param_2,&local_8);
          uVar8 = uVar8 & 0xff;
          if (local_8 != 0) goto LAB_008c9e63;
          if ((param_3 < (int)uVar8) ||
             (iVar12 = FUN_008b9850(param_2), (int)(param_3 - uVar8) < iVar12)) {
            iVar12 = FUN_008b9850(param_2);
            if (param_3 - iVar12 < 0) {
              uVar8 = 0;
            }
            else {
              iVar12 = FUN_008b9850(param_2);
              uVar8 = param_3 - iVar12;
            }
          }
          iVar12 = FUN_008bc7d0(uVar1,1,0,uVar8 + 1,0,&local_8);
          local_10[uVar11] = iVar12;
          if ((local_8 != 0) || (local_8 = FUN_008bab70(param_2,iVar12,uVar8), local_8 != 0))
          goto LAB_008c9e63;
          *(undefined1 *)(uVar8 + local_10[uVar11]) = 0;
          uVar7 = (ushort)local_14;
          uVar11 = uVar11 + 1;
          uVar8 = local_14;
        } while (uVar11 < uVar7);
      }
      goto LAB_008c9d2a;
    }
  }
LAB_008c9e81:
  FUN_008b9f80(uVar1,local_10);
  FUN_008b9f80(uVar1,iVar4);
  return local_8;
LAB_008c9e63:
  do {
    FUN_008b9f80(uVar1,*puVar10);
    *puVar10 = 0;
    uVar9 = uVar9 - 1;
    puVar10 = puVar10 + 1;
  } while (uVar9 != 0);
  goto LAB_008c9e81;
  while( true ) {
    uVar11 = uVar11 + 1;
    *puVar6 = 0;
    if (uVar7 <= uVar11) break;
LAB_008c9e28:
    puVar6 = (undefined1 *)FUN_008bc7d0(uVar1,1,0,1,0,&local_8);
    local_10[uVar11] = puVar6;
    if (local_8 != 0) goto LAB_008c9e63;
  }
LAB_008c9d2a:
  *(ushort *)(param_1 + 0x268) = uVar2;
  *(ushort *)(param_1 + 0x26a) = uVar7;
  *(int *)(param_1 + 0x26c) = iVar4;
  *(undefined4 **)(param_1 + 0x270) = local_10;
  return 0;
}

