
/* WARNING: Removing unreachable block (ram,0x004f8378) */
/* WARNING: Removing unreachable block (ram,0x004f8388) */
/* WARNING: Removing unreachable block (ram,0x004f8391) */
/* WARNING: Removing unreachable block (ram,0x004f8394) */
/* WARNING: Removing unreachable block (ram,0x004f8384) */
/* WARNING: Removing unreachable block (ram,0x004f83a2) */
/* WARNING: Removing unreachable block (ram,0x004f83b2) */
/* WARNING: Removing unreachable block (ram,0x004f83bd) */
/* WARNING: Removing unreachable block (ram,0x004f83b9) */
/* WARNING: Removing unreachable block (ram,0x004f83ad) */
/* WARNING: Removing unreachable block (ram,0x004f83c0) */

void FUN_004f82b0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x75) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_004f8d20();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x75) == '\0') {
    if (*(char *)(param_2[2] + 0x75) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x75) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fb7474[1] == param_2) {
    DAT_00fb7474[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fb7474 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x75) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x75);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x75);
        piVar5 = piVar3;
      }
    }
    *DAT_00fb7474 = piVar5;
  }
  if ((int *)DAT_00fb7474[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x75) == '\0') {
      uVar4 = FUN_004f8c20();
      DAT_00fb7474[2] = uVar4;
    }
    else {
      DAT_00fb7474[2] = piVar6;
    }
  }
  if ((char)param_2[0x1d] == '\x01') {
    if (piVar7 != (int *)DAT_00fb7474[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x1d] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x1d] == '\0') {
            *(undefined1 *)(piVar6 + 0x1d) = 1;
            *(undefined1 *)(piVar5 + 0x1d) = 0;
            FUN_004f8b60(&DAT_00fb7470);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x75) == '\0') {
            if ((*(char *)(*piVar6 + 0x74) != '\x01') || (*(char *)(piVar6[2] + 0x74) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x74) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x74) = 1;
                *(undefined1 *)(piVar6 + 0x1d) = 0;
                FUN_004f8bc0(&DAT_00fb7470);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x1d) = (char)piVar5[0x1d];
              *(undefined1 *)(piVar5 + 0x1d) = 1;
              *(undefined1 *)(piVar6[2] + 0x74) = 1;
              FUN_004f8b60(&DAT_00fb7470);
              break;
            }
LAB_004f84a7:
            *(undefined1 *)(piVar6 + 0x1d) = 0;
          }
        }
        else {
          if ((char)piVar6[0x1d] == '\0') {
            *(undefined1 *)(piVar6 + 0x1d) = 1;
            *(undefined1 *)(piVar5 + 0x1d) = 0;
            FUN_004f8bc0(&DAT_00fb7470);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x75) == '\0') {
            if ((*(char *)(piVar6[2] + 0x74) == '\x01') && (*(char *)(*piVar6 + 0x74) == '\x01'))
            goto LAB_004f84a7;
            if (*(char *)(*piVar6 + 0x74) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x74) = 1;
              *(undefined1 *)(piVar6 + 0x1d) = 0;
              FUN_004f8b60(&DAT_00fb7470);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x1d) = (char)piVar5[0x1d];
            *(undefined1 *)(piVar5 + 0x1d) = 1;
            *(undefined1 *)(*piVar6 + 0x74) = 1;
            FUN_004f8bc0(&DAT_00fb7470);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fb7474[1]);
    }
    *(undefined1 *)(piVar7 + 0x1d) = 1;
  }
  FUN_004f52b0();
  FUN_0089120c(param_2);
  if (DAT_00fb7478 != 0) {
    DAT_00fb7478 = DAT_00fb7478 + -1;
  }
  *param_1 = param_2;
  return;
}

