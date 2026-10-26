
void FUN_006b8030(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  local_20 = 0;
  piVar6 = (int *)(in_ECX + 0x80);
  do {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar3);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    iVar4 = *piVar6;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar4 + 0xa4) = 1;
    if (*(char *)((int)&DAT_00f94220 + local_20) + -1 < 0) {
      iVar4 = *piVar6;
      if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
        iVar5 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
        if (iVar5 == 0xbf6b) {
          iVar4 = *(int *)(iVar4 + 0x94);
          iVar5 = *(int *)(iVar4 + 0x10);
          if (iVar5 != 0) {
            piVar2 = *(int **)(iVar5 + 8);
            if (piVar2 != (int *)0x0) {
              piVar1 = piVar2 + 0x27;
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                (**(code **)(*piVar2 + 0x28))();
              }
            }
            *(undefined4 *)(iVar4 + 0x10) = 0;
          }
        }
      }
    }
    else {
      iVar4 = *piVar6;
      if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
        iVar4 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
        if (iVar4 == 0xbf6b) {
          FUN_0077b200();
        }
      }
    }
    (**(code **)(*(int *)*piVar6 + 0x90))(1);
    (**(code **)(*(int *)*piVar6 + 200))();
    local_20 = local_20 + 1;
    piVar6 = piVar6 + 1;
  } while (local_20 < 3);
  ExceptionList = local_14;
  return;
}

