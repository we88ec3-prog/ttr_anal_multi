
/* WARNING: Removing unreachable block (ram,0x005294b8) */
/* WARNING: Removing unreachable block (ram,0x005294c8) */
/* WARNING: Removing unreachable block (ram,0x005294d1) */
/* WARNING: Removing unreachable block (ram,0x005294d4) */
/* WARNING: Removing unreachable block (ram,0x005294c4) */
/* WARNING: Removing unreachable block (ram,0x005294e2) */
/* WARNING: Removing unreachable block (ram,0x005294f2) */
/* WARNING: Removing unreachable block (ram,0x005294fd) */
/* WARNING: Removing unreachable block (ram,0x005294f9) */
/* WARNING: Removing unreachable block (ram,0x005294ed) */
/* WARNING: Removing unreachable block (ram,0x00529500) */

void FUN_005293f0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x4d) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00466580();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x4d) == '\0') {
    if (*(char *)(param_2[2] + 0x4d) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x4d) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fab238[1] == param_2) {
    DAT_00fab238[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fab238 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x4d) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x4d);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x4d);
        piVar5 = piVar3;
      }
    }
    *DAT_00fab238 = piVar5;
  }
  if ((int *)DAT_00fab238[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x4d) == '\0') {
      uVar4 = FUN_00529850();
      DAT_00fab238[2] = uVar4;
    }
    else {
      DAT_00fab238[2] = piVar6;
    }
  }
  if ((char)param_2[0x13] == '\x01') {
    if (piVar7 != (int *)DAT_00fab238[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x13] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x13] == '\0') {
            *(undefined1 *)(piVar6 + 0x13) = 1;
            *(undefined1 *)(piVar5 + 0x13) = 0;
            FUN_00529790(&DAT_00fab234);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x4d) == '\0') {
            if ((*(char *)(*piVar6 + 0x4c) != '\x01') || (*(char *)(piVar6[2] + 0x4c) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x4c) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x4c) = 1;
                *(undefined1 *)(piVar6 + 0x13) = 0;
                FUN_005297f0(&DAT_00fab234);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x13) = (char)piVar5[0x13];
              *(undefined1 *)(piVar5 + 0x13) = 1;
              *(undefined1 *)(piVar6[2] + 0x4c) = 1;
              FUN_00529790(&DAT_00fab234);
              break;
            }
LAB_005295f0:
            *(undefined1 *)(piVar6 + 0x13) = 0;
          }
        }
        else {
          if ((char)piVar6[0x13] == '\0') {
            *(undefined1 *)(piVar6 + 0x13) = 1;
            *(undefined1 *)(piVar5 + 0x13) = 0;
            FUN_005297f0(&DAT_00fab234);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x4d) == '\0') {
            if ((*(char *)(piVar6[2] + 0x4c) == '\x01') && (*(char *)(*piVar6 + 0x4c) == '\x01'))
            goto LAB_005295f0;
            if (*(char *)(*piVar6 + 0x4c) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x4c) = 1;
              *(undefined1 *)(piVar6 + 0x13) = 0;
              FUN_00529790(&DAT_00fab234);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x13) = (char)piVar5[0x13];
            *(undefined1 *)(piVar5 + 0x13) = 1;
            *(undefined1 *)(*piVar6 + 0x4c) = 1;
            FUN_005297f0(&DAT_00fab234);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fab238[1]);
    }
    *(undefined1 *)(piVar7 + 0x13) = 1;
  }
  if (7 < (uint)param_2[0x11]) {
    FUN_0089120c(param_2[0xc]);
  }
  param_2[0x11] = 7;
  param_2[0x10] = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  if (7 < (uint)param_2[10]) {
    FUN_0089120c(param_2[5]);
  }
  param_2[10] = 7;
  param_2[9] = 0;
  *(undefined2 *)(param_2 + 5) = 0;
  FUN_0089120c(param_2);
  if (DAT_00fab23c != 0) {
    DAT_00fab23c = DAT_00fab23c + -1;
  }
  *param_1 = param_2;
  return;
}

