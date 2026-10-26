
/* WARNING: Removing unreachable block (ram,0x00835119) */
/* WARNING: Removing unreachable block (ram,0x00835129) */
/* WARNING: Removing unreachable block (ram,0x00835132) */
/* WARNING: Removing unreachable block (ram,0x00835135) */
/* WARNING: Removing unreachable block (ram,0x00835125) */
/* WARNING: Removing unreachable block (ram,0x00835143) */
/* WARNING: Removing unreachable block (ram,0x00835153) */
/* WARNING: Removing unreachable block (ram,0x0083515e) */
/* WARNING: Removing unreachable block (ram,0x0083515a) */
/* WARNING: Removing unreachable block (ram,0x0083514e) */
/* WARNING: Removing unreachable block (ram,0x00835161) */

void FUN_00835050(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_3 + 0x51) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0051f3c0();
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x51) == '\0') {
    if (*(char *)(param_3[2] + 0x51) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x51) == '\0') {
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
    if (*(char *)((int)piVar8 + 0x51) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x51);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x51);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x51) == '\0') {
      uVar5 = FUN_00835380();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[0x14] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[0x14] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[0x14] == '\0') {
            *(undefined1 *)(piVar7 + 0x14) = 1;
            *(undefined1 *)(piVar6 + 0x14) = 0;
            FUN_00835320(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x51) == '\0') {
            if ((*(char *)(*piVar7 + 0x50) != '\x01') || (*(char *)(piVar7[2] + 0x50) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x50) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x50) = 1;
                *(undefined1 *)(piVar7 + 0x14) = 0;
                FUN_0051f360(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 0x14) = (char)piVar6[0x14];
              *(undefined1 *)(piVar6 + 0x14) = 1;
              *(undefined1 *)(piVar7[2] + 0x50) = 1;
              FUN_00835320(param_1);
              break;
            }
LAB_00835237:
            *(undefined1 *)(piVar7 + 0x14) = 0;
          }
        }
        else {
          if ((char)piVar7[0x14] == '\0') {
            *(undefined1 *)(piVar7 + 0x14) = 1;
            *(undefined1 *)(piVar6 + 0x14) = 0;
            FUN_0051f360(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x51) == '\0') {
            if ((*(char *)(piVar7[2] + 0x50) == '\x01') && (*(char *)(*piVar7 + 0x50) == '\x01'))
            goto LAB_00835237;
            if (*(char *)(*piVar7 + 0x50) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x50) = 1;
              *(undefined1 *)(piVar7 + 0x14) = 0;
              FUN_00835320(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 0x14) = (char)piVar6[0x14];
            *(undefined1 *)(piVar6 + 0x14) = 1;
            *(undefined1 *)(*piVar7 + 0x50) = 1;
            FUN_0051f360(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 0x14) = 1;
  }
  _eh_vector_destructor_iterator_(param_3 + 4,0x10,4,FUN_00418290);
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

