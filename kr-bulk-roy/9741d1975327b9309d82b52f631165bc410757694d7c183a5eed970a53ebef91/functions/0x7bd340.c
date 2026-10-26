
void FUN_007bd340(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937e7c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  local_8 = 0xffffffff;
  local_14 = DAT_00fb76a8;
  piVar4 = *(int **)(param_1 + 0x28);
  piVar6 = (int *)*piVar4;
  if (piVar6 != piVar4) {
    do {
      if (*(int *)(piVar6[10] + 0x24) == 0) {
        piVar4 = piVar6 + 3;
        if (0xf < (uint)piVar6[8]) {
          piVar4 = (int *)*piVar4;
        }
        FUN_007bd180(local_14,piVar4);
        puVar5 = (undefined4 *)piVar6[10];
        if (puVar5 != (undefined4 *)0x0) {
          if (0xf < (uint)puVar5[5]) {
            FUN_0089120c(*puVar5);
          }
          puVar5[5] = 0xf;
          puVar5[4] = 0;
          *(undefined1 *)puVar5 = 0;
          FUN_0089120c(puVar5);
          piVar6[10] = 0;
        }
        puVar5 = (undefined4 *)FUN_007c2e30(param_1 + 0x24,local_18,piVar6);
        piVar6 = (int *)*puVar5;
        piVar4 = *(int **)(param_1 + 0x28);
      }
      else if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar3 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x2d);
            piVar3 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != piVar4);
  }
  ExceptionList = local_10;
  return;
}

