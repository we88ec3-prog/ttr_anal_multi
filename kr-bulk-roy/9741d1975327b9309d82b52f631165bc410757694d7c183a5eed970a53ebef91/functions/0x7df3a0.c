
void FUN_007df3a0(int param_1)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int *local_10;
  int local_c [2];
  
  FUN_007dfcc0(param_1 + 0x18,local_c,*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x1c));
  piVar10 = (int *)**(int **)(param_1 + 0xc);
  local_10 = piVar10;
  if (piVar10 == *(int **)(param_1 + 0xc)) {
    return;
  }
  do {
    iVar3 = piVar10[3];
    local_c[0] = iVar3;
    uVar6 = FUN_007df8c0(*(undefined4 *)(iVar3 + 8));
    puVar7 = (undefined4 *)FUN_007df9c0(uVar6,*(undefined4 *)(iVar3 + 0xc));
    puVar1 = puVar7 + 2;
    *puVar7 = *(undefined4 *)(iVar3 + 4);
    piVar4 = (int *)puVar7[3];
    if ((local_c < piVar4) && (piVar5 = (int *)*puVar1, piVar5 <= local_c)) {
      if (piVar4 == (int *)puVar7[4]) {
        uVar8 = (int)piVar4 - (int)piVar5 >> 2;
        if (0x3ffffffe < uVar8) {
LAB_007df52b:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar8 = uVar8 + 1;
        uVar9 = (int)puVar7[4] - (int)piVar5 >> 2;
        if (uVar9 < uVar8) {
          if (0x3fffffff - (uVar9 >> 1) < uVar9) {
            uVar9 = 0;
          }
          else {
            uVar9 = uVar9 + (uVar9 >> 1);
          }
          if (uVar9 < uVar8) {
            uVar9 = uVar8;
          }
          FUN_00797980(uVar9);
          piVar10 = local_10;
        }
      }
      if ((undefined4 *)puVar7[3] != (undefined4 *)0x0) {
        *(undefined4 *)puVar7[3] = *(undefined4 *)(*puVar1 + ((int)local_c - (int)piVar5 >> 2) * 4);
      }
    }
    else {
      if (piVar4 == (int *)puVar7[4]) {
        uVar8 = (int)((int)piVar4 - *puVar1) >> 2;
        if (0x3ffffffe < uVar8) goto LAB_007df52b;
        uVar8 = uVar8 + 1;
        uVar9 = (int)((int)puVar7[4] - *puVar1) >> 2;
        if (uVar9 < uVar8) {
          if (0x3fffffff - (uVar9 >> 1) < uVar9) {
            uVar9 = 0;
          }
          else {
            uVar9 = uVar9 + (uVar9 >> 1);
          }
          if (uVar9 < uVar8) {
            uVar9 = uVar8;
          }
          FUN_00797980(uVar9);
          piVar10 = local_10;
        }
      }
      if ((int *)puVar7[3] != (int *)0x0) {
        *(int *)puVar7[3] = iVar3;
      }
    }
    puVar7[3] = puVar7[3] + 4;
    if (*(char *)((int)piVar10 + 0x11) == '\0') {
      piVar4 = (int *)piVar10[2];
      if (*(char *)((int)piVar4 + 0x11) == '\0') {
        cVar2 = *(char *)(*piVar4 + 0x11);
        piVar10 = piVar4;
        piVar4 = (int *)*piVar4;
        while (local_10 = piVar10, cVar2 == '\0') {
          cVar2 = *(char *)(*piVar4 + 0x11);
          piVar10 = piVar4;
          piVar4 = (int *)*piVar4;
        }
      }
      else {
        cVar2 = *(char *)(piVar10[1] + 0x11);
        piVar5 = (int *)piVar10[1];
        piVar4 = piVar10;
        while ((piVar10 = piVar5, local_10 = piVar10, cVar2 == '\0' && (piVar4 == (int *)piVar10[2])
               )) {
          cVar2 = *(char *)(piVar10[1] + 0x11);
          piVar5 = (int *)piVar10[1];
          piVar4 = piVar10;
        }
      }
    }
    if (piVar10 == *(int **)(param_1 + 0xc)) {
      return;
    }
  } while( true );
}

