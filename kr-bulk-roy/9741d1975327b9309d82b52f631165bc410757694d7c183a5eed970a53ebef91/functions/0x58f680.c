
/* WARNING: Removing unreachable block (ram,0x0058f769) */
/* WARNING: Removing unreachable block (ram,0x0058f779) */
/* WARNING: Removing unreachable block (ram,0x0058f782) */
/* WARNING: Removing unreachable block (ram,0x0058f785) */
/* WARNING: Removing unreachable block (ram,0x0058f775) */
/* WARNING: Removing unreachable block (ram,0x0058f793) */
/* WARNING: Removing unreachable block (ram,0x0058f7a3) */
/* WARNING: Removing unreachable block (ram,0x0058f7ae) */
/* WARNING: Removing unreachable block (ram,0x0058f7aa) */
/* WARNING: Removing unreachable block (ram,0x0058f79e) */
/* WARNING: Removing unreachable block (ram,0x0058f7b1) */

void FUN_0058f680(int param_1,undefined4 *param_2,int *param_3)

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
  puStack_c = &LAB_0090f950;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_3 + 0x3d) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00401410(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar7 = (int *)*param_3;
  if (*(char *)((int)piVar7 + 0x3d) == '\0') {
    if (*(char *)(param_3[2] + 0x3d) == '\0') {
      piVar7 = (int *)param_3[2];
    }
  }
  else {
    piVar7 = (int *)param_3[2];
  }
  piVar6 = (int *)param_3[1];
  if (*(char *)((int)piVar7 + 0x3d) == '\0') {
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
    if (*(char *)((int)piVar7 + 0x3d) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x3d);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x3d);
        piVar5 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar7 + 0x3d) == '\0') {
      uVar4 = FUN_0058f9e0();
      *(undefined4 *)(*(int *)(param_1 + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar6;
    }
  }
  if ((char)param_3[0xf] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0xf] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0xf] == '\0') {
            *(undefined1 *)(piVar6 + 0xf) = 1;
            *(undefined1 *)(piVar5 + 0xf) = 0;
            FUN_0058f980(param_1);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x3d) == '\0') {
            if ((*(char *)(*piVar6 + 0x3c) != '\x01') || (*(char *)(piVar6[2] + 0x3c) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x3c) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x3c) = 1;
                *(undefined1 *)(piVar6 + 0xf) = 0;
                FUN_00401ba0(param_1);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0xf) = (char)piVar5[0xf];
              *(undefined1 *)(piVar5 + 0xf) = 1;
              *(undefined1 *)(piVar6[2] + 0x3c) = 1;
              FUN_0058f980(param_1);
              break;
            }
LAB_0058f896:
            *(undefined1 *)(piVar6 + 0xf) = 0;
          }
        }
        else {
          if ((char)piVar6[0xf] == '\0') {
            *(undefined1 *)(piVar6 + 0xf) = 1;
            *(undefined1 *)(piVar5 + 0xf) = 0;
            FUN_00401ba0(param_1);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x3d) == '\0') {
            if ((*(char *)(piVar6[2] + 0x3c) == '\x01') && (*(char *)(*piVar6 + 0x3c) == '\x01'))
            goto LAB_0058f896;
            if (*(char *)(*piVar6 + 0x3c) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x3c) = 1;
              *(undefined1 *)(piVar6 + 0xf) = 0;
              FUN_0058f980(param_1);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0xf) = (char)piVar5[0xf];
            *(undefined1 *)(piVar5 + 0xf) = 1;
            *(undefined1 *)(*piVar6 + 0x3c) = 1;
            FUN_00401ba0(param_1);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 0xf) = 1;
  }
  param_3[10] = (int)FUI::FXUIAttributeHistory::vftable;
  local_8 = 1;
  FUN_0051af60(*(undefined4 *)param_3[0xc],(undefined4 *)param_3[0xc]);
  FUN_0089120c(param_3[0xc]);
  if (7 < (uint)param_3[8]) {
    FUN_0089120c(param_3[3]);
  }
  param_3[8] = 7;
  param_3[7] = 0;
  *(undefined2 *)(param_3 + 3) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  ExceptionList = local_10;
  return;
}

