
/* WARNING: Removing unreachable block (ram,0x00516e09) */
/* WARNING: Removing unreachable block (ram,0x00516e19) */
/* WARNING: Removing unreachable block (ram,0x00516e22) */
/* WARNING: Removing unreachable block (ram,0x00516e25) */
/* WARNING: Removing unreachable block (ram,0x00516e15) */
/* WARNING: Removing unreachable block (ram,0x00516e33) */
/* WARNING: Removing unreachable block (ram,0x00516e43) */
/* WARNING: Removing unreachable block (ram,0x00516e4e) */
/* WARNING: Removing unreachable block (ram,0x00516e4a) */
/* WARNING: Removing unreachable block (ram,0x00516e3e) */
/* WARNING: Removing unreachable block (ram,0x00516e51) */

void FUN_00516d40(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_3 + 0x13) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_005176d0();
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x13) == '\0') {
    if (*(char *)(param_3[2] + 0x13) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x13) == '\0') {
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
    if (*(char *)((int)piVar8 + 0x13) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x13);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x13);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x13) == '\0') {
      uVar5 = FUN_004eed50();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if (*(char *)((int)param_3 + 0x12) == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if (*(char *)((int)piVar8 + 0x12) != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if (*(char *)((int)piVar7 + 0x12) == '\0') {
            *(undefined1 *)((int)piVar7 + 0x12) = 1;
            *(undefined1 *)((int)piVar6 + 0x12) = 0;
            FUN_004eece0(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x13) == '\0') {
            if ((*(char *)(*piVar7 + 0x12) != '\x01') || (*(char *)(piVar7[2] + 0x12) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x12) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x12) = 1;
                *(undefined1 *)((int)piVar7 + 0x12) = 0;
                FUN_00517440(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(undefined1 *)((int)piVar7 + 0x12) = *(undefined1 *)((int)piVar6 + 0x12);
              *(undefined1 *)((int)piVar6 + 0x12) = 1;
              *(undefined1 *)(piVar7[2] + 0x12) = 1;
              FUN_004eece0(param_1);
              break;
            }
LAB_00516f27:
            *(undefined1 *)((int)piVar7 + 0x12) = 0;
          }
        }
        else {
          if (*(char *)((int)piVar7 + 0x12) == '\0') {
            *(undefined1 *)((int)piVar7 + 0x12) = 1;
            *(undefined1 *)((int)piVar6 + 0x12) = 0;
            FUN_00517440(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x13) == '\0') {
            if ((*(char *)(piVar7[2] + 0x12) == '\x01') && (*(char *)(*piVar7 + 0x12) == '\x01'))
            goto LAB_00516f27;
            if (*(char *)(*piVar7 + 0x12) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x12) = 1;
              *(undefined1 *)((int)piVar7 + 0x12) = 0;
              FUN_004eece0(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(undefined1 *)((int)piVar7 + 0x12) = *(undefined1 *)((int)piVar6 + 0x12);
            *(undefined1 *)((int)piVar6 + 0x12) = 1;
            *(undefined1 *)(*piVar7 + 0x12) = 1;
            FUN_00517440(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)((int)piVar8 + 0x12) = 1;
  }
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

