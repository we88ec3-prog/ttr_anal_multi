
/* WARNING: Removing unreachable block (ram,0x004ca2c9) */
/* WARNING: Removing unreachable block (ram,0x004ca2d9) */
/* WARNING: Removing unreachable block (ram,0x004ca2e2) */
/* WARNING: Removing unreachable block (ram,0x004ca2e5) */
/* WARNING: Removing unreachable block (ram,0x004ca2d5) */
/* WARNING: Removing unreachable block (ram,0x004ca2f3) */
/* WARNING: Removing unreachable block (ram,0x004ca303) */
/* WARNING: Removing unreachable block (ram,0x004ca30e) */
/* WARNING: Removing unreachable block (ram,0x004ca30a) */
/* WARNING: Removing unreachable block (ram,0x004ca2fe) */
/* WARNING: Removing unreachable block (ram,0x004ca311) */

void FUN_004ca200(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_3 + 0x11) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0079c460();
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x11) == '\0') {
    if (*(char *)(param_3[2] + 0x11) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x11) == '\0') {
    piVar8[1] = (int)piVar7;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar8;
  }
  else if ((int *)*piVar7 == param_3) {
    *piVar7 = (int)piVar8;
  }
  else {
    piVar7[2] = (int)piVar8;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar6 = piVar7;
    if (*(char *)((int)piVar8 + 0x11) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x11);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x11);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x11) == '\0') {
      uVar5 = FUN_007e00f0();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[4] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[4] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[4] == '\0') {
            *(undefined1 *)(piVar7 + 4) = 1;
            *(undefined1 *)(piVar6 + 4) = 0;
            FUN_007c09f0(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x11) == '\0') {
            if ((*(char *)(*piVar7 + 0x10) != '\x01') || (*(char *)(piVar7[2] + 0x10) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x10) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x10) = 1;
                *(undefined1 *)(piVar7 + 4) = 0;
                FUN_007e0090(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 4) = (char)piVar6[4];
              *(undefined1 *)(piVar6 + 4) = 1;
              *(undefined1 *)(piVar7[2] + 0x10) = 1;
              FUN_007c09f0(param_1);
              break;
            }
LAB_004ca3e7:
            *(undefined1 *)(piVar7 + 4) = 0;
          }
        }
        else {
          if ((char)piVar7[4] == '\0') {
            *(undefined1 *)(piVar7 + 4) = 1;
            *(undefined1 *)(piVar6 + 4) = 0;
            FUN_007e0090(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x11) == '\0') {
            if ((*(char *)(piVar7[2] + 0x10) == '\x01') && (*(char *)(*piVar7 + 0x10) == '\x01'))
            goto LAB_004ca3e7;
            if (*(char *)(*piVar7 + 0x10) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x10) = 1;
              *(undefined1 *)(piVar7 + 4) = 0;
              FUN_007c09f0(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 4) = (char)piVar6[4];
            *(undefined1 *)(piVar6 + 4) = 1;
            *(undefined1 *)(*piVar7 + 0x10) = 1;
            FUN_007e0090(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 4) = 1;
  }
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

