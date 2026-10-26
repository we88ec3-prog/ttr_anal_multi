
void FUN_0064bc10(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *unaff_ESI;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = unaff_ESI[3];
  local_10 = unaff_ESI[4];
  local_c = unaff_ESI[5];
  iVar3 = unaff_ESI[2];
  if (param_3 == '\0') {
    iVar3 = FUN_008fed10();
    local_10 = (unaff_ESI[4] - unaff_ESI[2]) + iVar3;
    local_14 = FUN_008fed10();
    iVar2 = unaff_ESI[5] - unaff_ESI[3];
  }
  else {
    iVar1 = unaff_ESI[0x18];
    iVar2 = local_10 - iVar3;
    if (*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8) < iVar2) {
      iVar3 = FUN_008fed10();
      iVar6 = unaff_ESI[4];
      iVar5 = unaff_ESI[2];
      iVar4 = iVar3;
      if (iVar3 <= ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) - iVar6) + iVar5) {
        iVar4 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) - iVar6) + iVar5;
      }
      if (iVar4 < 0) {
        if (iVar3 <= ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) - iVar6) + iVar5) {
          iVar3 = ((*(int *)(iVar1 + 0x10) - iVar6) - *(int *)(iVar1 + 8)) + iVar5;
        }
      }
      else {
        iVar3 = 0;
      }
      local_10 = iVar2 + iVar3;
    }
    iVar2 = unaff_ESI[5] - unaff_ESI[3];
    if (iVar2 <= *(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) goto LAB_0064bd64;
    local_14 = FUN_008fed10();
    iVar5 = unaff_ESI[3] - unaff_ESI[5];
    iVar6 = local_14;
    if (local_14 <= (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5) {
      iVar6 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5;
    }
    if (iVar6 < 0) {
      if (local_14 <= (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5) {
        local_14 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + iVar5;
      }
    }
    else {
      local_14 = 0;
    }
  }
  local_c = iVar2 + local_14;
LAB_0064bd64:
  (**(code **)(*unaff_ESI + 0xbc))(iVar3,local_14,local_10,local_c);
  return;
}

