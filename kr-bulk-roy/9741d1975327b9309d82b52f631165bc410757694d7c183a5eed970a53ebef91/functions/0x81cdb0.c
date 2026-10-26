
/* WARNING: Removing unreachable block (ram,0x0081ce70) */
/* WARNING: Removing unreachable block (ram,0x0081ce80) */
/* WARNING: Removing unreachable block (ram,0x0081ce89) */
/* WARNING: Removing unreachable block (ram,0x0081ce8c) */
/* WARNING: Removing unreachable block (ram,0x0081ce7c) */
/* WARNING: Removing unreachable block (ram,0x0081ce9a) */
/* WARNING: Removing unreachable block (ram,0x0081ceaa) */
/* WARNING: Removing unreachable block (ram,0x0081ceb5) */
/* WARNING: Removing unreachable block (ram,0x0081ceb1) */
/* WARNING: Removing unreachable block (ram,0x0081cea5) */
/* WARNING: Removing unreachable block (ram,0x0081ceb8) */

void FUN_0081cdb0(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_3 + 0x45) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00426d80();
  piVar7 = (int *)*param_3;
  if (*(char *)((int)piVar7 + 0x45) == '\0') {
    if (*(char *)(param_3[2] + 0x45) == '\0') {
      piVar7 = (int *)param_3[2];
    }
  }
  else {
    piVar7 = (int *)param_3[2];
  }
  piVar6 = (int *)param_3[1];
  if (*(char *)((int)piVar7 + 0x45) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar7;
  }
  else if ((int *)*piVar6 == param_3) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x45) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x45);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x45);
        piVar5 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar7 + 0x45) == '\0') {
      uVar4 = FUN_0085eae0();
      *(undefined4 *)(*(int *)(param_1 + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar6;
    }
  }
  if ((char)param_3[0x11] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x11] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x11] == '\0') {
            *(undefined1 *)(piVar6 + 0x11) = 1;
            *(undefined1 *)(piVar5 + 0x11) = 0;
            FUN_0085f0d0(param_1);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x45) == '\0') {
            if ((*(char *)(*piVar6 + 0x44) != '\x01') || (*(char *)(piVar6[2] + 0x44) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x44) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x44) = 1;
                *(undefined1 *)(piVar6 + 0x11) = 0;
                FUN_004f8cc0(param_1);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x11) = (char)piVar5[0x11];
              *(undefined1 *)(piVar5 + 0x11) = 1;
              *(undefined1 *)(piVar6[2] + 0x44) = 1;
              FUN_0085f0d0(param_1);
              break;
            }
LAB_0081cf9c:
            *(undefined1 *)(piVar6 + 0x11) = 0;
          }
        }
        else {
          if ((char)piVar6[0x11] == '\0') {
            *(undefined1 *)(piVar6 + 0x11) = 1;
            *(undefined1 *)(piVar5 + 0x11) = 0;
            FUN_004f8cc0(param_1);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x45) == '\0') {
            if ((*(char *)(piVar6[2] + 0x44) == '\x01') && (*(char *)(*piVar6 + 0x44) == '\x01'))
            goto LAB_0081cf9c;
            if (*(char *)(*piVar6 + 0x44) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x44) = 1;
              *(undefined1 *)(piVar6 + 0x11) = 0;
              FUN_0085f0d0(param_1);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x11) = (char)piVar5[0x11];
            *(undefined1 *)(piVar5 + 0x11) = 1;
            *(undefined1 *)(*piVar6 + 0x44) = 1;
            FUN_004f8cc0(param_1);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 0x11) = 1;
  }
  if (param_3[0xd] != 0) {
    FUN_0089120c(param_3[0xd]);
  }
  param_3[0xd] = 0;
  param_3[0xe] = 0;
  param_3[0xf] = 0;
  if (7 < (uint)param_3[0xb]) {
    FUN_0089120c(param_3[6]);
  }
  param_3[0xb] = 7;
  param_3[10] = 0;
  *(undefined2 *)(param_3 + 6) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

