
int * FUN_00442470(int *param_1)

{
  int *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  
  if ((((-1 < *in_ECX) && (-1 < *in_EAX)) && (iVar1 = FUN_00404ba0(), *in_ECX == 1)) &&
     ((*(int *)(iVar1 + 0x6920) != -0x16f8 &&
      (puVar2 = (undefined4 *)FUN_00508da0(), puVar2 != (undefined4 *)0x0)))) {
    local_10 = *puVar2;
    switch(local_10) {
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x20:
    case 0x24:
    case 0x25:
      local_28[0] = *in_ECX;
      local_28[1] = *in_EAX;
      local_28[2] = puVar2[1];
      local_28[3] = puVar2[3];
      uVar5 = puVar2[4];
      uVar6 = puVar2[5];
      local_c = 0;
      local_18 = uVar5;
      local_14 = uVar6;
      FUN_00409560(uVar5,uVar6);
      iVar1 = FUN_004dc700(uVar5,uVar6);
      if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x15) != '\0' || (*(int *)(iVar1 + 0x24) != 0)))) {
        local_c = 1;
      }
      piVar3 = local_28;
      piVar4 = param_1;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      return param_1;
    }
  }
  *param_1 = -1;
  param_1[1] = -1;
  param_1[2] = -1;
  param_1[3] = -1;
  param_1[6] = -1;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  return param_1;
}

