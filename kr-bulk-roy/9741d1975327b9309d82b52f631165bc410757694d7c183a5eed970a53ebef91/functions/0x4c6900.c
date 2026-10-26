
/* WARNING: Removing unreachable block (ram,0x004c69c8) */
/* WARNING: Removing unreachable block (ram,0x004c69d8) */
/* WARNING: Removing unreachable block (ram,0x004c69e1) */
/* WARNING: Removing unreachable block (ram,0x004c69e4) */
/* WARNING: Removing unreachable block (ram,0x004c69d4) */
/* WARNING: Removing unreachable block (ram,0x004c69f2) */
/* WARNING: Removing unreachable block (ram,0x004c6a02) */
/* WARNING: Removing unreachable block (ram,0x004c6a0d) */
/* WARNING: Removing unreachable block (ram,0x004c6a09) */
/* WARNING: Removing unreachable block (ram,0x004c69fd) */
/* WARNING: Removing unreachable block (ram,0x004c6a10) */

void FUN_004c6900(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x29) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0080f830();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x29) == '\0') {
    if (*(char *)(param_2[2] + 0x29) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x29) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fd9268[1] == param_2) {
    DAT_00fd9268[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fd9268 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x29) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x29);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x29);
        piVar5 = piVar3;
      }
    }
    *DAT_00fd9268 = piVar5;
  }
  if ((int *)DAT_00fd9268[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x29) == '\0') {
      uVar4 = FUN_0080f810();
      DAT_00fd9268[2] = uVar4;
    }
    else {
      DAT_00fd9268[2] = piVar6;
    }
  }
  if ((char)param_2[10] == '\x01') {
    if (piVar7 != (int *)DAT_00fd9268[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[10] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[10] == '\0') {
            *(undefined1 *)(piVar6 + 10) = 1;
            *(undefined1 *)(piVar5 + 10) = 0;
            FUN_007c0a50(&DAT_00fd9264);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x29) == '\0') {
            if ((*(char *)(*piVar6 + 0x28) != '\x01') || (*(char *)(piVar6[2] + 0x28) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x28) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x28) = 1;
                *(undefined1 *)(piVar6 + 10) = 0;
                FUN_0080f7b0(&DAT_00fd9264);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 10) = (char)piVar5[10];
              *(undefined1 *)(piVar5 + 10) = 1;
              *(undefined1 *)(piVar6[2] + 0x28) = 1;
              FUN_007c0a50(&DAT_00fd9264);
              break;
            }
LAB_004c6af7:
            *(undefined1 *)(piVar6 + 10) = 0;
          }
        }
        else {
          if ((char)piVar6[10] == '\0') {
            *(undefined1 *)(piVar6 + 10) = 1;
            *(undefined1 *)(piVar5 + 10) = 0;
            FUN_0080f7b0(&DAT_00fd9264);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x29) == '\0') {
            if ((*(char *)(piVar6[2] + 0x28) == '\x01') && (*(char *)(*piVar6 + 0x28) == '\x01'))
            goto LAB_004c6af7;
            if (*(char *)(*piVar6 + 0x28) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x28) = 1;
              *(undefined1 *)(piVar6 + 10) = 0;
              FUN_007c0a50(&DAT_00fd9264);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 10) = (char)piVar5[10];
            *(undefined1 *)(piVar5 + 10) = 1;
            *(undefined1 *)(*piVar6 + 0x28) = 1;
            FUN_0080f7b0(&DAT_00fd9264);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fd9268[1]);
    }
    *(undefined1 *)(piVar7 + 10) = 1;
  }
  FUN_0089120c(param_2);
  if (DAT_00fd926c != 0) {
    DAT_00fd926c = DAT_00fd926c + -1;
  }
  *param_1 = param_2;
  return;
}

