
void FUN_008b8800(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if ((*(byte *)(param_1 + 8) & 1) == 0) {
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0x10000;
    *(undefined4 *)(iVar1 + 0x14) = 0x10000;
    return;
  }
  uVar6 = 0;
  iVar5 = 0;
  local_8 = 0;
  local_c = 0;
  switch(*param_2) {
  case 0:
    uVar6 = (uint)*(ushort *)(param_1 + 0x44);
    local_8 = uVar6;
    break;
  case 1:
    uVar6 = (int)*(short *)(param_1 + 0x46) - (int)*(short *)(param_1 + 0x48);
    local_8 = uVar6;
    break;
  case 2:
    uVar6 = *(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x38);
    local_8 = *(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x34);
    break;
  case 3:
    uVar6 = (int)*(short *)(param_1 + 0x46) - (int)*(short *)(param_1 + 0x48);
    local_8 = (int)*(short *)(param_1 + 0x4c);
    break;
  case 4:
    *(int *)(iVar1 + 0x10) = param_2[1];
    iVar2 = param_2[2];
    *(int *)(iVar1 + 0x14) = iVar2;
    if (*(int *)(iVar1 + 0x10) == 0) {
      *(int *)(iVar1 + 0x10) = iVar2;
    }
    else if (iVar2 == 0) {
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x10);
    }
    goto LAB_008b8987;
  default:
    goto switchD_008b8830_default;
  }
  if ((int)local_8 < 0) {
    local_8 = -local_8;
  }
  if ((int)uVar6 < 0) {
    uVar6 = -uVar6;
  }
switchD_008b8830_default:
  if (param_2[3] == 0) {
    local_c = param_2[1];
    local_10 = local_c;
  }
  else {
    local_c = (param_2[1] * param_2[3] + 0x24) / 0x48;
    local_10 = param_2[1];
  }
  if (param_2[4] == 0) {
    iVar5 = param_2[2];
  }
  else {
    iVar5 = (param_2[2] * param_2[4] + 0x24) / 0x48;
  }
  if (local_10 == 0) {
    uVar4 = FUN_008b7f40(iVar5,uVar6);
    *(undefined4 *)(iVar1 + 0x14) = uVar4;
    *(undefined4 *)(iVar1 + 0x10) = uVar4;
    local_c = FUN_008b7dc0(iVar5,local_8,uVar6);
  }
  else {
    iVar2 = FUN_008b7f40(local_c,local_8);
    *(int *)(iVar1 + 0x10) = iVar2;
    if (param_2[2] == 0) {
      *(int *)(iVar1 + 0x14) = iVar2;
      iVar5 = FUN_008b7dc0(local_c,uVar6,local_8);
    }
    else {
      iVar3 = FUN_008b7f40(iVar5,uVar6);
      *(int *)(iVar1 + 0x14) = iVar3;
      if (*param_2 == 3) {
        if (iVar2 < iVar3) {
          *(int *)(iVar1 + 0x14) = iVar2;
        }
        else {
          *(int *)(iVar1 + 0x10) = iVar3;
        }
      }
    }
  }
LAB_008b8987:
  if (*param_2 != 0) {
    local_c = FUN_008b7f10(*(undefined2 *)(param_1 + 0x44),*(undefined4 *)(iVar1 + 0x10));
    iVar5 = FUN_008b7f10(*(undefined2 *)(param_1 + 0x44),*(undefined4 *)(iVar1 + 0x14));
  }
  *(short *)(iVar1 + 0xc) = (short)(local_c + 0x20 >> 6);
  *(short *)(iVar1 + 0xe) = (short)(iVar5 + 0x20 >> 6);
  FUN_008b8700();
  return;
}

