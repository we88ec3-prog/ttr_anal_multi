
void FUN_007a76b0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint *in_EAX;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *local_8;
  
  piVar7 = (int *)**(int **)(param_1 + 0x60);
  local_8 = piVar7;
  if (piVar7 != *(int **)(param_1 + 0x60)) {
    do {
      piVar5 = (int *)in_EAX[1];
      piVar3 = piVar7 + 6;
      piVar8 = piVar7;
      if ((piVar3 < piVar5) && (piVar2 = (int *)*in_EAX, piVar2 <= piVar3)) {
        iVar9 = (int)piVar3 - (int)piVar2 >> 3;
        if (piVar5 == (int *)in_EAX[2]) {
          uVar4 = (int)piVar5 - (int)piVar2 >> 3;
          if (0x1ffffffe < uVar4) {
LAB_007a77f2:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar4 = uVar4 + 1;
          uVar6 = (int)in_EAX[2] - (int)piVar2 >> 3;
          if (uVar6 < uVar4) {
            if (0x1fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar4) {
              uVar6 = uVar4;
            }
            FUN_007aa2a0(uVar6);
            piVar8 = local_8;
          }
        }
        piVar5 = (int *)in_EAX[1];
        if (piVar5 != (int *)0x0) {
          uVar4 = *in_EAX;
          *piVar5 = *(int *)(uVar4 + iVar9 * 8);
          iVar9 = *(int *)(uVar4 + 4 + iVar9 * 8);
LAB_007a7793:
          piVar5[1] = iVar9;
        }
      }
      else {
        if (piVar5 == (int *)in_EAX[2]) {
          uVar4 = (int)((int)piVar5 - *in_EAX) >> 3;
          if (0x1ffffffe < uVar4) goto LAB_007a77f2;
          uVar4 = uVar4 + 1;
          uVar6 = (int)((int)in_EAX[2] - *in_EAX) >> 3;
          if (uVar6 < uVar4) {
            if (0x1fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar4) {
              uVar6 = uVar4;
            }
            FUN_007aa2a0(uVar6);
            piVar8 = local_8;
          }
        }
        piVar5 = (int *)in_EAX[1];
        if (piVar5 != (int *)0x0) {
          *piVar5 = *piVar3;
          iVar9 = piVar7[7];
          goto LAB_007a7793;
        }
      }
      in_EAX[1] = in_EAX[1] + 8;
      if (*(char *)((int)piVar8 + 0x21) == '\0') {
        piVar7 = (int *)piVar8[2];
        if (*(char *)((int)piVar7 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar7 + 0x21);
          piVar8 = piVar7;
          piVar7 = (int *)*piVar7;
          while (local_8 = piVar8, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar7 + 0x21);
            piVar8 = piVar7;
            piVar7 = (int *)*piVar7;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x21);
          piVar3 = (int *)piVar8[1];
          piVar7 = piVar8;
          while ((piVar8 = piVar3, local_8 = piVar8, cVar1 == '\0' && (piVar7 == (int *)piVar8[2])))
          {
            cVar1 = *(char *)(piVar8[1] + 0x21);
            piVar3 = (int *)piVar8[1];
            piVar7 = piVar8;
          }
        }
      }
      piVar7 = piVar8;
    } while (piVar8 != *(int **)(param_1 + 0x60));
  }
  return;
}

