
/* WARNING: Removing unreachable block (ram,0x00555dc8) */
/* WARNING: Removing unreachable block (ram,0x00555dd8) */
/* WARNING: Removing unreachable block (ram,0x00555de1) */
/* WARNING: Removing unreachable block (ram,0x00555de4) */
/* WARNING: Removing unreachable block (ram,0x00555dd4) */
/* WARNING: Removing unreachable block (ram,0x00555df2) */
/* WARNING: Removing unreachable block (ram,0x00555e02) */
/* WARNING: Removing unreachable block (ram,0x00555e0d) */
/* WARNING: Removing unreachable block (ram,0x00555e09) */
/* WARNING: Removing unreachable block (ram,0x00555dfd) */
/* WARNING: Removing unreachable block (ram,0x00555e10) */

void FUN_00555d00(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x21) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0085e240();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fc1904[1] == param_2) {
    DAT_00fc1904[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fc1904 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x21);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x21);
        piVar5 = piVar3;
      }
    }
    *DAT_00fc1904 = piVar5;
  }
  if ((int *)DAT_00fc1904[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      uVar4 = FUN_00852270();
      DAT_00fc1904[2] = uVar4;
    }
    else {
      DAT_00fc1904[2] = piVar6;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar7 != (int *)DAT_00fc1904[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[8] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar5 + 8) = 0;
            FUN_00405150(&DAT_00fc1900);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(*piVar6 + 0x20) != '\x01') || (*(char *)(piVar6[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x20) = 1;
                *(undefined1 *)(piVar6 + 8) = 0;
                FUN_00819bd0(&DAT_00fc1900);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 8) = (char)piVar5[8];
              *(undefined1 *)(piVar5 + 8) = 1;
              *(undefined1 *)(piVar6[2] + 0x20) = 1;
              FUN_00405150(&DAT_00fc1900);
              break;
            }
LAB_00555ef6:
            *(undefined1 *)(piVar6 + 8) = 0;
          }
        }
        else {
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar5 + 8) = 0;
            FUN_00819bd0(&DAT_00fc1900);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(piVar6[2] + 0x20) == '\x01') && (*(char *)(*piVar6 + 0x20) == '\x01'))
            goto LAB_00555ef6;
            if (*(char *)(*piVar6 + 0x20) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x20) = 1;
              *(undefined1 *)(piVar6 + 8) = 0;
              FUN_00405150(&DAT_00fc1900);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 8) = (char)piVar5[8];
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(*piVar6 + 0x20) = 1;
            FUN_00819bd0(&DAT_00fc1900);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fc1904[1]);
    }
    *(undefined1 *)(piVar7 + 8) = 1;
  }
  if (param_2[4] != 0) {
    FUN_00440a80();
    FUN_0089120c(param_2[4]);
  }
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  FUN_0089120c(param_2);
  if (DAT_00fc1908 != 0) {
    DAT_00fc1908 = DAT_00fc1908 + -1;
  }
  *param_1 = param_2;
  return;
}

