
/* WARNING: Removing unreachable block (ram,0x00462348) */
/* WARNING: Removing unreachable block (ram,0x00462358) */
/* WARNING: Removing unreachable block (ram,0x00462361) */
/* WARNING: Removing unreachable block (ram,0x00462364) */
/* WARNING: Removing unreachable block (ram,0x00462354) */
/* WARNING: Removing unreachable block (ram,0x00462372) */
/* WARNING: Removing unreachable block (ram,0x00462382) */
/* WARNING: Removing unreachable block (ram,0x0046238d) */
/* WARNING: Removing unreachable block (ram,0x00462389) */
/* WARNING: Removing unreachable block (ram,0x0046237d) */
/* WARNING: Removing unreachable block (ram,0x00462390) */

void FUN_00462280(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x7d) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00401460();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x7d) == '\0') {
    if (*(char *)(param_2[2] + 0x7d) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x7d) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fc0d4c[1] == param_2) {
    DAT_00fc0d4c[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fc0d4c == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x7d) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x7d);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x7d);
        piVar5 = piVar3;
      }
    }
    *DAT_00fc0d4c = piVar5;
  }
  if ((int *)DAT_00fc0d4c[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x7d) == '\0') {
      uVar4 = FUN_00401a90();
      DAT_00fc0d4c[2] = uVar4;
    }
    else {
      DAT_00fc0d4c[2] = piVar6;
    }
  }
  if ((char)param_2[0x1f] == '\x01') {
    if (piVar7 != (int *)DAT_00fc0d4c[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x1f] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x1f] == '\0') {
            *(undefined1 *)(piVar6 + 0x1f) = 1;
            *(undefined1 *)(piVar5 + 0x1f) = 0;
            FUN_004019f0();
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x7d) == '\0') {
            if ((*(char *)(*piVar6 + 0x7c) != '\x01') || (*(char *)(piVar6[2] + 0x7c) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x7c) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x7c) = 1;
                *(undefined1 *)(piVar6 + 0x1f) = 0;
                FUN_00401a40();
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x1f) = (char)piVar5[0x1f];
              *(undefined1 *)(piVar5 + 0x1f) = 1;
              *(undefined1 *)(piVar6[2] + 0x7c) = 1;
              FUN_004019f0();
              break;
            }
LAB_0046245c:
            *(undefined1 *)(piVar6 + 0x1f) = 0;
          }
        }
        else {
          if ((char)piVar6[0x1f] == '\0') {
            *(undefined1 *)(piVar6 + 0x1f) = 1;
            *(undefined1 *)(piVar5 + 0x1f) = 0;
            FUN_00401a40();
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x7d) == '\0') {
            if ((*(char *)(piVar6[2] + 0x7c) == '\x01') && (*(char *)(*piVar6 + 0x7c) == '\x01'))
            goto LAB_0046245c;
            if (*(char *)(*piVar6 + 0x7c) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x7c) = 1;
              *(undefined1 *)(piVar6 + 0x1f) = 0;
              FUN_004019f0();
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x1f) = (char)piVar5[0x1f];
            *(undefined1 *)(piVar5 + 0x1f) = 1;
            *(undefined1 *)(*piVar6 + 0x7c) = 1;
            FUN_00401a40();
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fc0d4c[1]);
    }
    *(undefined1 *)(piVar7 + 0x1f) = 1;
  }
  FUN_004012f0(param_2 + 4);
  FUN_0089120c(param_2);
  if (DAT_00fc0d50 != 0) {
    DAT_00fc0d50 = DAT_00fc0d50 + -1;
  }
  *param_1 = param_2;
  return;
}

