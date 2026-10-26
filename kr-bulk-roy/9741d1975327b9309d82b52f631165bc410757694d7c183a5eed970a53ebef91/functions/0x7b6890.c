
/* WARNING: Removing unreachable block (ram,0x007b6959) */
/* WARNING: Removing unreachable block (ram,0x007b6969) */
/* WARNING: Removing unreachable block (ram,0x007b6972) */
/* WARNING: Removing unreachable block (ram,0x007b6975) */
/* WARNING: Removing unreachable block (ram,0x007b6965) */
/* WARNING: Removing unreachable block (ram,0x007b6983) */
/* WARNING: Removing unreachable block (ram,0x007b6993) */
/* WARNING: Removing unreachable block (ram,0x007b699e) */
/* WARNING: Removing unreachable block (ram,0x007b699a) */
/* WARNING: Removing unreachable block (ram,0x007b698e) */
/* WARNING: Removing unreachable block (ram,0x007b69a1) */

void FUN_007b6890(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_3 + 0x15) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0049e6a0();
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x15) == '\0') {
    if (*(char *)(param_3[2] + 0x15) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x15) == '\0') {
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
    if (*(char *)((int)piVar8 + 0x15) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x15);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x15);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x15) == '\0') {
      uVar5 = FUN_00823b80();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[5] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[5] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[5] == '\0') {
            *(undefined1 *)(piVar7 + 5) = 1;
            *(undefined1 *)(piVar6 + 5) = 0;
            FUN_00763f60(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x15) == '\0') {
            if ((*(char *)(*piVar7 + 0x14) != '\x01') || (*(char *)(piVar7[2] + 0x14) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x14) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x14) = 1;
                *(undefined1 *)(piVar7 + 5) = 0;
                FUN_0043e670(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 5) = (char)piVar6[5];
              *(undefined1 *)(piVar6 + 5) = 1;
              *(undefined1 *)(piVar7[2] + 0x14) = 1;
              FUN_00763f60(param_1);
              break;
            }
LAB_007b6a77:
            *(undefined1 *)(piVar7 + 5) = 0;
          }
        }
        else {
          if ((char)piVar7[5] == '\0') {
            *(undefined1 *)(piVar7 + 5) = 1;
            *(undefined1 *)(piVar6 + 5) = 0;
            FUN_0043e670(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x15) == '\0') {
            if ((*(char *)(piVar7[2] + 0x14) == '\x01') && (*(char *)(*piVar7 + 0x14) == '\x01'))
            goto LAB_007b6a77;
            if (*(char *)(*piVar7 + 0x14) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x14) = 1;
              *(undefined1 *)(piVar7 + 5) = 0;
              FUN_00763f60(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 5) = (char)piVar6[5];
            *(undefined1 *)(piVar6 + 5) = 1;
            *(undefined1 *)(*piVar7 + 0x14) = 1;
            FUN_0043e670(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 5) = 1;
  }
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

