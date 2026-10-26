
/* WARNING: Removing unreachable block (ram,0x00828d6d) */
/* WARNING: Removing unreachable block (ram,0x00828d7d) */
/* WARNING: Removing unreachable block (ram,0x00828d89) */
/* WARNING: Removing unreachable block (ram,0x00828d8c) */
/* WARNING: Removing unreachable block (ram,0x00828d79) */
/* WARNING: Removing unreachable block (ram,0x00828d9a) */
/* WARNING: Removing unreachable block (ram,0x00828daa) */
/* WARNING: Removing unreachable block (ram,0x00828db5) */
/* WARNING: Removing unreachable block (ram,0x00828db1) */
/* WARNING: Removing unreachable block (ram,0x00828da5) */
/* WARNING: Removing unreachable block (ram,0x00828db8) */

void FUN_00828c90(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(char *)((int)param_2 + 0x95) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_004a62d0();
  piVar4 = (int *)*param_2;
  if (*(char *)((int)piVar4 + 0x95) == '\0') {
    if (*(char *)(param_2[2] + 0x95) == '\0') {
      piVar4 = (int *)param_2[2];
    }
  }
  else {
    piVar4 = (int *)param_2[2];
  }
  piVar3 = (int *)param_2[1];
  if (*(char *)((int)piVar4 + 0x95) == '\0') {
    piVar4[1] = (int)piVar3;
  }
  if ((int *)DAT_00fd93fc[1] == param_2) {
    DAT_00fd93fc[1] = piVar4;
  }
  else if ((int *)*piVar3 == param_2) {
    *piVar3 = (int)piVar4;
  }
  else {
    piVar3[2] = (int)piVar4;
  }
  if ((int *)*DAT_00fd93fc == param_2) {
    piVar1 = piVar3;
    if (*(char *)((int)piVar4 + 0x95) == '\0') {
      piVar1 = (int *)FUN_004a6330();
    }
    *DAT_00fd93fc = piVar1;
  }
  if ((int *)DAT_00fd93fc[2] == param_2) {
    if (*(char *)((int)piVar4 + 0x95) == '\0') {
      uVar2 = FUN_008290f0();
      DAT_00fd93fc[2] = uVar2;
    }
    else {
      DAT_00fd93fc[2] = piVar3;
    }
  }
  if ((char)param_2[0x25] == '\x01') {
    if (piVar4 != (int *)DAT_00fd93fc[1]) {
      do {
        piVar1 = piVar3;
        if ((char)piVar4[0x25] != '\x01') break;
        piVar3 = (int *)*piVar1;
        if (piVar4 == piVar3) {
          piVar3 = (int *)piVar1[2];
          if ((char)piVar3[0x25] == '\0') {
            *(undefined1 *)(piVar3 + 0x25) = 1;
            *(undefined1 *)(piVar1 + 0x25) = 0;
            FUN_00829030(&DAT_00fd93f8);
            piVar3 = (int *)piVar1[2];
          }
          if (*(char *)((int)piVar3 + 0x95) == '\0') {
            if ((*(char *)(*piVar3 + 0x94) != '\x01') || (*(char *)(piVar3[2] + 0x94) != '\x01')) {
              if (*(char *)(piVar3[2] + 0x94) == '\x01') {
                *(undefined1 *)(*piVar3 + 0x94) = 1;
                *(undefined1 *)(piVar3 + 0x25) = 0;
                FUN_00829090(&DAT_00fd93f8);
                piVar3 = (int *)piVar1[2];
              }
              *(char *)(piVar3 + 0x25) = (char)piVar1[0x25];
              *(undefined1 *)(piVar1 + 0x25) = 1;
              *(undefined1 *)(piVar3[2] + 0x94) = 1;
              FUN_00829030(&DAT_00fd93f8);
              break;
            }
LAB_00828ef9:
            *(undefined1 *)(piVar3 + 0x25) = 0;
          }
        }
        else {
          if ((char)piVar3[0x25] == '\0') {
            *(undefined1 *)(piVar3 + 0x25) = 1;
            *(undefined1 *)(piVar1 + 0x25) = 0;
            FUN_00829090(&DAT_00fd93f8);
            piVar3 = (int *)*piVar1;
          }
          if (*(char *)((int)piVar3 + 0x95) == '\0') {
            if ((*(char *)(piVar3[2] + 0x94) == '\x01') && (*(char *)(*piVar3 + 0x94) == '\x01'))
            goto LAB_00828ef9;
            if (*(char *)(*piVar3 + 0x94) == '\x01') {
              *(undefined1 *)(piVar3[2] + 0x94) = 1;
              *(undefined1 *)(piVar3 + 0x25) = 0;
              FUN_00829030(&DAT_00fd93f8);
              piVar3 = (int *)*piVar1;
            }
            *(char *)(piVar3 + 0x25) = (char)piVar1[0x25];
            *(undefined1 *)(piVar1 + 0x25) = 1;
            *(undefined1 *)(*piVar3 + 0x94) = 1;
            FUN_00829090(&DAT_00fd93f8);
            break;
          }
        }
        piVar3 = (int *)piVar1[1];
        piVar4 = piVar1;
      } while (piVar1 != (int *)DAT_00fd93fc[1]);
    }
    *(undefined1 *)(piVar4 + 0x25) = 1;
  }
  FUN_00827e30();
  FUN_0089120c(param_2);
  if (DAT_00fd9400 != 0) {
    DAT_00fd9400 = DAT_00fd9400 + -1;
  }
  *param_1 = param_2;
  return;
}

