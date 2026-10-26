
int ** FUN_005384c0(int **param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *local_24;
  int *local_20;
  int *local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908428;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar4 = (int *)0x0;
  local_24 = (int *)0x0;
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  local_8 = 0;
  FUN_008438c0(&param_2);
  if (local_14 == *(int *)(in_ECX + 0x14)) {
    *param_1 = (int *)0x0;
    param_1[1] = (int *)0x0;
    param_1[2] = (int *)0x0;
    if (param_1 != &local_24) {
      *param_1 = (int *)0x0;
      param_1[1] = (int *)0x0;
      param_1[2] = (int *)0x0;
      ExceptionList = local_10;
      return param_1;
    }
  }
  else {
    param_2 = *(int **)(*(int *)(local_14 + 0x10) + 0x30);
    piVar7 = (int *)*param_2;
    piVar6 = (int *)0x0;
    if (piVar7 != param_2) {
      do {
        piVar6 = piVar7 + 3;
        if ((piVar6 < piVar4) && (local_24 <= piVar6)) {
          iVar5 = (int)piVar6 - (int)local_24;
          if (piVar4 == local_1c) {
            FUN_006d6240(uVar3);
            piVar4 = local_20;
          }
          if (piVar4 != (int *)0x0) {
            *piVar4 = local_24[iVar5 >> 2];
          }
        }
        else {
          if (piVar4 == local_1c) {
            FUN_006d6240(uVar3);
            piVar4 = local_20;
          }
          if (piVar4 != (int *)0x0) {
            *piVar4 = *piVar6;
          }
        }
        piVar4 = piVar4 + 1;
        if (*(char *)((int)piVar7 + 0x15) == '\0') {
          piVar6 = (int *)piVar7[2];
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar6 + 0x15);
            piVar7 = piVar6;
            piVar6 = (int *)*piVar6;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar6 + 0x15);
              piVar7 = piVar6;
              piVar6 = (int *)*piVar6;
            }
          }
          else {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar2 = (int *)piVar7[1];
            piVar6 = piVar7;
            while ((piVar7 = piVar2, cVar1 == '\0' && (piVar6 == (int *)piVar7[2]))) {
              cVar1 = *(char *)(piVar7[1] + 0x15);
              piVar2 = (int *)piVar7[1];
              piVar6 = piVar7;
            }
          }
        }
        piVar6 = local_24;
        local_20 = piVar4;
      } while (piVar7 != param_2);
    }
    *param_1 = (int *)0x0;
    param_1[1] = (int *)0x0;
    param_1[2] = (int *)0x0;
    if (param_1 == &local_24) {
      if (piVar6 != (int *)0x0) {
        FUN_0089120c(piVar6);
      }
    }
    else {
      *param_1 = piVar6;
      param_1[1] = piVar4;
      param_1[2] = local_1c;
    }
  }
  ExceptionList = local_10;
  return param_1;
}

