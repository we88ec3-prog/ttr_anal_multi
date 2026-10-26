
uint FUN_00408920(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint in_EAX;
  undefined4 uVar5;
  int iVar6;
  
  piVar4 = param_1;
  iVar6 = param_1[0x2b] - param_1[0x2a] >> 2;
  if ((iVar6 == param_2) || (param_1[0x29] == 0)) {
    return in_EAX & 0xffffff00;
  }
  FUN_00408b60();
  if (param_2 < iVar6) {
    if (param_2 < piVar4[0x2b] - piVar4[0x2a] >> 2) {
      do {
        piVar1 = *(int **)(piVar4[0x2b] + -4);
        (**(code **)(*piVar4 + 0x74))(piVar1);
        puVar2 = (undefined4 *)piVar4[0x2f];
        param_1 = piVar1;
        if (&param_1 < puVar2) {
          puVar3 = (undefined4 *)piVar4[0x2e];
          if (&param_1 < puVar3) goto LAB_004089e1;
          if (puVar2 == (undefined4 *)piVar4[0x30]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar4[0x2f] != (undefined4 *)0x0) {
            *(undefined4 *)piVar4[0x2f] =
                 *(undefined4 *)(piVar4[0x2e] + ((int)&param_1 - (int)puVar3 >> 2) * 4);
          }
        }
        else {
LAB_004089e1:
          if (puVar2 == (undefined4 *)piVar4[0x30]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar4[0x2f] != (undefined4 *)0x0) {
            *(undefined4 *)piVar4[0x2f] = piVar1;
          }
        }
        piVar4[0x2f] = piVar4[0x2f] + 4;
        if (piVar4[0x2a] != piVar4[0x2b]) {
          piVar4[0x2b] = piVar4[0x2b] + -4;
        }
      } while (param_2 < piVar4[0x2b] - piVar4[0x2a] >> 2);
    }
  }
  else {
    param_1 = (int *)(param_2 - iVar6);
    if (0 < (int)param_1) {
      do {
        uVar5 = FUN_00408bf0();
        (**(code **)(*piVar4 + 0x70))(uVar5);
        FUN_00443d10();
        param_1 = (int *)((int)param_1 + -1);
      } while (param_1 != (int *)0x0);
    }
  }
  iVar6 = 0;
  if (0 < param_2) {
    do {
      *(int *)(*(int *)(piVar4[0x2a] + iVar6 * 4) + 0x20) = iVar6;
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_2);
  }
  piVar4[0x39] = param_2 + 1;
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}

