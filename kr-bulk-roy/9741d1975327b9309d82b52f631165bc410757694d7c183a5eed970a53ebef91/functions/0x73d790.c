
undefined4
FUN_0073d790(undefined4 param_1,int param_2,short *param_3,int param_4,int param_5,int *param_6,
            int param_7,int *param_8)

{
  short sVar1;
  longlong lVar2;
  bool bVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_60;
  int local_58;
  int local_50;
  int local_48;
  
  iVar7 = 0;
  bVar3 = false;
  local_60 = 0;
  local_58 = 0;
  if (param_4 < 0) {
    psVar4 = param_3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    param_4 = (int)psVar4 - (int)(param_3 + 1) >> 1;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  if (0 < param_4) {
    do {
      iVar5 = FUN_008b8ce0(*(undefined4 *)(*(int *)(param_2 + 8) + 0x58),param_3[iVar7]);
      iVar6 = FUN_00740140();
      iVar8 = 0;
      if (((iVar5 != 0) && (iVar6 == 0)) ||
         ((iVar8 = FUN_0073d5e0(), iVar8 != 0 &&
          ((iVar5 = FUN_008b8ce0(*(undefined4 *)(*(int *)(iVar8 + 8) + 0x58),param_3[iVar7]),
           iVar5 != 0 && (iVar6 = FUN_00740140(), iVar6 == 0)))))) {
        if (local_58 != 0) {
          if (iVar8 == 0) {
            FUN_008b8b80(*(undefined4 *)(*(int *)(param_2 + 8) + 0x58),local_58,iVar5);
            local_60 = local_60 + local_50;
          }
          else {
            FUN_008b8b80(*(undefined4 *)(*(int *)(iVar8 + 8) + 0x58),local_58,iVar5);
            local_60 = local_60 + local_50;
          }
        }
        local_60 = local_60 + local_48;
        if ((*(int *)(param_2 + 0x18) != 0) && (*(int *)(*(int *)(param_2 + 8) + 0x50) == 0)) {
          local_60 = local_60 + 0x40;
        }
        if (param_7 != 0) {
          *(int *)(param_7 + iVar7 * 4) = local_60;
        }
        local_58 = iVar5;
        if (param_6 != (int *)0x0) {
          FUN_00892d30();
          iVar5 = FUN_008fed10();
          if (((param_5 < iVar5) || (param_5 < 0)) && (!bVar3)) {
            *param_6 = iVar7;
            bVar3 = true;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_4);
  }
  if ((param_6 != (int *)0x0) && (!bVar3)) {
    *param_6 = param_4;
  }
  if (param_8 != (int *)0x0) {
    iVar7 = *(int *)(*(int *)(param_2 + 8) + 0x58);
    lVar2 = (longlong)((int)*(short *)(iVar7 + 0x46) - (int)*(short *)(iVar7 + 0x48)) *
            (longlong)*(int *)(*(int *)(iVar7 + 0x58) + 0x14);
    lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
    *param_8 = local_60;
    param_8[1] = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + 1;
  }
  return 1;
}

