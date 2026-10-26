
void FUN_007a6970(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  int unaff_EDI;
  float10 fVar11;
  int *piStack_18;
  float fStack_14;
  int *local_10;
  undefined4 local_c;
  
  *(undefined4 *)(unaff_EDI + 0x104) = param_2;
  *(undefined4 *)(unaff_EDI + 0xa8) = param_1;
  piVar5 = *(int **)(unaff_EDI + 0x108);
  *(undefined4 *)(unaff_EDI + 0xb0) = 0;
  if (piVar5 != (int *)0x0) {
    if (piVar5[0x1b] == 0) {
      iVar6 = *(int *)(unaff_EDI + 0x10c);
      local_c = *(undefined4 *)(unaff_EDI + 0x120);
      local_10 = piVar5;
      iVar4 = FUN_00404fd0(iVar6,*(undefined4 *)(iVar6 + 4));
      if (*(int *)(unaff_EDI + 0x110) == 0x1ffffffe) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      *(int *)(unaff_EDI + 0x110) = *(int *)(unaff_EDI + 0x110) + 1;
      *(int *)(iVar6 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      *(undefined4 *)(unaff_EDI + 0x108) = 0;
      *(undefined4 *)(unaff_EDI + 0x120) = 0;
    }
    else {
      FUN_007be5f0();
    }
  }
  piVar5 = (int *)FUN_007a7800(param_1);
  *(int **)(unaff_EDI + 0xac) = piVar5;
  if (piVar5 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar5 + 0x40))();
    piVar5 = *(int **)(unaff_EDI + 0xa0);
    piVar9 = (int *)(uint)*(byte *)(iVar6 + 0x29);
    if (piVar5 != (int *)0x0) {
      if (piVar9 == (int *)0x0) {
        piVar5[5] = 1;
      }
      else {
        piStack_18 = piVar9;
        FUN_0082ef00(&piStack_18);
        if ((fStack_14 != *(float *)(*piVar5 + 0x38)) && (*(int *)((int)fStack_14 + 0x10) != 0)) {
          iVar6 = *(int *)(*(int *)((int)fStack_14 + 0x10) + 4);
          piVar5[4] = (int)piVar9;
          piVar5[1] = iVar6;
          piVar5[2] = 0;
        }
        *(int **)(*(int *)(unaff_EDI + 0xa0) + 0x14) = piVar9;
      }
    }
    FUN_007a6d80();
    fVar11 = (float10)(**(code **)(**(int **)(unaff_EDI + 0xac) + 0xc))();
    fStack_14 = (float)fVar11;
    fVar11 = (float10)(**(code **)(**(int **)(unaff_EDI + 0xac) + 0x18))();
    piStack_18 = (int *)(float)fVar11;
    fVar11 = (float10)(**(code **)(**(int **)(unaff_EDI + 0xac) + 0xc))();
    local_10 = (int *)(float)fVar11;
    uVar7 = (**(code **)(**(int **)(unaff_EDI + 0xac) + 0x38))();
    *(float *)(unaff_EDI + 0xb8) = fStack_14;
    if (fStack_14 < *(float *)(unaff_EDI + 0xc0)) {
      *(float *)(unaff_EDI + 0xc0) = fStack_14;
      *(undefined4 *)(unaff_EDI + 0xc4) = 0;
    }
    if (fStack_14 < *(float *)(unaff_EDI + 0xbc)) {
      *(undefined4 *)(unaff_EDI + 0xbc) = 0;
    }
    *(int **)(unaff_EDI + 0xbc) = piStack_18;
    *(int **)(unaff_EDI + 0xc0) = local_10;
    uVar8 = FUN_008fed10();
    *(undefined4 *)(unaff_EDI + 0xc4) = uVar8;
    *(undefined4 *)(unaff_EDI + 200) = uVar7;
    piVar5 = *(int **)(unaff_EDI + 0x70);
    piVar9 = (int *)*piVar5;
    piStack_18 = piVar9;
    local_10 = piVar5;
    if (piVar9 != piVar5) {
      do {
        iVar6 = piVar9[6];
        uVar10 = 0;
        if (*(int *)(iVar6 + 0x1c) - *(int *)(iVar6 + 0x18) >> 2 != 0) {
          do {
            (**(code **)(**(int **)(*(int *)(iVar6 + 0x18) + uVar10 * 4) + 8))(param_1);
            uVar10 = uVar10 + 1;
            piVar9 = piStack_18;
            piVar5 = local_10;
          } while (uVar10 < (uint)(*(int *)(iVar6 + 0x1c) - *(int *)(iVar6 + 0x18) >> 2));
        }
        if (*(char *)((int)piVar9 + 0x21) == '\0') {
          piVar2 = (int *)piVar9[2];
          if (*(char *)((int)piVar2 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x21);
            piVar9 = piVar2;
            piVar2 = (int *)*piVar2;
            while (piStack_18 = piVar9, cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x21);
              piVar9 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar9[1] + 0x21);
            piVar3 = (int *)piVar9[1];
            piVar2 = piVar9;
            while ((piVar9 = piVar3, piStack_18 = piVar9, cVar1 == '\0' &&
                   (piVar2 == (int *)piVar9[2]))) {
              cVar1 = *(char *)(piVar9[1] + 0x21);
              piVar3 = (int *)piVar9[1];
              piVar2 = piVar9;
            }
          }
        }
      } while (piVar9 != piVar5);
    }
  }
  if (*(int **)(unaff_EDI + 0x120) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 0x120) + 8))();
    *(undefined4 *)(unaff_EDI + 0x120) = 0;
  }
  FUN_007a6c60();
  FUN_007a6730();
  return;
}

