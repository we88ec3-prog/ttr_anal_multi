
/* WARNING: Removing unreachable block (ram,0x0081d138) */
/* WARNING: Removing unreachable block (ram,0x0081d148) */
/* WARNING: Removing unreachable block (ram,0x0081d151) */
/* WARNING: Removing unreachable block (ram,0x0081d154) */
/* WARNING: Removing unreachable block (ram,0x0081d144) */
/* WARNING: Removing unreachable block (ram,0x0081d162) */
/* WARNING: Removing unreachable block (ram,0x0081d172) */
/* WARNING: Removing unreachable block (ram,0x0081d17d) */
/* WARNING: Removing unreachable block (ram,0x0081d179) */
/* WARNING: Removing unreachable block (ram,0x0081d16d) */
/* WARNING: Removing unreachable block (ram,0x0081d180) */

void FUN_0081d050(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911603;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_2 + 0x41) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0047bf70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x41) == '\0') {
    if (*(char *)(param_2[2] + 0x41) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x41) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fb732c[1] == param_2) {
    DAT_00fb732c[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fb732c == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x41) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x41);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x41);
        piVar5 = piVar3;
      }
    }
    *DAT_00fb732c = piVar5;
  }
  if ((int *)DAT_00fb732c[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x41) == '\0') {
      uVar4 = FUN_0081d7d0();
      DAT_00fb732c[2] = uVar4;
    }
    else {
      DAT_00fb732c[2] = piVar6;
    }
  }
  if ((char)param_2[0x10] == '\x01') {
    if (piVar7 != (int *)DAT_00fb732c[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x10] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x10] == '\0') {
            *(undefined1 *)(piVar6 + 0x10) = 1;
            *(undefined1 *)(piVar5 + 0x10) = 0;
            FUN_0085f130(&DAT_00fb7328);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x41) == '\0') {
            if ((*(char *)(*piVar6 + 0x40) != '\x01') || (*(char *)(piVar6[2] + 0x40) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x40) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x40) = 1;
                *(undefined1 *)(piVar6 + 0x10) = 0;
                FUN_0081d770(&DAT_00fb7328);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x10) = (char)piVar5[0x10];
              *(undefined1 *)(piVar5 + 0x10) = 1;
              *(undefined1 *)(piVar6[2] + 0x40) = 1;
              FUN_0085f130(&DAT_00fb7328);
              break;
            }
LAB_0081d270:
            *(undefined1 *)(piVar6 + 0x10) = 0;
          }
        }
        else {
          if ((char)piVar6[0x10] == '\0') {
            *(undefined1 *)(piVar6 + 0x10) = 1;
            *(undefined1 *)(piVar5 + 0x10) = 0;
            FUN_0081d770(&DAT_00fb7328);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x41) == '\0') {
            if ((*(char *)(piVar6[2] + 0x40) == '\x01') && (*(char *)(*piVar6 + 0x40) == '\x01'))
            goto LAB_0081d270;
            if (*(char *)(*piVar6 + 0x40) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x40) = 1;
              *(undefined1 *)(piVar6 + 0x10) = 0;
              FUN_0085f130(&DAT_00fb7328);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x10) = (char)piVar5[0x10];
            *(undefined1 *)(piVar5 + 0x10) = 1;
            *(undefined1 *)(*piVar6 + 0x40) = 1;
            FUN_0081d770(&DAT_00fb7328);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fb732c[1]);
    }
    *(undefined1 *)(piVar7 + 0x10) = 1;
  }
  local_8 = 1;
  FUN_0081cbb0(*(undefined4 *)param_2[0xd],(undefined4 *)param_2[0xd]);
  FUN_0089120c(param_2[0xd]);
  if (7 < (uint)param_2[10]) {
    FUN_0089120c(param_2[5]);
  }
  param_2[10] = 7;
  param_2[9] = 0;
  *(undefined2 *)(param_2 + 5) = 0;
  FUN_0089120c(param_2);
  if (DAT_00fb7330 != 0) {
    DAT_00fb7330 = DAT_00fb7330 + -1;
  }
  *param_1 = param_2;
  ExceptionList = local_10;
  return;
}

