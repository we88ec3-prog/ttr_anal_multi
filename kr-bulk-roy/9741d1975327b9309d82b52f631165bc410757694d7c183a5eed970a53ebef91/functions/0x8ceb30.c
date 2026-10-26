
void FUN_008ceb30(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (param_1[1] != 0) {
    do {
      piVar1 = *(int **)(param_1[3] + uVar7 * 8);
      piVar6 = piVar1;
      if (*(int *)(param_1[3] + 4 + uVar7 * 8) != 0) {
        do {
          piVar6 = (int *)*piVar6;
          if (piVar6 == piVar1) goto LAB_008cec22;
        } while (piVar6[7] == piVar1[7]);
        piVar1 = (int *)piVar6[1];
        piVar5 = piVar1;
        piVar4 = piVar1;
LAB_008ceb72:
        do {
          piVar5 = (int *)piVar5[1];
          if (piVar5 == piVar1) break;
          if (piVar5[7] != piVar4[7]) {
            iVar2 = piVar4[7];
            if (*(int *)((int)piVar6 + 0x1c) < iVar2) {
              if (iVar2 <= piVar5[7]) {
                piVar6 = (int *)*piVar5;
                piVar4 = piVar5;
                goto LAB_008ceb72;
              }
LAB_008ceba0:
              do {
                piVar4[4] = piVar4[4] | 0x40;
                piVar4 = (int *)piVar4[1];
              } while (piVar4 != piVar5);
            }
            else if (iVar2 < piVar5[7]) goto LAB_008ceba0;
            piVar6 = (int *)*piVar5;
            piVar4 = piVar5;
          }
        } while( true );
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_1[1]);
  }
  uVar7 = 0;
  do {
    if (*param_1 <= uVar7) {
      return;
    }
    piVar1 = (int *)(param_1[2] + uVar7 * 0x28);
    uVar3 = piVar1[4];
    piVar6 = piVar1;
    piVar5 = piVar1;
    if ((uVar3 & 0x40) != 0) {
      do {
        piVar6 = (int *)*piVar6;
        if (piVar6 == piVar1) goto LAB_008cec22;
      } while (piVar6[8] == piVar1[8]);
      do {
        piVar5 = (int *)piVar5[1];
        if (piVar5 == piVar1) goto LAB_008cec22;
      } while (piVar5[8] == piVar1[8]);
    }
    iVar2 = piVar1[8];
    if ((piVar6[8] < iVar2) && (iVar2 < piVar5[8])) {
      piVar1[4] = uVar3 | 0x80;
      uVar7 = uVar7 + 1;
    }
    else {
      if ((iVar2 < piVar6[8]) && (piVar5[8] < iVar2)) {
        piVar1[4] = uVar3 | 0x100;
      }
LAB_008cec22:
      uVar7 = uVar7 + 1;
    }
  } while( true );
}

