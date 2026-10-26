
void FUN_00462570(uint param_1,uint *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  undefined **local_28 [3];
  char *local_1c;
  undefined1 local_18 [4];
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906722;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar9 = (int *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (piVar9 == (int *)0x0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_1c);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  *piVar9 = (int)piVar9;
  piVar9[1] = (int)piVar9;
  piVar9[2] = (int)piVar9;
  *(undefined1 *)(piVar9 + 4) = 1;
  *(undefined1 *)((int)piVar9 + 0x11) = 1;
  local_8 = 0;
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    FUN_004858c0(local_18,puVar3 + 3);
    if (*(char *)((int)puVar3 + 0x25) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x25);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x25);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x25);
        puVar7 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x25);
          puVar7 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  piVar12 = (int *)*piVar9;
  local_14 = piVar9;
  if (piVar12 != piVar9) {
    do {
      puVar6 = param_2;
      puVar2 = (undefined4 *)param_2[1];
      param_1 = (uint)(ushort)((short)piVar12[3] + 10000);
      if ((&param_1 < puVar2) && (puVar3 = (undefined4 *)*param_2, puVar3 <= &param_1)) {
        if (puVar2 == (undefined4 *)param_2[2]) {
          uVar10 = (int)puVar2 - (int)puVar3 >> 1;
          if (0x7ffffffe < uVar10) {
LAB_004627a4:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar10 = uVar10 + 1;
          uVar11 = (int)param_2[2] - (int)puVar3 >> 1;
          if (uVar11 < uVar10) {
            if (0x7fffffff - (uVar11 >> 1) < uVar11) {
              uVar11 = 0;
            }
            else {
              uVar11 = uVar11 + (uVar11 >> 1);
            }
            if (uVar11 < uVar10) {
              uVar11 = uVar10;
            }
            FUN_00419730(uVar11);
          }
        }
        if ((undefined2 *)puVar6[1] != (undefined2 *)0x0) {
          *(undefined2 *)puVar6[1] =
               *(undefined2 *)(*puVar6 + ((int)&param_1 - (int)puVar3 >> 1) * 2);
        }
      }
      else {
        if (puVar2 == (undefined4 *)param_2[2]) {
          uVar10 = (int)((int)puVar2 - *param_2) >> 1;
          if (0x7ffffffe < uVar10) goto LAB_004627a4;
          uVar10 = uVar10 + 1;
          uVar11 = (int)((int)param_2[2] - *param_2) >> 1;
          if (uVar11 < uVar10) {
            if (0x7fffffff - (uVar11 >> 1) < uVar11) {
              uVar11 = 0;
            }
            else {
              uVar11 = uVar11 + (uVar11 >> 1);
            }
            if (uVar11 < uVar10) {
              uVar11 = uVar10;
            }
            FUN_00419730(uVar11);
          }
        }
        if ((undefined2 *)puVar6[1] != (undefined2 *)0x0) {
          *(undefined2 *)puVar6[1] = (undefined2)param_1;
        }
      }
      puVar6[1] = puVar6[1] + 2;
      if (*(char *)((int)piVar12 + 0x11) == '\0') {
        piVar5 = (int *)piVar12[2];
        if (*(char *)((int)piVar5 + 0x11) == '\0') {
          cVar1 = *(char *)(*piVar5 + 0x11);
          piVar12 = piVar5;
          piVar5 = (int *)*piVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x11);
            piVar12 = piVar5;
            piVar5 = (int *)*piVar5;
          }
        }
        else {
          cVar1 = *(char *)(piVar12[1] + 0x11);
          piVar8 = (int *)piVar12[1];
          piVar5 = piVar12;
          while ((piVar12 = piVar8, cVar1 == '\0' && (piVar5 == (int *)piVar12[2]))) {
            cVar1 = *(char *)(piVar12[1] + 0x11);
            piVar8 = (int *)piVar12[1];
            piVar5 = piVar12;
          }
        }
      }
    } while (piVar12 != local_14);
  }
  local_8 = 1;
  FUN_004ca160(*piVar9,piVar9);
  FUN_0089120c(piVar9);
  ExceptionList = local_10;
  return;
}

