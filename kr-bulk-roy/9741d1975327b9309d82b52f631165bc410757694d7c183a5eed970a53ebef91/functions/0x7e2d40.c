
void FUN_007e2d40(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009378ee;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if ((*param_1 == 1) && (piVar5 = *(int **)param_1[2], piVar5 != (int *)param_1[2])) {
    do {
      if ((DAT_00fe1ac0 & 1) == 0) {
        DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
        local_c = 0;
        FUN_007bb970(uVar4);
        _atexit((_func_4879 *)&LAB_00bceac0);
        local_c = 0xffffffff;
      }
      FUN_007bcf60();
      if (*(char *)((int)piVar5 + 0x2d) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x2d);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x2d);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != (int *)param_1[2]);
  }
  FUN_007e3190(param_1 + 1);
  ExceptionList = local_14;
  return;
}

