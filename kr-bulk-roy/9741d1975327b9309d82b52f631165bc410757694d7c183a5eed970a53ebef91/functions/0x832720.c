
/* WARNING: Removing unreachable block (ram,0x008327e9) */
/* WARNING: Removing unreachable block (ram,0x008327f9) */
/* WARNING: Removing unreachable block (ram,0x00832802) */
/* WARNING: Removing unreachable block (ram,0x00832805) */
/* WARNING: Removing unreachable block (ram,0x008327f5) */
/* WARNING: Removing unreachable block (ram,0x00832813) */
/* WARNING: Removing unreachable block (ram,0x00832823) */
/* WARNING: Removing unreachable block (ram,0x0083282e) */
/* WARNING: Removing unreachable block (ram,0x0083282a) */
/* WARNING: Removing unreachable block (ram,0x0083281e) */
/* WARNING: Removing unreachable block (ram,0x00832831) */

void FUN_00832720(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_3 + 0x39) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0052d260();
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x39) == '\0') {
    if (*(char *)(param_3[2] + 0x39) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x39) == '\0') {
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
    if (*(char *)((int)piVar8 + 0x39) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x39);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x39);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x39) == '\0') {
      uVar5 = FUN_00832a00();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[0xe] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[0xe] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[0xe] == '\0') {
            *(undefined1 *)(piVar7 + 0xe) = 1;
            *(undefined1 *)(piVar6 + 0xe) = 0;
            FUN_007c0990(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x39) == '\0') {
            if ((*(char *)(*piVar7 + 0x38) != '\x01') || (*(char *)(piVar7[2] + 0x38) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x38) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x38) = 1;
                *(undefined1 *)(piVar7 + 0xe) = 0;
                FUN_0081f6c0(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 0xe) = (char)piVar6[0xe];
              *(undefined1 *)(piVar6 + 0xe) = 1;
              *(undefined1 *)(piVar7[2] + 0x38) = 1;
              FUN_007c0990(param_1);
              break;
            }
LAB_00832907:
            *(undefined1 *)(piVar7 + 0xe) = 0;
          }
        }
        else {
          if ((char)piVar7[0xe] == '\0') {
            *(undefined1 *)(piVar7 + 0xe) = 1;
            *(undefined1 *)(piVar6 + 0xe) = 0;
            FUN_0081f6c0(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x39) == '\0') {
            if ((*(char *)(piVar7[2] + 0x38) == '\x01') && (*(char *)(*piVar7 + 0x38) == '\x01'))
            goto LAB_00832907;
            if (*(char *)(*piVar7 + 0x38) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x38) = 1;
              *(undefined1 *)(piVar7 + 0xe) = 0;
              FUN_007c0990(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 0xe) = (char)piVar6[0xe];
            *(undefined1 *)(piVar6 + 0xe) = 1;
            *(undefined1 *)(*piVar7 + 0x38) = 1;
            FUN_0081f6c0(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 0xe) = 1;
  }
  if (param_3[9] != 0) {
    FUN_0089120c(param_3[9]);
  }
  param_3[9] = 0;
  param_3[10] = 0;
  param_3[0xb] = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

