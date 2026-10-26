
void FUN_006f33f0(uint *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  puVar4 = param_1;
  FUN_006f3350(&local_18);
  if (local_24 < -0x5000) {
    param_1 = (uint *)0x1;
    FUN_007bb350();
  }
  if (0x5000 < local_24) {
    param_1 = (uint *)0x2;
    FUN_007bb350();
  }
  if (local_20 < -0x5000) {
    param_1 = (uint *)0x3;
    FUN_007bb350();
  }
  if (0x5000 < local_20) {
    param_1 = (uint *)0x4;
    FUN_007bb350();
  }
  if (local_18 < -0x5000) {
    param_1 = (uint *)0x5;
    FUN_007bb350();
  }
  if (0x5000 < local_18) {
    param_1 = (uint *)0x6;
    FUN_007bb350();
  }
  if (local_14 < -0x5000) {
    param_1 = (uint *)0x7;
    FUN_007bb350();
  }
  if (0x5000 < local_14) {
    param_1 = (uint *)0x8;
    FUN_007bb350();
  }
  if (DAT_00fba80c == 0) {
    iVar5 = FUN_00891268(0x57c);
    if (iVar5 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if (*(int *)(DAT_00fba80c + 0x20) == 0) {
    param_1 = (uint *)(DAT_00fba80c + 0x478);
  }
  else {
    param_1 = (uint *)(DAT_00fba80c + 0x378);
  }
  if (param_1 != (uint *)0x0) {
    iVar5 = 9;
    local_c = 0x20;
    do {
      if (*(char *)((int)param_1 + -9 + iVar5) != '\0') {
        piVar7 = (int *)puVar4[1];
        local_8 = iVar5;
        if (&local_8 < piVar7) {
          piVar1 = (int *)*puVar4;
          if (&local_8 < piVar1) goto LAB_006f3575;
          if (piVar7 == (int *)puVar4[2]) {
            FUN_00797930();
          }
          if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar4[1] =
                 *(undefined4 *)(*puVar4 + ((int)&local_8 - (int)piVar1 >> 2) * 4);
          }
        }
        else {
LAB_006f3575:
          if (piVar7 == (int *)puVar4[2]) {
            FUN_00797930();
          }
          if ((int *)puVar4[1] != (int *)0x0) {
            *(int *)puVar4[1] = iVar5;
          }
        }
        puVar4[1] = puVar4[1] + 4;
      }
      iVar5 = iVar5 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
    local_c = 0;
  }
  if (DAT_00fba80c == 0) {
    iVar5 = FUN_00891268(0x57c);
    if (iVar5 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if (*(int *)(DAT_00fba80c + 0x20) == 0) {
    return;
  }
  iVar5 = 4;
  piVar7 = (int *)(DAT_00fba80c + 0x18);
  while (((*piVar7 == 0 || (iVar6 = (**(code **)(*(int *)*piVar7 + 0x30))(), iVar6 == 0)) ||
         (iVar6 = (**(code **)(*(int *)*piVar7 + 0x20))(), iVar6 == 0))) {
    piVar7 = piVar7 + -1;
    iVar5 = iVar5 + -1;
    if (iVar5 < 0) {
      return;
    }
  }
  if (*(int *)(iVar6 + 0x20) == -1) {
    return;
  }
  iVar5 = (*(int *)(iVar6 + 0x20) + 0x8ca) / 0x1194 + 0x29;
  puVar2 = (undefined4 *)puVar4[1];
  param_1 = (uint *)iVar5;
  if (&param_1 < puVar2) {
    puVar3 = (undefined4 *)*puVar4;
    if (puVar3 <= &param_1) {
      if (puVar2 == (undefined4 *)puVar4[2]) {
        FUN_00797930();
      }
      if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar4[1] = *(undefined4 *)(*puVar4 + ((int)&param_1 - (int)puVar3 >> 2) * 4)
        ;
        puVar4[1] = puVar4[1] + 4;
        return;
      }
      goto LAB_006f3678;
    }
  }
  if (puVar2 == (undefined4 *)puVar4[2]) {
    FUN_00797930();
  }
  if ((int *)puVar4[1] != (int *)0x0) {
    *(int *)puVar4[1] = iVar5;
  }
LAB_006f3678:
  puVar4[1] = puVar4[1] + 4;
  return;
}

