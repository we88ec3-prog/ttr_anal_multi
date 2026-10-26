
void FUN_0056f5c0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  int iVar7;
  int *piVar8;
  
  piVar3 = param_2;
  iVar1 = *param_2;
  if ((iVar1 == 8) || (iVar1 == 0xb)) {
    piVar4 = *(int **)(param_1 + 0x54);
    if (param_2[2] == 4) {
      piVar8 = (int *)*piVar4;
      bVar6 = false;
      if (piVar8 != piVar4) {
        do {
          piVar5 = (int *)piVar8[2];
          iVar1 = *piVar5;
          if ((iVar1 == 8) || (iVar1 == 0xb)) {
            if ((*param_2 == iVar1) && (param_2[1] == piVar5[1])) {
              piVar5[2] = param_2[2];
              *(undefined1 *)(piVar5 + 3) = 1;
              bVar6 = true;
            }
            else if (((float)param_2[4] == (float)piVar5[4]) &&
                    ((float)param_2[5] == (float)piVar5[5])) {
              *(undefined1 *)(piVar5 + 3) = 0;
            }
          }
          piVar8 = (int *)*piVar8;
        } while (piVar8 != piVar4);
        if (bVar6) {
LAB_0056f6ac:
          if (7 < (uint)param_2[0xe]) {
            FUN_0089120c(param_2[9]);
          }
          piVar3[0xe] = 7;
          piVar3[0xd] = 0;
          *(undefined2 *)(piVar3 + 9) = 0;
          FUN_0089120c(piVar3);
          return;
        }
      }
    }
    else {
      for (piVar8 = (int *)*piVar4; piVar8 != piVar4; piVar8 = (int *)*piVar8) {
        piVar5 = (int *)piVar8[2];
        if ((*piVar5 == iVar1) && (piVar5[1] == param_2[1])) {
          piVar5[2] = param_2[2];
          *(undefined1 *)(piVar5 + 3) = 1;
          goto LAB_0056f6ac;
        }
      }
    }
  }
  else {
    for (puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x54);
        puVar2 != *(undefined4 **)(param_1 + 0x54); puVar2 = (undefined4 *)*puVar2) {
      piVar3 = (int *)puVar2[2];
      if ((*piVar3 == iVar1) && (piVar3[1] == param_2[1])) {
        piVar3[2] = param_2[2];
        FUN_0056f0f0();
        return;
      }
    }
  }
  iVar1 = *(int *)(param_1 + 0x54);
  iVar7 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&param_2);
  if (*(int *)(param_1 + 0x58) != 0x3ffffffe) {
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
    *(int *)(iVar1 + 4) = iVar7;
    **(int **)(iVar7 + 4) = iVar7;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

