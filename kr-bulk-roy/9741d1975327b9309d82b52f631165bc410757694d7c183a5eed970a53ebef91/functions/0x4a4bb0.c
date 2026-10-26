
void FUN_004a4bb0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int *piVar5;
  int *piVar6;
  undefined2 local_1c [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  piVar2 = *(int **)(param_1 + 4);
  piVar6 = (int *)*piVar2;
  bVar4 = false;
  if (piVar6 != piVar2) {
    do {
      if ((*(int *)(piVar6[4] + 0x5c) != 0) && (*(int *)(piVar6[4] + 0x5c) < DAT_00f93950)) {
        bVar4 = true;
      }
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar5 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar5 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != piVar2);
    if ((bVar4) && (local_1c[0] = 0xf2, DAT_00fba798 == 0)) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,local_1c,2);
    }
  }
  ExceptionList = local_14;
  return;
}

