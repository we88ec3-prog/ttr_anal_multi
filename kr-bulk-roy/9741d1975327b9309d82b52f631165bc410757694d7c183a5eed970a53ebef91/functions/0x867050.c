
void FUN_00867050(undefined ***param_1,int param_2,undefined ***param_3)

{
  undefined **ppuVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined ***pppuVar6;
  undefined ***pppuVar7;
  undefined ***pppuVar8;
  int *unaff_FS_OFFSET;
  undefined **local_28;
  undefined **local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined ***local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906968;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  iVar3 = (int)param_3 - (int)param_1 >> 4;
  iVar5 = param_2 - (int)param_1 >> 4;
  param_2 = iVar3;
  iVar2 = iVar5;
  while (iVar2 != 0) {
    iVar4 = param_2 % iVar2;
    param_2 = iVar2;
    iVar2 = iVar4;
  }
  if ((param_2 < iVar3) && (0 < param_2)) {
    local_18 = iVar5 << 4;
    local_14 = param_1 + param_2 * 4;
    do {
      pppuVar7 = (undefined ***)((int)local_14 + local_18);
      pppuVar8 = local_14;
      if ((undefined ***)((int)local_14 + local_18) == param_3) {
        pppuVar7 = param_1;
      }
      do {
        pppuVar6 = pppuVar7;
        FUN_00867d70(&local_28,pppuVar8);
        local_8 = 0;
        if (pppuVar8 != pppuVar6) {
          if (pppuVar8[1] == (undefined **)0x0) {
            pppuVar8[1] = pppuVar6[1];
          }
          FUN_00867fd0(pppuVar8,pppuVar6);
        }
        ppuVar1 = local_24;
        if (pppuVar6 != &local_28) {
          if (pppuVar6[1] == (undefined **)0x0) {
            pppuVar6[1] = local_24;
          }
          FUN_00867fd0(pppuVar6,&local_28);
        }
        local_8 = 0xffffffff;
        local_28 = gbParam::vftable;
        switch(ppuVar1) {
        case (undefined **)0x1:
        case (undefined **)0x6:
        case (undefined **)0x9:
        case (undefined **)0xa:
        case (undefined **)0xd:
          break;
        case (undefined **)0x2:
        case (undefined **)0x7:
        case (undefined **)0xb:
          break;
        case (undefined **)0x3:
        case (undefined **)0x5:
        case (undefined **)0x8:
        case (undefined **)0xc:
          break;
        case (undefined **)0x4:
          FUN_00891d3d(local_20);
        default:
          goto switchD_0086713d_default;
        }
        FUN_0089120c(local_20);
switchD_0086713d_default:
        local_20 = 0;
        if (local_1c != 0) {
          FUN_00891d3d(local_1c);
          local_1c = 0;
        }
        iVar2 = (int)param_3 - (int)pppuVar6 >> 4;
        if (iVar5 < iVar2) {
          pppuVar7 = (undefined ***)((int)pppuVar6 + local_18);
        }
        else {
          pppuVar7 = param_1 + (iVar5 - iVar2) * 4;
        }
        pppuVar8 = pppuVar6;
      } while (pppuVar7 != local_14);
      local_14 = local_14 + -4;
      param_2 = param_2 + -1;
    } while (0 < param_2);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

