
/* WARNING: Removing unreachable block (ram,0x005707f9) */
/* WARNING: Removing unreachable block (ram,0x00570809) */
/* WARNING: Removing unreachable block (ram,0x00570812) */
/* WARNING: Removing unreachable block (ram,0x00570815) */
/* WARNING: Removing unreachable block (ram,0x00570805) */
/* WARNING: Removing unreachable block (ram,0x00570823) */
/* WARNING: Removing unreachable block (ram,0x00570833) */
/* WARNING: Removing unreachable block (ram,0x0057083e) */
/* WARNING: Removing unreachable block (ram,0x0057083a) */
/* WARNING: Removing unreachable block (ram,0x0057082e) */
/* WARNING: Removing unreachable block (ram,0x00570841) */

void FUN_00570710(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool bVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090acf0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_3 + 0x41) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0047bf70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x41) == '\0') {
    if (*(char *)(param_3[2] + 0x41) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x41) == '\0') {
    piVar6[1] = (int)piVar7;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar7 == param_3) {
    *piVar7 = (int)piVar6;
  }
  else {
    piVar7[2] = (int)piVar6;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar5 = piVar7;
    if (*(char *)((int)piVar6 + 0x41) == '\0') {
      cVar1 = *(char *)(*piVar6 + 0x41);
      piVar2 = (int *)*piVar6;
      piVar5 = piVar6;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x41);
        piVar5 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x41) == '\0') {
      uVar4 = FUN_0081d7d0();
      *(undefined4 *)(*(int *)(param_1 + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar7;
    }
  }
  if ((char)param_3[0x10] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        if ((char)piVar6[0x10] != '\x01') break;
        piVar5 = (int *)*piVar7;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar7[2];
          if ((char)piVar5[0x10] == '\0') {
            *(undefined1 *)(piVar5 + 0x10) = 1;
            *(undefined1 *)(piVar7 + 0x10) = 0;
            FUN_0085f130(param_1);
            piVar5 = (int *)piVar7[2];
          }
          if (*(char *)((int)piVar5 + 0x41) == '\0') {
            if ((*(char *)(*piVar5 + 0x40) != '\x01') || (*(char *)(piVar5[2] + 0x40) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x40) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x40) = 1;
                *(undefined1 *)(piVar5 + 0x10) = 0;
                FUN_0081d770(param_1);
                piVar5 = (int *)piVar7[2];
              }
              *(char *)(piVar5 + 0x10) = (char)piVar7[0x10];
              *(undefined1 *)(piVar7 + 0x10) = 1;
              *(undefined1 *)(piVar5[2] + 0x40) = 1;
              FUN_0085f130(param_1);
              break;
            }
LAB_00570926:
            *(undefined1 *)(piVar5 + 0x10) = 0;
          }
        }
        else {
          if ((char)piVar5[0x10] == '\0') {
            *(undefined1 *)(piVar5 + 0x10) = 1;
            *(undefined1 *)(piVar7 + 0x10) = 0;
            FUN_0081d770(param_1);
            piVar5 = (int *)*piVar7;
          }
          if (*(char *)((int)piVar5 + 0x41) == '\0') {
            if ((*(char *)(piVar5[2] + 0x40) == '\x01') && (*(char *)(*piVar5 + 0x40) == '\x01'))
            goto LAB_00570926;
            if (*(char *)(*piVar5 + 0x40) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x40) = 1;
              *(undefined1 *)(piVar5 + 0x10) = 0;
              FUN_0085f130(param_1);
              piVar5 = (int *)*piVar7;
            }
            *(char *)(piVar5 + 0x10) = (char)piVar7[0x10];
            *(undefined1 *)(piVar7 + 0x10) = 1;
            *(undefined1 *)(*piVar5 + 0x40) = 1;
            FUN_0081d770(param_1);
            break;
          }
        }
        bVar8 = piVar7 != *(int **)(*(int *)(param_1 + 4) + 4);
        piVar6 = piVar7;
        piVar7 = (int *)piVar7[1];
      } while (bVar8);
    }
    *(undefined1 *)(piVar6 + 0x10) = 1;
  }
  local_8 = 1;
  FUN_005540c0(*(undefined4 *)param_3[0xd],(undefined4 *)param_3[0xd]);
  FUN_0089120c(param_3[0xd]);
  if (0xf < (uint)param_3[9]) {
    FUN_0089120c(param_3[4]);
  }
  param_3[9] = 0xf;
  param_3[8] = 0;
  *(undefined1 *)(param_3 + 4) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  ExceptionList = local_10;
  return;
}

