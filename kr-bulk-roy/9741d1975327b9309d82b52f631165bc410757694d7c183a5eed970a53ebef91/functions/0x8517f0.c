
/* WARNING: Removing unreachable block (ram,0x008518d9) */
/* WARNING: Removing unreachable block (ram,0x008518e9) */
/* WARNING: Removing unreachable block (ram,0x008518f2) */
/* WARNING: Removing unreachable block (ram,0x008518f5) */
/* WARNING: Removing unreachable block (ram,0x008518e5) */
/* WARNING: Removing unreachable block (ram,0x00851903) */
/* WARNING: Removing unreachable block (ram,0x00851913) */
/* WARNING: Removing unreachable block (ram,0x0085191e) */
/* WARNING: Removing unreachable block (ram,0x0085191a) */
/* WARNING: Removing unreachable block (ram,0x0085190e) */
/* WARNING: Removing unreachable block (ram,0x00851921) */

void FUN_008517f0(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b5d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_3 + 0x21) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0085e240(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x21) == '\0') {
    if (*(char *)(param_3[2] + 0x21) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x21) == '\0') {
    piVar8[1] = (int)piVar7;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar8;
  }
  else if ((int *)*piVar7 == param_3) {
    *piVar7 = (int)piVar8;
  }
  else {
    piVar7[2] = (int)piVar8;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar6 = piVar7;
    if (*(char *)((int)piVar8 + 0x21) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x21);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x21);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x21) == '\0') {
      uVar5 = FUN_00852270();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[8] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[8] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[8] == '\0') {
            *(undefined1 *)(piVar7 + 8) = 1;
            *(undefined1 *)(piVar6 + 8) = 0;
            FUN_00405150(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x21) == '\0') {
            if ((*(char *)(*piVar7 + 0x20) != '\x01') || (*(char *)(piVar7[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x20) = 1;
                *(undefined1 *)(piVar7 + 8) = 0;
                FUN_00819bd0(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 8) = (char)piVar6[8];
              *(undefined1 *)(piVar6 + 8) = 1;
              *(undefined1 *)(piVar7[2] + 0x20) = 1;
              FUN_00405150(param_1);
              break;
            }
LAB_008519f7:
            *(undefined1 *)(piVar7 + 8) = 0;
          }
        }
        else {
          if ((char)piVar7[8] == '\0') {
            *(undefined1 *)(piVar7 + 8) = 1;
            *(undefined1 *)(piVar6 + 8) = 0;
            FUN_00819bd0(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x21) == '\0') {
            if ((*(char *)(piVar7[2] + 0x20) == '\x01') && (*(char *)(*piVar7 + 0x20) == '\x01'))
            goto LAB_008519f7;
            if (*(char *)(*piVar7 + 0x20) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x20) = 1;
              *(undefined1 *)(piVar7 + 8) = 0;
              FUN_00405150(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 8) = (char)piVar6[8];
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(*piVar7 + 0x20) = 1;
            FUN_00819bd0(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 8) = 1;
  }
  local_8 = 0;
  FUN_00850e70(*(undefined4 *)param_3[5],(undefined4 *)param_3[5]);
  FUN_0089120c(param_3[5]);
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  ExceptionList = local_10;
  return;
}

