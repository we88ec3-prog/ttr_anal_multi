
int FUN_008c8710(uint param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  uint local_8;
  
  uVar3 = param_2;
  uVar2 = param_1;
  *(undefined4 *)(param_1 + 0x2d4) = 0;
  *(undefined4 *)(param_1 + 0x2d8) = 0;
  *(undefined4 *)(param_1 + 0x2dc) = 0;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  iVar6 = (**(code **)(param_1 + 0x1fc))(param_1,0x43424c43,param_2,&param_1);
  if (iVar6 == 0) {
    *(undefined4 *)(uVar2 + 0x2dc) = 2;
  }
  else {
    iVar6 = (**(code **)(uVar2 + 0x1fc))(uVar2,0x45424c43,uVar3,&param_1);
    if ((iVar6 == 0) ||
       (iVar6 = (**(code **)(uVar2 + 0x1fc))(uVar2,0x626c6f63,uVar3,&param_1), iVar6 == 0)) {
      *(undefined4 *)(uVar2 + 0x2dc) = 1;
    }
    else {
      iVar6 = (**(code **)(uVar2 + 0x1fc))(uVar2,0x73626978,uVar3,&param_1);
      if (iVar6 != 0) goto LAB_008c8955;
      *(undefined4 *)(uVar2 + 0x2dc) = 3;
    }
  }
  if (7 < param_1) {
    uVar7 = *(uint *)(uVar2 + 0x2dc);
    if (uVar7 == 0) {
      return 0;
    }
    if (uVar7 < 3) {
      iVar6 = FUN_008bc7a0(uVar3,param_1,uVar2 + 0x2d4);
      if (iVar6 != 0) goto LAB_008c8955;
      *(uint *)(uVar2 + 0x2d8) = param_1;
      puVar1 = *(undefined1 **)(uVar2 + 0x2d4);
      uVar7 = CONCAT31(CONCAT21(CONCAT11(puVar1[4],puVar1[5]),puVar1[6]),puVar1[7]);
      if (CONCAT11(*puVar1,puVar1[1]) != 2) {
        iVar6 = 2;
        goto LAB_008c8955;
      }
      if (uVar7 < 0x10000) {
        if (param_1 < uVar7 * 0x30 + 8) {
          uVar7 = (param_1 - 8) / 0x30;
        }
        *(uint *)(uVar2 + 0x2e0) = uVar7;
        return 0;
      }
    }
    else {
      if (uVar7 != 3) {
        return 0;
      }
      iVar6 = FUN_008babe0(uVar3,8);
      if (iVar6 != 0) goto LAB_008c8955;
      sVar4 = FUN_008b9960(uVar3);
      sVar5 = FUN_008b9960(uVar3);
      local_8 = FUN_008b99c0(uVar3);
      FUN_008baca0(uVar3);
      if (sVar4 == 0) {
        iVar6 = 2;
        goto LAB_008c8955;
      }
      if ((sVar5 == 1) && (local_8 < 0x10000)) {
        if (param_1 < local_8 * 4 + 8) {
          local_8 = param_1 - 8 >> 2;
        }
        iVar6 = FUN_008b9850(uVar3);
        iVar6 = FUN_008b97e0(uVar3,iVar6 + -8);
        if (iVar6 == 0) {
          iVar6 = local_8 * 4 + 8;
          *(int *)(uVar2 + 0x2d8) = iVar6;
          iVar6 = FUN_008bc7a0(uVar3,iVar6,uVar2 + 0x2d4);
          if (iVar6 == 0) {
            *(uint *)(uVar2 + 0x2e0) = local_8;
            return 0;
          }
        }
        goto LAB_008c8955;
      }
    }
  }
  iVar6 = 3;
LAB_008c8955:
  if (*(int *)(uVar2 + 0x2d4) != 0) {
    FUN_008bab90(uVar3,uVar2 + 0x2d4);
  }
  *(undefined4 *)(uVar2 + 0x2d8) = 0;
  *(undefined4 *)(uVar2 + 0x2dc) = 0;
  return iVar6;
}

