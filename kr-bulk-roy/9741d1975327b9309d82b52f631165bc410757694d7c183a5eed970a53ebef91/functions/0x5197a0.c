
/* WARNING: Removing unreachable block (ram,0x00519868) */
/* WARNING: Removing unreachable block (ram,0x00519878) */
/* WARNING: Removing unreachable block (ram,0x00519881) */
/* WARNING: Removing unreachable block (ram,0x00519884) */
/* WARNING: Removing unreachable block (ram,0x00519874) */
/* WARNING: Removing unreachable block (ram,0x00519892) */
/* WARNING: Removing unreachable block (ram,0x005198a2) */
/* WARNING: Removing unreachable block (ram,0x005198ad) */
/* WARNING: Removing unreachable block (ram,0x005198a9) */
/* WARNING: Removing unreachable block (ram,0x0051989d) */
/* WARNING: Removing unreachable block (ram,0x005198b0) */

void FUN_005197a0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x39) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0052d260();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x39) == '\0') {
    if (*(char *)(param_2[2] + 0x39) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x39) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fe1de8[1] == param_2) {
    DAT_00fe1de8[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fe1de8 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x39) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x39);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x39);
        piVar5 = piVar3;
      }
    }
    *DAT_00fe1de8 = piVar5;
  }
  if ((int *)DAT_00fe1de8[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x39) == '\0') {
      uVar4 = FUN_00832a00();
      DAT_00fe1de8[2] = uVar4;
    }
    else {
      DAT_00fe1de8[2] = piVar6;
    }
  }
  if ((char)param_2[0xe] == '\x01') {
    if (piVar7 != (int *)DAT_00fe1de8[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0xe] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0xe] == '\0') {
            *(undefined1 *)(piVar6 + 0xe) = 1;
            *(undefined1 *)(piVar5 + 0xe) = 0;
            FUN_007c0990(&DAT_00fe1de4);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x39) == '\0') {
            if ((*(char *)(*piVar6 + 0x38) != '\x01') || (*(char *)(piVar6[2] + 0x38) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x38) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x38) = 1;
                *(undefined1 *)(piVar6 + 0xe) = 0;
                FUN_0081f6c0(&DAT_00fe1de4);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0xe) = (char)piVar5[0xe];
              *(undefined1 *)(piVar5 + 0xe) = 1;
              *(undefined1 *)(piVar6[2] + 0x38) = 1;
              FUN_007c0990(&DAT_00fe1de4);
              break;
            }
LAB_00519997:
            *(undefined1 *)(piVar6 + 0xe) = 0;
          }
        }
        else {
          if ((char)piVar6[0xe] == '\0') {
            *(undefined1 *)(piVar6 + 0xe) = 1;
            *(undefined1 *)(piVar5 + 0xe) = 0;
            FUN_0081f6c0(&DAT_00fe1de4);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x39) == '\0') {
            if ((*(char *)(piVar6[2] + 0x38) == '\x01') && (*(char *)(*piVar6 + 0x38) == '\x01'))
            goto LAB_00519997;
            if (*(char *)(*piVar6 + 0x38) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x38) = 1;
              *(undefined1 *)(piVar6 + 0xe) = 0;
              FUN_007c0990(&DAT_00fe1de4);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0xe) = (char)piVar5[0xe];
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(*piVar6 + 0x38) = 1;
            FUN_0081f6c0(&DAT_00fe1de4);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fe1de8[1]);
    }
    *(undefined1 *)(piVar7 + 0xe) = 1;
  }
  if (param_2[10] != 0) {
    FUN_0089120c(param_2[10]);
  }
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  FUN_0089120c(param_2);
  if (DAT_00fe1dec != 0) {
    DAT_00fe1dec = DAT_00fe1dec + -1;
  }
  *param_1 = param_2;
  return;
}

