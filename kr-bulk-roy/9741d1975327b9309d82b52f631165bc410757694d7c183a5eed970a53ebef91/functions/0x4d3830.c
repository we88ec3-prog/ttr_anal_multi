
/* WARNING: Removing unreachable block (ram,0x004d38f8) */
/* WARNING: Removing unreachable block (ram,0x004d3908) */
/* WARNING: Removing unreachable block (ram,0x004d3911) */
/* WARNING: Removing unreachable block (ram,0x004d3914) */
/* WARNING: Removing unreachable block (ram,0x004d3904) */
/* WARNING: Removing unreachable block (ram,0x004d3922) */
/* WARNING: Removing unreachable block (ram,0x004d3932) */
/* WARNING: Removing unreachable block (ram,0x004d393d) */
/* WARNING: Removing unreachable block (ram,0x004d3939) */
/* WARNING: Removing unreachable block (ram,0x004d392d) */
/* WARNING: Removing unreachable block (ram,0x004d3940) */

void FUN_004d3830(undefined4 *param_1,int *param_2)

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
  if ((int *)DAT_00fc7f10[1] == param_2) {
    DAT_00fc7f10[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fc7f10 == param_2) {
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
    *DAT_00fc7f10 = piVar5;
  }
  if ((int *)DAT_00fc7f10[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      uVar4 = FUN_00852270();
      DAT_00fc7f10[2] = uVar4;
    }
    else {
      DAT_00fc7f10[2] = piVar6;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar7 != (int *)DAT_00fc7f10[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[8] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar5 + 8) = 0;
            FUN_00405150(&DAT_00fc7f0c);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(*piVar6 + 0x20) != '\x01') || (*(char *)(piVar6[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x20) = 1;
                *(undefined1 *)(piVar6 + 8) = 0;
                FUN_00819bd0(&DAT_00fc7f0c);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 8) = (char)piVar5[8];
              *(undefined1 *)(piVar5 + 8) = 1;
              *(undefined1 *)(piVar6[2] + 0x20) = 1;
              FUN_00405150(&DAT_00fc7f0c);
              break;
            }
LAB_004d3a27:
            *(undefined1 *)(piVar6 + 8) = 0;
          }
        }
        else {
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar5 + 8) = 0;
            FUN_00819bd0(&DAT_00fc7f0c);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(piVar6[2] + 0x20) == '\x01') && (*(char *)(*piVar6 + 0x20) == '\x01'))
            goto LAB_004d3a27;
            if (*(char *)(*piVar6 + 0x20) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x20) = 1;
              *(undefined1 *)(piVar6 + 8) = 0;
              FUN_00405150(&DAT_00fc7f0c);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 8) = (char)piVar5[8];
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(*piVar6 + 0x20) = 1;
            FUN_00819bd0(&DAT_00fc7f0c);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fc7f10[1]);
    }
    *(undefined1 *)(piVar7 + 8) = 1;
  }
  if (param_2[4] != 0) {
    FUN_0089120c(param_2[4]);
  }
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  FUN_0089120c(param_2);
  if (DAT_00fc7f14 != 0) {
    DAT_00fc7f14 = DAT_00fc7f14 + -1;
  }
  *param_1 = param_2;
  return;
}

