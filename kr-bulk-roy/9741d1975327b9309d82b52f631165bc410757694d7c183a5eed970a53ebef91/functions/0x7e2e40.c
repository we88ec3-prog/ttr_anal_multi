
void FUN_007e2e40(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093792c;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  *param_1 = 1;
  piVar5 = *(int **)param_1[2];
  if (piVar5 != (int *)param_1[2]) {
    do {
      piVar4 = (int *)piVar5[10];
      piVar3 = piVar4;
      local_1c = piVar4;
      if (0xf < (uint)piVar4[5]) {
        piVar3 = (int *)*piVar4;
        local_1c = (int *)*piVar4;
      }
      if ((DAT_00fe1ac0 & 1) == 0) {
        DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
        local_c = 0;
        FUN_007bb970(uVar2);
        _atexit((_func_4879 *)&LAB_00bceac0);
        local_c = 0xffffffff;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
      (*DAT_00fe1adc)(piVar3,local_1c);
      SetEvent(DAT_00fe1b2c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
      if (0xf < (uint)piVar4[5]) {
        piVar4 = (int *)*piVar4;
      }
      if ((DAT_00fe3314 & 1) == 0) {
        DAT_00fe3314 = DAT_00fe3314 | 1;
        local_c = 1;
        FUN_007ed9f0();
        _atexit((_func_4879 *)&LAB_00bd0ae0);
        local_c = 0xffffffff;
      }
      FUN_007edbf0(&DAT_00fe3318,piVar4);
      if (*(char *)((int)piVar5 + 0x2d) == '\0') {
        piVar4 = (int *)piVar5[2];
        if (*(char *)((int)piVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x2d);
          piVar5 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x2d);
            piVar5 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x2d);
          piVar3 = (int *)piVar5[1];
          piVar4 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar4 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x2d);
            piVar3 = (int *)piVar5[1];
            piVar4 = piVar5;
          }
        }
      }
    } while (piVar5 != (int *)param_1[2]);
  }
  ExceptionList = local_14;
  return;
}

