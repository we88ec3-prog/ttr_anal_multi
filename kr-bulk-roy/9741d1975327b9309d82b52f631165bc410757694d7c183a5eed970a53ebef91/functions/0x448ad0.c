
void FUN_00448ad0(void)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  int *piVar8;
  int *piVar9;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931b1a;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)0xb;
  FUN_0082ef00(&local_14);
  if (local_18 == *(int **)(in_ECX + 0x50)) {
    iVar5 = 0;
  }
  else {
    iVar5 = local_18[4];
  }
  *(int *)(in_ECX + 0x80) = iVar5;
  FUN_0044a650(uVar4);
  local_14 = (int *)(in_ECX + 0xf0);
  FUN_0044a740();
  FUN_006afeb0();
  FUN_00615fc0(0xfa1);
  FUN_00615fc0(0x1389);
  FUN_0044a830();
  (**(code **)(**(int **)(in_ECX + 0x100) + 0x94))(0);
  piVar9 = local_14;
  uVar4 = DAT_00fe5ae4 & 1;
  *(undefined4 *)(*(int *)(*(int *)(*local_14 + 0x24c) + 0xd0) + 0xd8) = 0x1c;
  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xf4) + 0xd0) + 0xd8) = 0x3c;
  if (uVar4 == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = (int *)0x32c;
  FUN_005740f0(&local_18);
  if (local_1c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar7 = local_1c + 4;
  if (7 < (uint)local_1c[9]) {
    piVar7 = (int *)*piVar7;
  }
  FUN_0075cbb0(piVar7);
  if ((DAT_00fb93cc & 1) == 0) {
    DAT_00fb93cc = DAT_00fb93cc | 1;
    local_8 = 1;
    FUN_00445460();
    _atexit((_func_4879 *)&LAB_00bcd620);
    local_8 = 0xffffffff;
  }
  piVar7 = (int *)*DAT_00fb93f4;
  local_1c = DAT_00fb93f4;
  piVar8 = DAT_00fb93f4;
  if (piVar7 != DAT_00fb93f4) {
    do {
      iVar5 = *piVar9;
      iVar6 = *(int *)(iVar5 + 0x24c);
      if (iVar6 != 0) {
        iVar6 = *(int *)(iVar6 + 0xcc);
        if (iVar6 == 0) {
          iVar6 = -1;
        }
        else {
          iVar6 = FUN_0075d370(*(undefined4 *)(iVar6 + 0xe4));
        }
        iVar5 = *(int *)(*(int *)(iVar5 + 0x24c) + 0xcc);
        if (iVar5 != 0) {
          for (piVar9 = *(int **)(iVar5 + 0xa8);
              (piVar9 != *(int **)(iVar5 + 0xac) && (*(int *)(*piVar9 + 0x20) != iVar6));
              piVar9 = piVar9 + 1) {
          }
        }
        FUN_00757800(piVar7 + 4);
        piVar8 = local_1c;
      }
      if (*(char *)((int)piVar7 + 0x2d) == '\0') {
        piVar9 = (int *)piVar7[2];
        if (*(char *)((int)piVar9 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar9 + 0x2d);
          piVar7 = piVar9;
          piVar9 = (int *)*piVar9;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar9 + 0x2d);
            piVar7 = piVar9;
            piVar9 = (int *)*piVar9;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x2d);
          piVar3 = (int *)piVar7[1];
          piVar9 = piVar7;
          while ((piVar7 = piVar3, cVar1 == '\0' && (piVar9 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x2d);
            piVar3 = (int *)piVar7[1];
            piVar9 = piVar7;
          }
        }
      }
      piVar9 = local_14;
    } while (piVar7 != piVar8);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = (int *)0x32c;
  FUN_005740f0(&local_1c);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar7 = local_18 + 4;
  if (7 < (uint)local_18[9]) {
    piVar7 = (int *)*piVar7;
  }
  FUN_0075cc70(*piVar9,piVar7);
  if (*(int *)(*piVar9 + 0x24c) != 0) {
    FUN_00749920(*(int *)(*piVar9 + 0x24c));
  }
  (**(code **)(*(int *)*piVar9 + 200))();
  ExceptionList = local_10;
  return;
}

