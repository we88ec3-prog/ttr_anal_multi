
/* WARNING: Removing unreachable block (ram,0x0051f078) */
/* WARNING: Removing unreachable block (ram,0x0051f088) */
/* WARNING: Removing unreachable block (ram,0x0051f091) */
/* WARNING: Removing unreachable block (ram,0x0051f094) */
/* WARNING: Removing unreachable block (ram,0x0051f084) */
/* WARNING: Removing unreachable block (ram,0x0051f0a2) */
/* WARNING: Removing unreachable block (ram,0x0051f0b2) */
/* WARNING: Removing unreachable block (ram,0x0051f0bd) */
/* WARNING: Removing unreachable block (ram,0x0051f0b9) */
/* WARNING: Removing unreachable block (ram,0x0051f0ad) */
/* WARNING: Removing unreachable block (ram,0x0051f0c0) */

void FUN_0051efb0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x51) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0051f3c0();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x51) == '\0') {
    if (*(char *)(param_2[2] + 0x51) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x51) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fe1dd4[1] == param_2) {
    DAT_00fe1dd4[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fe1dd4 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x51) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x51);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x51);
        piVar5 = piVar3;
      }
    }
    *DAT_00fe1dd4 = piVar5;
  }
  if ((int *)DAT_00fe1dd4[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x51) == '\0') {
      uVar4 = FUN_00835380();
      DAT_00fe1dd4[2] = uVar4;
    }
    else {
      DAT_00fe1dd4[2] = piVar6;
    }
  }
  if ((char)param_2[0x14] == '\x01') {
    if (piVar7 != (int *)DAT_00fe1dd4[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x14] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x14] == '\0') {
            *(undefined1 *)(piVar6 + 0x14) = 1;
            *(undefined1 *)(piVar5 + 0x14) = 0;
            FUN_00835320(&DAT_00fe1dd0);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x51) == '\0') {
            if ((*(char *)(*piVar6 + 0x50) != '\x01') || (*(char *)(piVar6[2] + 0x50) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x50) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x50) = 1;
                *(undefined1 *)(piVar6 + 0x14) = 0;
                FUN_0051f360(&DAT_00fe1dd0);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x14) = (char)piVar5[0x14];
              *(undefined1 *)(piVar5 + 0x14) = 1;
              *(undefined1 *)(piVar6[2] + 0x50) = 1;
              FUN_00835320(&DAT_00fe1dd0);
              break;
            }
LAB_0051f1a7:
            *(undefined1 *)(piVar6 + 0x14) = 0;
          }
        }
        else {
          if ((char)piVar6[0x14] == '\0') {
            *(undefined1 *)(piVar6 + 0x14) = 1;
            *(undefined1 *)(piVar5 + 0x14) = 0;
            FUN_0051f360(&DAT_00fe1dd0);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x51) == '\0') {
            if ((*(char *)(piVar6[2] + 0x50) == '\x01') && (*(char *)(*piVar6 + 0x50) == '\x01'))
            goto LAB_0051f1a7;
            if (*(char *)(*piVar6 + 0x50) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x50) = 1;
              *(undefined1 *)(piVar6 + 0x14) = 0;
              FUN_00835320(&DAT_00fe1dd0);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x14) = (char)piVar5[0x14];
            *(undefined1 *)(piVar5 + 0x14) = 1;
            *(undefined1 *)(*piVar6 + 0x50) = 1;
            FUN_0051f360(&DAT_00fe1dd0);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fe1dd4[1]);
    }
    *(undefined1 *)(piVar7 + 0x14) = 1;
  }
  FUN_0051eb80();
  FUN_0089120c(param_2);
  if (DAT_00fe1dd8 != 0) {
    DAT_00fe1dd8 = DAT_00fe1dd8 + -1;
  }
  *param_1 = param_2;
  return;
}

