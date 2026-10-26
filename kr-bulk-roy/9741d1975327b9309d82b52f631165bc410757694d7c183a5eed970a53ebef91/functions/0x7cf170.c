
void FUN_007cf170(int param_1)

{
  char cVar1;
  void *_Dst;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  int *local_8;
  
  puVar8 = (uint *)(param_1 + 0x20);
  _Dst = (void *)*puVar8;
  if (_Dst != *(void **)(param_1 + 0x24)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x24),0);
    *(void **)(param_1 + 0x24) = _Dst;
  }
  piVar7 = (int *)**(int **)(param_1 + 0x14);
  local_8 = piVar7;
  if (piVar7 != *(int **)(param_1 + 0x14)) {
    do {
      piVar2 = *(int **)(param_1 + 0x24);
      piVar4 = piVar7 + 10;
      if ((piVar4 < piVar2) && (piVar3 = (int *)*puVar8, piVar3 <= piVar4)) {
        if (piVar2 == *(int **)(param_1 + 0x28)) {
          uVar5 = (int)piVar2 - (int)piVar3 >> 2;
          if (0x3ffffffe < uVar5) {
LAB_007cf2e1:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar5 = uVar5 + 1;
          uVar6 = (int)*(int **)(param_1 + 0x28) - (int)piVar3 >> 2;
          if (uVar6 < uVar5) {
            if (0x3fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar5) {
              uVar6 = uVar5;
            }
            FUN_00797980(uVar6);
          }
        }
        if (*(undefined4 **)(param_1 + 0x24) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0x24) =
               *(undefined4 *)(*puVar8 + ((int)piVar4 - (int)piVar3 >> 2) * 4);
        }
      }
      else {
        if (piVar2 == *(int **)(param_1 + 0x28)) {
          uVar5 = (int)((int)piVar2 - *puVar8) >> 2;
          if (0x3ffffffe < uVar5) goto LAB_007cf2e1;
          uVar5 = uVar5 + 1;
          uVar6 = (int)((int)*(int **)(param_1 + 0x28) - *puVar8) >> 2;
          if (uVar6 < uVar5) {
            if (0x3fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar5) {
              uVar6 = uVar5;
            }
            FUN_00797980(uVar6);
            piVar7 = local_8;
          }
        }
        if (*(int **)(param_1 + 0x24) != (int *)0x0) {
          **(int **)(param_1 + 0x24) = *piVar4;
        }
      }
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 4;
      if (*(char *)((int)piVar7 + 0x2d) == '\0') {
        piVar4 = (int *)piVar7[2];
        if (*(char *)((int)piVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x2d);
          piVar7 = piVar4;
          piVar4 = (int *)*piVar4;
          while (local_8 = piVar7, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x2d);
            piVar7 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x2d);
          piVar2 = (int *)piVar7[1];
          piVar4 = piVar7;
          while ((piVar7 = piVar2, local_8 = piVar7, cVar1 == '\0' && (piVar4 == (int *)piVar7[2])))
          {
            cVar1 = *(char *)(piVar7[1] + 0x2d);
            piVar2 = (int *)piVar7[1];
            piVar4 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_1 + 0x14));
  }
  return;
}

