
/* WARNING: Removing unreachable block (ram,0x0073ed89) */
/* WARNING: Removing unreachable block (ram,0x0073ed99) */
/* WARNING: Removing unreachable block (ram,0x0073eda2) */
/* WARNING: Removing unreachable block (ram,0x0073eda5) */
/* WARNING: Removing unreachable block (ram,0x0073ed95) */
/* WARNING: Removing unreachable block (ram,0x0073edb3) */
/* WARNING: Removing unreachable block (ram,0x0073edc3) */
/* WARNING: Removing unreachable block (ram,0x0073edce) */
/* WARNING: Removing unreachable block (ram,0x0073edca) */
/* WARNING: Removing unreachable block (ram,0x0073edbe) */
/* WARNING: Removing unreachable block (ram,0x0073edd1) */

void FUN_0073eca0(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined1 local_20 [4];
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ca10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_3 + 0x39) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  local_14 = param_3;
  FUN_0052d260(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar7 = (int *)*param_3;
  if (*(char *)((int)piVar7 + 0x39) == '\0') {
    if (*(char *)(param_3[2] + 0x39) == '\0') {
      piVar7 = (int *)param_3[2];
    }
  }
  else {
    piVar7 = (int *)param_3[2];
  }
  piVar6 = (int *)param_3[1];
  if (*(char *)((int)piVar7 + 0x39) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar7;
  }
  else if ((int *)*piVar6 == param_3) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
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
    **(undefined4 **)(param_1 + 4) = piVar5;
  }
  local_18 = *(int **)(param_1 + 4);
  if (*(int **)((int)local_18 + 8) == param_3) {
    if (*(char *)((int)piVar7 + 0x39) == '\0') {
      uVar4 = FUN_00832a00();
      *(undefined4 *)((int)local_18 + 8) = uVar4;
    }
    else {
      *(int **)((int)local_18 + 8) = piVar6;
    }
  }
  if ((char)local_14[0xe] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0xe] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0xe] == '\0') {
            *(undefined1 *)(piVar6 + 0xe) = 1;
            *(undefined1 *)(piVar5 + 0xe) = 0;
            FUN_007c0990(param_1);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x39) == '\0') {
            if ((*(char *)(*piVar6 + 0x38) != '\x01') || (*(char *)(piVar6[2] + 0x38) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x38) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x38) = 1;
                *(undefined1 *)(piVar6 + 0xe) = 0;
                FUN_0081f6c0(param_1);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0xe) = (char)piVar5[0xe];
              *(undefined1 *)(piVar5 + 0xe) = 1;
              *(undefined1 *)(piVar6[2] + 0x38) = 1;
              FUN_007c0990(param_1);
              break;
            }
LAB_0073eea7:
            *(undefined1 *)(piVar6 + 0xe) = 0;
          }
        }
        else {
          if ((char)piVar6[0xe] == '\0') {
            *(undefined1 *)(piVar6 + 0xe) = 1;
            *(undefined1 *)(piVar5 + 0xe) = 0;
            FUN_0081f6c0(param_1);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x39) == '\0') {
            if ((*(char *)(piVar6[2] + 0x38) == '\x01') && (*(char *)(*piVar6 + 0x38) == '\x01'))
            goto LAB_0073eea7;
            if (*(char *)(*piVar6 + 0x38) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x38) = 1;
              *(undefined1 *)(piVar6 + 0xe) = 0;
              FUN_007c0990(param_1);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0xe) = (char)piVar5[0xe];
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(*piVar6 + 0x38) = 1;
            FUN_0081f6c0(param_1);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 0xe) = 1;
  }
  piVar7 = local_14;
  piVar6 = local_14 + 3;
  local_1c = local_14 + 10;
  local_8 = 1;
  local_18 = piVar6;
  FUN_0073f170(local_20,*(undefined4 *)local_14[0xb],(undefined4 *)local_14[0xb]);
  FUN_0089120c(piVar7[0xb]);
  if (7 < (uint)piVar7[8]) {
    FUN_0089120c(*piVar6);
  }
  piVar7[8] = 7;
  piVar7[7] = 0;
  *(undefined2 *)piVar6 = 0;
  FUN_0089120c(local_14);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  ExceptionList = local_10;
  return;
}

