
undefined4 FUN_00846cc0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined1 *puStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  int iStack_50;
  int *piStack_4c;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  
  uStack_2c = param_1;
  iStack_30 = 0x846cd7;
  FUN_00780260();
  uStack_38 = *(uint *)(param_1 + 0x84);
  uStack_2c = 0;
  iStack_30 = 0x1c;
  iStack_34 = in_ECX + 0x54;
  iStack_3c = 0x846ceb;
  FUN_006ddcc0();
  iStack_3c = 0x846cf2;
  piVar2 = (int *)FUN_00781f20();
  puVar5 = *(undefined4 **)(in_ECX + 0x74);
  if (puVar5 != (undefined4 *)0x0) {
    piVar1 = puVar5 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      iStack_3c = 1;
      uStack_40 = 0x846d08;
      (**(code **)*puVar5)();
    }
  }
  *(int **)(in_ECX + 0x74) = piVar2;
  if (piVar2 != (int *)0x0) {
    iStack_3c = 0x846d18;
    iVar3 = (**(code **)(*piVar2 + 8))();
    if (iVar3 == 0) {
      iStack_3c = 0x846d26;
      uVar4 = (**(code **)(**(int **)(in_ECX + 0x74) + 0xc))();
      *(undefined4 *)(in_ECX + 0x74) = uVar4;
    }
    piVar2 = (int *)(*(int *)(in_ECX + 0x74) + 4);
    *piVar2 = *piVar2 + 1;
  }
  iStack_3c = 0x846d36;
  piVar2 = (int *)FUN_00781f20();
  puVar5 = *(undefined4 **)(in_ECX + 0x78);
  if (puVar5 != (undefined4 *)0x0) {
    piVar1 = puVar5 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      iStack_3c = 1;
      uStack_40 = 0x846d4c;
      (**(code **)*puVar5)();
    }
  }
  *(int **)(in_ECX + 0x78) = piVar2;
  if (piVar2 != (int *)0x0) {
    iStack_3c = 0x846d5c;
    iVar3 = (**(code **)(*piVar2 + 8))();
    if (iVar3 == 0) {
      iStack_3c = 0x846d6a;
      uVar4 = (**(code **)(**(int **)(in_ECX + 0x78) + 0xc))();
      *(undefined4 *)(in_ECX + 0x78) = uVar4;
    }
    piVar2 = (int *)(*(int *)(in_ECX + 0x78) + 4);
    *piVar2 = *piVar2 + 1;
  }
  uStack_48 = *(undefined4 *)(param_1 + 0x84);
  iStack_3c = 0;
  uStack_40 = 4;
  puStack_44 = &stack0xffffffd8;
  piStack_4c = (int *)0x846d90;
  FUN_006ddcc0();
  if (uStack_38 != 0) {
    iStack_50 = *(int *)(in_ECX + 0x7c);
    piVar2 = (int *)(in_ECX + 0x7c);
    if (iStack_50 != *(int *)(in_ECX + 0x80)) {
      piStack_4c = (int *)uStack_2c;
      uStack_58 = 0x846db7;
      piStack_54 = (int *)*(int *)(in_ECX + 0x80);
      piStack_4c = (int *)FUN_00848b00();
      iStack_50 = 0x846dcb;
      uStack_2c = (uint)piStack_4c;
      FUN_00848b60();
      *(uint *)(in_ECX + 0x80) = uStack_2c;
    }
    iStack_50 = 0x846ddf;
    piStack_4c = piVar2;
    FUN_008480d0();
    uStack_2c = 0;
    if (uStack_38 != 0) {
      iStack_3c = 0;
      do {
        uStack_58 = *(undefined4 *)(param_1 + 0x84);
        puVar5 = (undefined4 *)(*piVar2 + iStack_3c);
        piStack_4c = (int *)0x0;
        iStack_50 = 4;
        piStack_54 = &iStack_34;
        iStack_34 = 0;
        uStack_5c = 0x846e16;
        FUN_006ddcc0();
        if (puStack_44 != (undefined1 *)0x0) {
          if ((undefined1 *)puVar5[4] < puStack_44) {
            puStack_60 = puStack_44 + -(int)puVar5[4];
            uStack_5c = 0;
            FUN_00429630();
          }
          else {
            uStack_5c = 0xffffffff;
            puStack_60 = puStack_44;
            FUN_00402c80();
          }
          if (0xf < (uint)puVar5[5]) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puStack_44 != (undefined1 *)0x0) {
            uStack_5c = 0;
            puStack_60 = puStack_44;
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),puVar5);
          }
        }
        piVar1 = piStack_4c;
        uStack_5c = 0;
        puStack_60 = (undefined1 *)0x34;
        FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),(int)piStack_4c + 0x1c + *piVar2);
        FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),(int)piVar1 + 0x50 + *piVar2,4,0);
        puStack_60 = (undefined1 *)0x0;
        FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&puStack_60,4,0);
        piStack_4c = (int *)0x846ebb;
        FUN_00847f80();
        iVar3 = *(int *)(iStack_3c + 0x54 + *piVar2);
        if (0 < iStack_30) {
          iStack_34 = iStack_30;
          do {
            uStack_58 = *(undefined4 *)(param_1 + 0x84);
            piStack_4c = (int *)0x0;
            iStack_50 = 8;
            uStack_5c = 0x846ee2;
            piStack_54 = (int *)iVar3;
            FUN_006ddcc0();
            iVar3 = iVar3 + 8;
            iStack_34 = iStack_34 + -1;
          } while (iStack_34 != 0);
        }
        iStack_3c = iStack_3c + 100;
        uStack_2c = uStack_2c + 1;
      } while (uStack_2c < uStack_38);
    }
  }
  return 1;
}

