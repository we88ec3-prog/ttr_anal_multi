
/* WARNING: Removing unreachable block (ram,0x005115e8) */
/* WARNING: Removing unreachable block (ram,0x005115f8) */
/* WARNING: Removing unreachable block (ram,0x00511601) */
/* WARNING: Removing unreachable block (ram,0x00511604) */
/* WARNING: Removing unreachable block (ram,0x005115f4) */
/* WARNING: Removing unreachable block (ram,0x00511612) */
/* WARNING: Removing unreachable block (ram,0x00511622) */
/* WARNING: Removing unreachable block (ram,0x0051162d) */
/* WARNING: Removing unreachable block (ram,0x00511629) */
/* WARNING: Removing unreachable block (ram,0x0051161d) */
/* WARNING: Removing unreachable block (ram,0x00511630) */

void FUN_00511520(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x15) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0049e6a0();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x15) == '\0') {
    if (*(char *)(param_2[2] + 0x15) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x15) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fe3714[1] == param_2) {
    DAT_00fe3714[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fe3714 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x15) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x15);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x15);
        piVar5 = piVar3;
      }
    }
    *DAT_00fe3714 = piVar5;
  }
  if ((int *)DAT_00fe3714[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x15) == '\0') {
      uVar4 = FUN_00823b80();
      DAT_00fe3714[2] = uVar4;
    }
    else {
      DAT_00fe3714[2] = piVar6;
    }
  }
  if ((char)param_2[5] == '\x01') {
    if (piVar7 != (int *)DAT_00fe3714[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[5] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[5] == '\0') {
            *(undefined1 *)(piVar6 + 5) = 1;
            *(undefined1 *)(piVar5 + 5) = 0;
            FUN_005117e0();
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            if ((*(char *)(*piVar6 + 0x14) != '\x01') || (*(char *)(piVar6[2] + 0x14) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x14) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x14) = 1;
                *(undefined1 *)(piVar6 + 5) = 0;
                FUN_00511830();
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 5) = (char)piVar5[5];
              *(undefined1 *)(piVar5 + 5) = 1;
              *(undefined1 *)(piVar6[2] + 0x14) = 1;
              FUN_005117e0();
              break;
            }
LAB_005116fc:
            *(undefined1 *)(piVar6 + 5) = 0;
          }
        }
        else {
          if ((char)piVar6[5] == '\0') {
            *(undefined1 *)(piVar6 + 5) = 1;
            *(undefined1 *)(piVar5 + 5) = 0;
            FUN_00511830();
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            if ((*(char *)(piVar6[2] + 0x14) == '\x01') && (*(char *)(*piVar6 + 0x14) == '\x01'))
            goto LAB_005116fc;
            if (*(char *)(*piVar6 + 0x14) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x14) = 1;
              *(undefined1 *)(piVar6 + 5) = 0;
              FUN_005117e0();
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 5) = (char)piVar5[5];
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(*piVar6 + 0x14) = 1;
            FUN_00511830();
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fe3714[1]);
    }
    *(undefined1 *)(piVar7 + 5) = 1;
  }
  FUN_0089120c(param_2);
  if (DAT_00fe3718 != 0) {
    DAT_00fe3718 = DAT_00fe3718 + -1;
  }
  *param_1 = param_2;
  return;
}

