
void FUN_0062d0b0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int local_50;
  undefined1 local_44 [20];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00926c7a;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_c = 0;
    FUN_006ccd20(uVar6);
    _atexit((_func_4879 *)&LAB_00bce3c0);
    if ((DAT_00fc1724 & 1) == 0) {
      DAT_00fc1724 = DAT_00fc1724 | 1;
      local_c = 1;
      FUN_006ccd20();
      _atexit((_func_4879 *)&LAB_00bce3c0);
    }
  }
  local_c = 0xffffffff;
  FUN_006cdb80();
  iVar7 = FUN_006cda20();
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_c = 2;
    FUN_006ccd20(uVar6);
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_c = 0xffffffff;
  }
  piVar2 = *(int **)(param_1 + 0x120);
  piVar3 = (int *)*piVar2;
  while (piVar3 != piVar2) {
    if ((iVar7 != 0) &&
       (piVar9 = (int *)**(int **)(iVar7 + 0x44), piVar9 != *(int **)(iVar7 + 0x44))) {
      do {
        if (piVar9[5] == piVar3[3]) {
          piVar4 = piVar9 + 4;
          FUN_0062db10(piVar4);
          if (local_50 == DAT_00fc1800) {
            local_24 = *piVar4;
            local_20 = piVar9[4];
            local_1c = piVar9[5];
            uVar8 = FUN_00821c50();
          }
          else {
            FUN_00535c60(&DAT_00fc17fc,local_44,local_50);
            local_30 = *piVar4;
            local_2c = piVar9[4];
            local_28 = piVar9[5];
            uVar8 = FUN_00821c50();
          }
          FUN_00517bf0(&DAT_00fc17fc,uVar8);
        }
        if (*(char *)((int)piVar9 + 0x19) == '\0') {
          piVar4 = (int *)piVar9[2];
          if (*(char *)((int)piVar4 + 0x19) == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x19);
            piVar9 = piVar4;
            piVar4 = (int *)*piVar4;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar4 + 0x19);
              piVar9 = piVar4;
              piVar4 = (int *)*piVar4;
            }
          }
          else {
            cVar1 = *(char *)(piVar9[1] + 0x19);
            piVar5 = (int *)piVar9[1];
            piVar4 = piVar9;
            while ((piVar9 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar9[2]))) {
              cVar1 = *(char *)(piVar9[1] + 0x19);
              piVar5 = (int *)piVar9[1];
              piVar4 = piVar9;
            }
          }
        }
      } while (piVar9 != *(int **)(iVar7 + 0x44));
    }
    FUN_00628740();
  }
  ExceptionList = local_14;
  return;
}

