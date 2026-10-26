
undefined4 FUN_006e4e90(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  
  iVar7 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    *param_1 = param_2;
    param_1[1] = param_3;
    param_1[2] = param_4;
    param_1[3] = param_5;
    return 0;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x50) + 0x654);
  iVar5 = 100000;
  local_8 = 0;
  if (0 < iVar1) {
    piVar2 = *(int **)(*(int *)(in_ECX + 0x50) + 0x650);
    do {
      if ((piVar2[3] == *(int *)(in_ECX + 8)) &&
         (uVar3 = piVar2[1] - param_3 >> 0x1f, uVar4 = *piVar2 - param_2 >> 0x1f,
         iVar6 = ((piVar2[1] - param_3 ^ uVar3) - uVar3) + ((*piVar2 - param_2 ^ uVar4) - uVar4),
         iVar6 < iVar5)) {
        local_1c = piVar2[1];
        local_18 = piVar2[2];
        iVar7 = *piVar2;
        local_14 = piVar2[3];
        iVar5 = iVar6;
        if (iVar6 == 0) break;
      }
      local_8 = local_8 + 1;
      piVar2 = piVar2 + 4;
    } while (local_8 < iVar1);
  }
  if (iVar7 != 0) {
    *param_1 = iVar7;
    param_1[1] = local_1c;
    param_1[2] = local_18;
    param_1[3] = local_14;
    return 0;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  return 0x80004005;
}

