
void FUN_0062cb90(uint *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint *puVar6;
  int *piVar7;
  int *piVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00926cae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 0;
    FUN_006ccd20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce3c0);
  }
  puVar6 = param_1;
  local_8 = 0xffffffff;
  piVar8 = (int *)*DAT_00fc1800;
  if (piVar8 != DAT_00fc1800) {
    do {
      if (piVar8[5] == param_2) {
        puVar2 = (undefined4 *)puVar6[1];
        iVar3 = piVar8[4];
        param_1 = (uint *)iVar3;
        if (&param_1 < puVar2) {
          puVar4 = (undefined4 *)*puVar6;
          if (&param_1 < puVar4) goto LAB_0062cc40;
          if (puVar2 == (undefined4 *)puVar6[2]) {
            FUN_006d6240();
          }
          if ((undefined4 *)puVar6[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar6[1] =
                 *(undefined4 *)(*puVar6 + ((int)&param_1 - (int)puVar4 >> 2) * 4);
          }
        }
        else {
LAB_0062cc40:
          if (puVar2 == (undefined4 *)puVar6[2]) {
            FUN_006d6240();
          }
          if ((int *)puVar6[1] != (int *)0x0) {
            *(int *)puVar6[1] = iVar3;
          }
        }
        puVar6[1] = puVar6[1] + 4;
      }
      if (*(char *)((int)piVar8 + 0x19) == '\0') {
        piVar5 = (int *)piVar8[2];
        if (*(char *)((int)piVar5 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar5 + 0x19);
          piVar8 = piVar5;
          piVar5 = (int *)*piVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x19);
            piVar8 = piVar5;
            piVar5 = (int *)*piVar5;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x19);
          piVar7 = (int *)piVar8[1];
          piVar5 = piVar8;
          while ((piVar8 = piVar7, cVar1 == '\0' && (piVar5 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x19);
            piVar7 = (int *)piVar8[1];
            piVar5 = piVar8;
          }
        }
      }
    } while (piVar8 != DAT_00fc1800);
  }
  ExceptionList = local_10;
  return;
}

