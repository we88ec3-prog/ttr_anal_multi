
/* WARNING: Removing unreachable block (ram,0x0081f448) */
/* WARNING: Removing unreachable block (ram,0x0081f458) */
/* WARNING: Removing unreachable block (ram,0x0081f461) */
/* WARNING: Removing unreachable block (ram,0x0081f464) */
/* WARNING: Removing unreachable block (ram,0x0081f454) */
/* WARNING: Removing unreachable block (ram,0x0081f472) */
/* WARNING: Removing unreachable block (ram,0x0081f482) */
/* WARNING: Removing unreachable block (ram,0x0081f48d) */
/* WARNING: Removing unreachable block (ram,0x0081f489) */
/* WARNING: Removing unreachable block (ram,0x0081f47d) */
/* WARNING: Removing unreachable block (ram,0x0081f490) */

void FUN_0081f380(undefined4 *param_1,int *param_2)

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
  if ((int *)DAT_00fb7a10[1] == param_2) {
    DAT_00fb7a10[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fb7a10 == param_2) {
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
    *DAT_00fb7a10 = piVar5;
  }
  if ((int *)DAT_00fb7a10[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x39) == '\0') {
      uVar4 = FUN_00832a00();
      DAT_00fb7a10[2] = uVar4;
    }
    else {
      DAT_00fb7a10[2] = piVar6;
    }
  }
  if ((char)param_2[0xe] == '\x01') {
    if (piVar7 != (int *)DAT_00fb7a10[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0xe] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0xe] == '\0') {
            *(undefined1 *)(piVar6 + 0xe) = 1;
            *(undefined1 *)(piVar5 + 0xe) = 0;
            FUN_007c0990(&DAT_00fb7a0c);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x39) == '\0') {
            if ((*(char *)(*piVar6 + 0x38) != '\x01') || (*(char *)(piVar6[2] + 0x38) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x38) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x38) = 1;
                *(undefined1 *)(piVar6 + 0xe) = 0;
                FUN_0081f6c0(&DAT_00fb7a0c);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0xe) = (char)piVar5[0xe];
              *(undefined1 *)(piVar5 + 0xe) = 1;
              *(undefined1 *)(piVar6[2] + 0x38) = 1;
              FUN_007c0990(&DAT_00fb7a0c);
              break;
            }
LAB_0081f576:
            *(undefined1 *)(piVar6 + 0xe) = 0;
          }
        }
        else {
          if ((char)piVar6[0xe] == '\0') {
            *(undefined1 *)(piVar6 + 0xe) = 1;
            *(undefined1 *)(piVar5 + 0xe) = 0;
            FUN_0081f6c0(&DAT_00fb7a0c);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x39) == '\0') {
            if ((*(char *)(piVar6[2] + 0x38) == '\x01') && (*(char *)(*piVar6 + 0x38) == '\x01'))
            goto LAB_0081f576;
            if (*(char *)(*piVar6 + 0x38) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x38) = 1;
              *(undefined1 *)(piVar6 + 0xe) = 0;
              FUN_007c0990(&DAT_00fb7a0c);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0xe) = (char)piVar5[0xe];
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(*piVar6 + 0x38) = 1;
            FUN_0081f6c0(&DAT_00fb7a0c);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fb7a10[1]);
    }
    *(undefined1 *)(piVar7 + 0xe) = 1;
  }
  if (7 < (uint)param_2[0xc]) {
    FUN_0089120c(param_2[7]);
  }
  param_2[0xc] = 7;
  param_2[0xb] = 0;
  *(undefined2 *)(param_2 + 7) = 0;
  FUN_0089120c(param_2);
  if (DAT_00fb7a14 != 0) {
    DAT_00fb7a14 = DAT_00fb7a14 + -1;
  }
  *param_1 = param_2;
  return;
}

