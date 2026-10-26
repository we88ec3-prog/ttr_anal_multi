
int FUN_008c98b0(uint param_1,int param_2,uint param_3,short *param_4)

{
  int iVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  uint local_c;
  int local_8;
  
  uVar5 = param_1;
  param_4[0] = 0;
  param_4[1] = 0;
  iVar1 = *(int *)(param_1 + 0x2d4);
  iVar4 = iVar1 + 0xc + param_2 * 4;
  local_8 = 0;
  uVar7 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 8 + param_2 * 4),
                                     *(undefined1 *)(iVar1 + 9 + param_2 * 4)),
                            *(undefined1 *)(iVar4 + -2)),*(undefined1 *)(iVar4 + -1));
  iVar4 = (**(code **)(param_1 + 0x1fc))(param_1,0x73626978);
  if (iVar4 != 0) {
    return iVar4;
  }
  param_2 = FUN_008b9850();
  if (param_3 <= *(uint *)(uVar5 + 0x10)) {
    do {
      if ((local_c <= uVar7) || (local_c - uVar7 < param_3 * 4 + 0xc)) {
        return 3;
      }
      iVar4 = FUN_008b97e0();
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_008babe0();
      if (iVar4 != 0) {
        return iVar4;
      }
      uVar5 = FUN_008b99c0();
      uVar6 = FUN_008b99c0();
      FUN_008baca0();
      if (uVar5 == uVar6) {
        return 6;
      }
      if (uVar6 <= uVar5) {
        return 3;
      }
      if (uVar6 - uVar5 < 8) {
        return 3;
      }
      if (local_c - uVar7 < uVar6) {
        return 3;
      }
      iVar4 = FUN_008b97e0();
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_008babe0();
      if (iVar4 != 0) {
        return iVar4;
      }
      sVar2 = FUN_008b9960();
      sVar3 = FUN_008b9960();
      uVar5 = FUN_008b99c0();
      if (0x706e6720 < uVar5) {
        bVar8 = uVar5 == 0x74696666;
LAB_008c9a71:
        iVar4 = 7;
        if (bVar8) {
          iVar4 = 2;
        }
LAB_008c9a7d:
        FUN_008baca0();
        uVar5 = param_1;
        if (iVar4 == 0) {
          FUN_008c3530(param_1,0,param_3,&param_2,&param_1);
          param_4[2] = sVar2;
          param_4[3] = *param_4 - sVar3;
          param_4[4] = (short)((int)((uint)*(ushort *)(*(int *)(uVar5 + 0x58) + 0xc) *
                                    (param_1 & 0xffff)) / (int)(uint)*(ushort *)(uVar5 + 0xb2));
        }
        return iVar4;
      }
      if (uVar5 == 0x706e6720) {
        iVar4 = 7;
        goto LAB_008c9a7d;
      }
      if (uVar5 != 0x64757065) {
        bVar8 = uVar5 == 0x6a706720;
        goto LAB_008c9a71;
      }
      if (3 < local_8) {
        iVar4 = 3;
        goto LAB_008c9a7d;
      }
      uVar5 = FUN_008b9960();
      param_3 = uVar5 & 0xffff;
      FUN_008baca0();
      local_8 = local_8 + 1;
    } while ((uVar5 & 0xffff) <= *(uint *)(param_1 + 0x10));
  }
  return 6;
}

