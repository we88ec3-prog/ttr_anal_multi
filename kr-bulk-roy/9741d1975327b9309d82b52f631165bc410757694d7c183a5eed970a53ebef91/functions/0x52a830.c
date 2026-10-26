
/* WARNING: Removing unreachable block (ram,0x0052a8f8) */
/* WARNING: Removing unreachable block (ram,0x0052a908) */
/* WARNING: Removing unreachable block (ram,0x0052a911) */
/* WARNING: Removing unreachable block (ram,0x0052a914) */
/* WARNING: Removing unreachable block (ram,0x0052a904) */
/* WARNING: Removing unreachable block (ram,0x0052a922) */
/* WARNING: Removing unreachable block (ram,0x0052a932) */
/* WARNING: Removing unreachable block (ram,0x0052a93d) */
/* WARNING: Removing unreachable block (ram,0x0052a939) */
/* WARNING: Removing unreachable block (ram,0x0052a92d) */
/* WARNING: Removing unreachable block (ram,0x0052a940) */

void FUN_0052a830(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x5d) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0052ac90();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x5d) == '\0') {
    if (*(char *)(param_2[2] + 0x5d) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x5d) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fc0dcc[1] == param_2) {
    DAT_00fc0dcc[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fc0dcc == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x5d) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x5d);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x5d);
        piVar5 = piVar3;
      }
    }
    *DAT_00fc0dcc = piVar5;
  }
  if ((int *)DAT_00fc0dcc[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x5d) == '\0') {
      uVar4 = FUN_0052ac70();
      DAT_00fc0dcc[2] = uVar4;
    }
    else {
      DAT_00fc0dcc[2] = piVar6;
    }
  }
  if ((char)param_2[0x17] == '\x01') {
    if (piVar7 != (int *)DAT_00fc0dcc[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x17] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x17] == '\0') {
            *(undefined1 *)(piVar6 + 0x17) = 1;
            *(undefined1 *)(piVar5 + 0x17) = 0;
            FUN_0052abb0(&DAT_00fc0dc8);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x5d) == '\0') {
            if ((*(char *)(*piVar6 + 0x5c) != '\x01') || (*(char *)(piVar6[2] + 0x5c) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x5c) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x5c) = 1;
                *(undefined1 *)(piVar6 + 0x17) = 0;
                FUN_0052ac10(&DAT_00fc0dc8);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x17) = (char)piVar5[0x17];
              *(undefined1 *)(piVar5 + 0x17) = 1;
              *(undefined1 *)(piVar6[2] + 0x5c) = 1;
              FUN_0052abb0(&DAT_00fc0dc8);
              break;
            }
LAB_0052aa27:
            *(undefined1 *)(piVar6 + 0x17) = 0;
          }
        }
        else {
          if ((char)piVar6[0x17] == '\0') {
            *(undefined1 *)(piVar6 + 0x17) = 1;
            *(undefined1 *)(piVar5 + 0x17) = 0;
            FUN_0052ac10(&DAT_00fc0dc8);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x5d) == '\0') {
            if ((*(char *)(piVar6[2] + 0x5c) == '\x01') && (*(char *)(*piVar6 + 0x5c) == '\x01'))
            goto LAB_0052aa27;
            if (*(char *)(*piVar6 + 0x5c) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x5c) = 1;
              *(undefined1 *)(piVar6 + 0x17) = 0;
              FUN_0052abb0(&DAT_00fc0dc8);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x17) = (char)piVar5[0x17];
            *(undefined1 *)(piVar5 + 0x17) = 1;
            *(undefined1 *)(*piVar6 + 0x5c) = 1;
            FUN_0052ac10(&DAT_00fc0dc8);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fc0dcc[1]);
    }
    *(undefined1 *)(piVar7 + 0x17) = 1;
  }
  FUN_0052a270(param_2 + 4);
  FUN_0089120c(param_2);
  if (DAT_00fc0dd0 != 0) {
    DAT_00fc0dd0 = DAT_00fc0dd0 + -1;
  }
  *param_1 = param_2;
  return;
}

