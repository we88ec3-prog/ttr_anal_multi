
undefined4 FUN_0077f2a0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *in_ECX;
  int **ppiVar5;
  uint uVar6;
  int **ppiVar7;
  uint uVar8;
  undefined1 *puStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int *piStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int *piStack_48;
  undefined4 uStack_44;
  int iStack_40;
  uint uStack_3c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091ec38;
  local_14 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  iStack_40 = param_1;
  uStack_44 = 0x77f2d7;
  FUN_00780260();
  uStack_4c = *(undefined4 *)(param_1 + 0x84);
  iStack_40 = 0;
  uStack_44 = 4;
  piStack_48 = in_ECX + 0x18;
  uStack_50 = 0x77f2eb;
  FUN_006ddcc0();
  uStack_5c = *(undefined4 *)(param_1 + 0x84);
  uStack_50 = 0;
  uStack_54 = 0x2c;
  piStack_58 = in_ECX + 0x1a;
  uStack_60 = 0x77f2ff;
  FUN_006ddcc0();
  uStack_60 = 0;
  puStack_64 = &DAT_0000002c;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0x25);
  uVar6 = 4;
  ppiVar5 = &piStack_58;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),ppiVar5,4,0);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&puStack_64,4,0);
  FUN_00797980(ppiVar5);
  FUN_00873000(uVar6);
  ppiVar7 = (int **)0x0;
  if (ppiVar5 != (int **)0x0) {
    do {
      iVar2 = *in_ECX;
      uVar3 = FUN_00781f20();
      (**(code **)(iVar2 + 0x40))(uVar3);
      ppiVar7 = (int **)((int)ppiVar7 + 1);
    } while (ppiVar7 < ppiVar5);
  }
  uVar8 = 0;
  if (uVar6 != 0) {
    do {
      puVar4 = (undefined4 *)FUN_00781f20();
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = puVar4[1] + 1;
      }
      uStack_5c = 0;
      FUN_0077f8f0();
      uStack_5c = 0xffffffff;
      if (puVar4 != (undefined4 *)0x0) {
        piVar1 = puVar4 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)*puVar4)(1);
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar6);
  }
  ExceptionList = puStack_64;
  return 1;
}

