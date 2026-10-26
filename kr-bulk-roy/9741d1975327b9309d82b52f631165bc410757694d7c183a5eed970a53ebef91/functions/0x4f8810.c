
/* WARNING: Removing unreachable block (ram,0x004f88d0) */
/* WARNING: Removing unreachable block (ram,0x004f88e0) */
/* WARNING: Removing unreachable block (ram,0x004f88e9) */
/* WARNING: Removing unreachable block (ram,0x004f88ec) */
/* WARNING: Removing unreachable block (ram,0x004f88dc) */
/* WARNING: Removing unreachable block (ram,0x004f88fa) */
/* WARNING: Removing unreachable block (ram,0x004f890a) */
/* WARNING: Removing unreachable block (ram,0x004f8915) */
/* WARNING: Removing unreachable block (ram,0x004f8911) */
/* WARNING: Removing unreachable block (ram,0x004f8905) */
/* WARNING: Removing unreachable block (ram,0x004f8918) */

void FUN_004f8810(int param_1,undefined4 *param_2,int *param_3)

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
LAB_004f89fc:
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
            goto LAB_004f89fc;
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
  if (0xf < (uint)param_3[0xf]) {
    FUN_0089120c(param_3[10]);
  }
  param_3[0xf] = 0xf;
  param_3[0xe] = 0;
  *(undefined1 *)(param_3 + 10) = 0;
  if (0xf < (uint)param_3[8]) {
    FUN_0089120c(param_3[3]);
  }
  param_3[8] = 0xf;
  param_3[7] = 0;
  *(undefined1 *)(param_3 + 3) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

