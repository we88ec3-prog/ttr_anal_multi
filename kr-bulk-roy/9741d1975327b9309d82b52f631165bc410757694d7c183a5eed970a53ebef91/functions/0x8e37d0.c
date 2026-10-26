
void FUN_008e37d0(int *param_1,int *param_2,int param_3,char param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  bool bVar7;
  int local_50;
  int local_40 [6];
  undefined4 local_28 [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_40[1] = *param_2;
  bVar7 = *(char *)(param_3 + 9) == '\0';
  local_40[0] = *param_1;
  uVar3 = (uint)!bVar7;
  iVar4 = 0;
  if (uVar3 != 0xfffffff7) {
    do {
      cVar1 = *(char *)(iVar4 + param_3);
      iVar6 = local_40[iVar4];
      local_40[iVar4 + 2] = iVar6;
      if (cVar1 != '\0') {
        iVar2 = FUN_008e1f60();
        local_40[iVar4 + 2] = iVar2 + iVar6;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uVar3 + 9));
  }
  if (bVar7) {
    local_14 = *param_2;
  }
  if (param_4 == '\0') {
    if (*(char *)(param_3 + 10) == '\0') {
      local_10 = *param_1;
    }
    else {
      local_10 = FUN_008e1f60();
      local_10 = local_10 + local_18;
    }
    if (*(char *)(param_3 + 0xb) == '\0') {
      iVar4 = *param_2;
    }
    else {
      iVar4 = FUN_008e1f60();
      iVar4 = iVar4 + local_14;
    }
  }
  else {
    iVar4 = local_18 - *param_1;
    if (iVar4 < 0) {
      iVar4 = *param_1 - local_18;
    }
    iVar6 = local_14 - *param_2;
    if (iVar6 < 0) {
      iVar6 = *param_2 - local_14;
    }
    iVar2 = FUN_008e1f60();
    if (iVar6 < iVar4) {
      iVar4 = *param_2;
      local_10 = iVar2 + local_18;
    }
    else {
      local_10 = *param_1;
      iVar4 = iVar2 + local_14;
    }
  }
  local_c = iVar4;
  puVar5 = local_28;
  local_50 = 2;
  do {
    FUN_008e3480(puVar5[-4],puVar5[-3],puVar5[-2],puVar5[-1],*puVar5,puVar5[1]);
    puVar5 = puVar5 + 6;
    local_50 = local_50 + -1;
  } while (local_50 != 0);
  FUN_008e1fb0();
  *param_1 = local_10;
  *param_2 = iVar4;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

