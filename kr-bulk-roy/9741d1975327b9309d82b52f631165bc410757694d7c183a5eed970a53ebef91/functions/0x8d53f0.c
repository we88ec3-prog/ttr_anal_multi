
int FUN_008d53f0(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  
  iVar1 = *param_2;
  if ((iVar1 == 0) || (*(uint *)(iVar1 + 0x10) <= param_3)) {
    return 6;
  }
  uVar2 = *(undefined4 *)(iVar1 + 0x68);
  if (param_3 != 0) {
    param_3 = param_3 - 1;
  }
  psVar7 = (short *)(param_3 * 0x10 + *(int *)(iVar1 + 0x124));
  *(int *)(param_1 + 0x4c) = (int)psVar7[4] + (int)psVar7[3];
  iVar6 = (int)psVar7[1] - (int)*psVar7;
  *(undefined2 *)(param_1 + 0x5c) = 1;
  *(undefined1 *)(param_1 + 0x5e) = 1;
  *(int *)(param_1 + 0x50) = iVar6;
  bVar4 = (byte)*(undefined4 *)(iVar1 + 0x134) & 3;
  if (7 < (1 << bVar4) - 1U) {
    return 3;
  }
  switch(bVar4) {
  case 0:
    uVar5 = iVar6 + 7 >> 3;
    break;
  case 1:
    *(uint *)(param_1 + 0x54) = iVar6 + 0xf >> 3 & 0xfffffffe;
    goto LAB_008d5498;
  case 2:
    *(uint *)(param_1 + 0x54) = iVar6 + 0x1f >> 3 & 0xfffffffc;
    goto LAB_008d5498;
  case 3:
    uVar5 = iVar6 + 0x3f >> 3 & 0xfffffff8;
  }
  *(uint *)(param_1 + 0x54) = uVar5;
LAB_008d5498:
  iVar3 = *(int *)(param_1 + 0x4c) * *(int *)(param_1 + 0x54);
  iVar6 = FUN_008bb1d0(param_1,iVar3);
  if (((iVar6 == 0) && (iVar6 = FUN_008b97e0(uVar2,*(undefined4 *)(psVar7 + 6)), iVar6 == 0)) &&
     (iVar6 = FUN_008bab70(uVar2,*(undefined4 *)(param_1 + 0x58),iVar3), iVar6 == 0)) {
    if ((*(byte *)(iVar1 + 0x134) & 8) == 0) {
      FUN_008d3be0();
    }
    uVar5 = *(uint *)(iVar1 + 0x134);
    if (((uVar5 >> 1 ^ uVar5) & 4) != 0) {
      iVar6 = 1 << ((byte)(uVar5 >> 4) & 3);
      if (iVar6 == 2) {
        FUN_008d3c20();
      }
      else if (iVar6 == 4) {
        FUN_008d3c50();
      }
    }
    *(undefined4 *)(param_1 + 0x48) = 0x62697473;
    *(int *)(param_1 + 100) = (int)*psVar7;
    *(int *)(param_1 + 0x68) = (int)psVar7[3];
    *(int *)(param_1 + 0x28) = (int)psVar7[2] << 6;
    *(int *)(param_1 + 0x20) = (int)*psVar7 << 6;
    *(int *)(param_1 + 0x24) = (int)psVar7[3] << 6;
    *(int *)(param_1 + 0x18) = ((int)psVar7[1] - (int)*psVar7) * 0x40;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x4c) << 6;
    FUN_008b86a0((int *)(param_1 + 0x18),(*(int *)(iVar1 + 0xd0) + *(int *)(iVar1 + 0xcc)) * 0x40);
    return 0;
  }
  param_1 = iVar6;
  return param_1;
}

