
void FUN_00648d10(int param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  
  FUN_007445d0(param_1);
  if (*(int *)(param_1 + 0x10) != 0x66) {
    return;
  }
  if (in_ECX[9] == 0) {
    return;
  }
  iVar1 = in_ECX[0x18];
  if (iVar1 == 0) {
    return;
  }
  local_10 = in_ECX[4];
  iVar2 = in_ECX[2];
  iVar3 = in_ECX[3];
  iVar6 = in_ECX[5];
  iVar4 = in_ECX[4] - iVar2;
  if (*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8) < iVar4) {
    iVar2 = iVar2 + *(int *)(in_ECX[9] + 0xbc);
    iVar5 = iVar2;
    if (iVar2 <= ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) - in_ECX[4]) + in_ECX[2]) {
      iVar5 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) - in_ECX[4]) + in_ECX[2];
    }
    if (iVar5 < 0) {
      if (iVar2 <= ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) - in_ECX[4]) + in_ECX[2]) {
        iVar2 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) - in_ECX[4]) + in_ECX[2];
      }
    }
    else {
      iVar2 = 0;
    }
    local_10 = iVar4 + iVar2;
  }
  iVar4 = in_ECX[5] - iVar3;
  if (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc) < iVar4) {
    iVar3 = iVar3 + *(int *)(in_ECX[9] + 0xc0);
    iVar5 = in_ECX[3] - in_ECX[5];
    iVar6 = iVar3;
    if (iVar3 <= (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5) {
      iVar6 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5;
    }
    if (iVar6 < 0) {
      if (iVar3 <= (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5) {
        iVar3 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5;
        iVar6 = iVar4 + iVar3;
        goto LAB_00648e2e;
      }
    }
    else {
      iVar3 = 0;
    }
    iVar6 = iVar4 + iVar3;
  }
LAB_00648e2e:
  (**(code **)(*in_ECX + 0xbc))(iVar2,iVar3,local_10,iVar6);
  return;
}

