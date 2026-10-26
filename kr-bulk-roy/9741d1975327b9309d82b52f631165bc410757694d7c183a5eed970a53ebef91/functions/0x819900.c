
/* WARNING: Removing unreachable block (ram,0x008199e8) */
/* WARNING: Removing unreachable block (ram,0x008199f8) */
/* WARNING: Removing unreachable block (ram,0x00819a01) */
/* WARNING: Removing unreachable block (ram,0x00819a04) */
/* WARNING: Removing unreachable block (ram,0x008199f4) */
/* WARNING: Removing unreachable block (ram,0x00819a12) */
/* WARNING: Removing unreachable block (ram,0x00819a22) */
/* WARNING: Removing unreachable block (ram,0x00819a2d) */
/* WARNING: Removing unreachable block (ram,0x00819a29) */
/* WARNING: Removing unreachable block (ram,0x00819a1d) */
/* WARNING: Removing unreachable block (ram,0x00819a30) */

void FUN_00819900(undefined4 *param_1,int *param_2)

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
  puStack_c = &LAB_0090b5d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_2 + 0x21) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0085e240(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fab280[1] == param_2) {
    DAT_00fab280[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fab280 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x21);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x21);
        piVar5 = piVar3;
      }
    }
    *DAT_00fab280 = piVar5;
  }
  if ((int *)DAT_00fab280[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      uVar4 = FUN_00852270();
      DAT_00fab280[2] = uVar4;
    }
    else {
      DAT_00fab280[2] = piVar6;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar7 != (int *)DAT_00fab280[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[8] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar5 + 8) = 0;
            FUN_00405150(&DAT_00fab27c);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(*piVar6 + 0x20) != '\x01') || (*(char *)(piVar6[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x20) = 1;
                *(undefined1 *)(piVar6 + 8) = 0;
                FUN_00819bd0(&DAT_00fab27c);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 8) = (char)piVar5[8];
              *(undefined1 *)(piVar5 + 8) = 1;
              *(undefined1 *)(piVar6[2] + 0x20) = 1;
              FUN_00405150(&DAT_00fab27c);
              break;
            }
LAB_00819b17:
            *(undefined1 *)(piVar6 + 8) = 0;
          }
        }
        else {
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar5 + 8) = 0;
            FUN_00819bd0(&DAT_00fab27c);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(piVar6[2] + 0x20) == '\x01') && (*(char *)(*piVar6 + 0x20) == '\x01'))
            goto LAB_00819b17;
            if (*(char *)(*piVar6 + 0x20) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x20) = 1;
              *(undefined1 *)(piVar6 + 8) = 0;
              FUN_00405150(&DAT_00fab27c);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 8) = (char)piVar5[8];
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(*piVar6 + 0x20) = 1;
            FUN_00819bd0(&DAT_00fab27c);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fab280[1]);
    }
    *(undefined1 *)(piVar7 + 8) = 1;
  }
  local_8 = 0;
  FUN_00535ac0(*(undefined4 *)param_2[5],(undefined4 *)param_2[5]);
  FUN_0089120c(param_2[5]);
  FUN_0089120c(param_2);
  if (DAT_00fab284 != 0) {
    DAT_00fab284 = DAT_00fab284 + -1;
  }
  *param_1 = param_2;
  ExceptionList = local_10;
  return;
}

