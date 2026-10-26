
/* WARNING: Removing unreachable block (ram,0x00505b3b) */
/* WARNING: Removing unreachable block (ram,0x00505b4b) */
/* WARNING: Removing unreachable block (ram,0x00505b57) */
/* WARNING: Removing unreachable block (ram,0x00505b5a) */
/* WARNING: Removing unreachable block (ram,0x00505b47) */
/* WARNING: Removing unreachable block (ram,0x00505b68) */
/* WARNING: Removing unreachable block (ram,0x00505b78) */
/* WARNING: Removing unreachable block (ram,0x00505b83) */
/* WARNING: Removing unreachable block (ram,0x00505b7f) */
/* WARNING: Removing unreachable block (ram,0x00505b73) */
/* WARNING: Removing unreachable block (ram,0x00505b86) */

void FUN_00505a60(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  
  if (*(char *)((int)param_3 + 0xb5) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00503da0();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0xb5) == '\0') {
    if (*(char *)(param_3[2] + 0xb5) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0xb5) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_3) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  if ((int *)*puVar1 == param_3) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar6 + 0xb5) == '\0') {
      piVar3 = (int *)FUN_00503e00();
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(int **)(iVar2 + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0xb5) == '\0') {
      uVar4 = FUN_00505e20();
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_3[0x2d] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x2d] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x2d] == '\0') {
            *(undefined1 *)(piVar5 + 0x2d) = 1;
            *(undefined1 *)(piVar3 + 0x2d) = 0;
            FUN_00505d60(param_1);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0xb5) == '\0') {
            if ((*(char *)(*piVar5 + 0xb4) != '\x01') || (*(char *)(piVar5[2] + 0xb4) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xb4) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xb4) = 1;
                *(undefined1 *)(piVar5 + 0x2d) = 0;
                FUN_00505dc0(param_1);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 0x2d) = (char)piVar3[0x2d];
              *(undefined1 *)(piVar3 + 0x2d) = 1;
              *(undefined1 *)(piVar5[2] + 0xb4) = 1;
              FUN_00505d60(param_1);
              break;
            }
LAB_00505cb6:
            *(undefined1 *)(piVar5 + 0x2d) = 0;
          }
        }
        else {
          if ((char)piVar5[0x2d] == '\0') {
            *(undefined1 *)(piVar5 + 0x2d) = 1;
            *(undefined1 *)(piVar3 + 0x2d) = 0;
            FUN_00505dc0(param_1);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0xb5) == '\0') {
            if ((*(char *)(piVar5[2] + 0xb4) == '\x01') && (*(char *)(*piVar5 + 0xb4) == '\x01'))
            goto LAB_00505cb6;
            if (*(char *)(*piVar5 + 0xb4) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xb4) = 1;
              *(undefined1 *)(piVar5 + 0x2d) = 0;
              FUN_00505d60(param_1);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 0x2d) = (char)piVar3[0x2d];
            *(undefined1 *)(piVar3 + 0x2d) = 1;
            *(undefined1 *)(*piVar5 + 0xb4) = 1;
            FUN_00505dc0(param_1);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x2d) = 1;
  }
  FUN_005045c0(param_3 + 4);
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

