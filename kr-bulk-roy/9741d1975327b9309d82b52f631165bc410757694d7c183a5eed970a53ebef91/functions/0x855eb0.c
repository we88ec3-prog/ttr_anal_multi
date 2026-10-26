
/* WARNING: Removing unreachable block (ram,0x00855f70) */
/* WARNING: Removing unreachable block (ram,0x00855f80) */
/* WARNING: Removing unreachable block (ram,0x00855f89) */
/* WARNING: Removing unreachable block (ram,0x00855f8c) */
/* WARNING: Removing unreachable block (ram,0x00855f7c) */
/* WARNING: Removing unreachable block (ram,0x00855f9a) */
/* WARNING: Removing unreachable block (ram,0x00855faa) */
/* WARNING: Removing unreachable block (ram,0x00855fb5) */
/* WARNING: Removing unreachable block (ram,0x00855fb1) */
/* WARNING: Removing unreachable block (ram,0x00855fa5) */
/* WARNING: Removing unreachable block (ram,0x00855fb8) */

void FUN_00855eb0(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool bVar8;
  int iVar9;
  
  if (*(char *)((int)param_3 + 0x39) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0052d260();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
    if (*(char *)(param_3[2] + 0x39) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      cVar1 = *(char *)(*piVar6 + 0x39);
      piVar2 = (int *)*piVar6;
      piVar5 = piVar6;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x39);
        piVar5 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      uVar4 = FUN_00832a00();
      *(undefined4 *)(*(int *)(param_1 + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar7;
    }
  }
  if ((char)param_3[0xe] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        if ((char)piVar6[0xe] != '\x01') break;
        piVar5 = (int *)*piVar7;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar7[2];
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar7 + 0xe) = 0;
            FUN_007c0990(param_1);
            piVar5 = (int *)piVar7[2];
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(*piVar5 + 0x38) != '\x01') || (*(char *)(piVar5[2] + 0x38) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x38) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x38) = 1;
                *(undefined1 *)(piVar5 + 0xe) = 0;
                FUN_0081f6c0(param_1);
                piVar5 = (int *)piVar7[2];
              }
              *(char *)(piVar5 + 0xe) = (char)piVar7[0xe];
              *(undefined1 *)(piVar7 + 0xe) = 1;
              *(undefined1 *)(piVar5[2] + 0x38) = 1;
              FUN_007c0990(param_1);
              break;
            }
LAB_0085609c:
            *(undefined1 *)(piVar5 + 0xe) = 0;
          }
        }
        else {
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar7 + 0xe) = 0;
            FUN_0081f6c0(param_1);
            piVar5 = (int *)*piVar7;
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(piVar5[2] + 0x38) == '\x01') && (*(char *)(*piVar5 + 0x38) == '\x01'))
            goto LAB_0085609c;
            if (*(char *)(*piVar5 + 0x38) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x38) = 1;
              *(undefined1 *)(piVar5 + 0xe) = 0;
              FUN_007c0990(param_1);
              piVar5 = (int *)*piVar7;
            }
            *(char *)(piVar5 + 0xe) = (char)piVar7[0xe];
            *(undefined1 *)(piVar7 + 0xe) = 1;
            *(undefined1 *)(*piVar5 + 0x38) = 1;
            FUN_0081f6c0(param_1);
            break;
          }
        }
        bVar8 = piVar7 != *(int **)(*(int *)(param_1 + 4) + 4);
        piVar6 = piVar7;
        piVar7 = (int *)piVar7[1];
      } while (bVar8);
    }
    *(undefined1 *)(piVar6 + 0xe) = 1;
  }
  param_3[10] = (int)gbParam::vftable;
  switch(param_3[0xb]) {
  case 1:
  case 6:
  case 9:
  case 10:
  case 0xd:
    iVar9 = param_3[0xc];
    break;
  case 2:
  case 7:
  case 0xb:
    iVar9 = param_3[0xc];
    break;
  case 3:
  case 5:
  case 8:
  case 0xc:
    iVar9 = param_3[0xc];
    break;
  case 4:
    FUN_00891d3d(param_3[0xc]);
  default:
    goto switchD_008560fd_default;
  }
  FUN_0089120c(iVar9);
switchD_008560fd_default:
  param_3[0xc] = 0;
  if (param_3[0xd] != 0) {
    FUN_00891d3d(param_3[0xd]);
    param_3[0xd] = 0;
  }
  if (0xf < (uint)param_3[8]) {
    FUN_0089120c(param_3[3]);
  }
  param_3[8] = 0xf;
  param_3[7] = 0;
  *(undefined1 *)(param_3 + 3) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

