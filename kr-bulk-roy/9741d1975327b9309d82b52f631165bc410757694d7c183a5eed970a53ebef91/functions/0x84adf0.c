
undefined4 FUN_0084adf0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  undefined4 uStack_74;
  void *pvStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  uint uStack_44;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092053a;
  local_14 = ExceptionList;
  uStack_44 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  iStack_48 = param_1;
  uStack_4c = 0x84ae27;
  FUN_00780260();
  uStack_54 = *(undefined4 *)(param_1 + 0x84);
  iStack_48 = 0;
  uStack_4c = 0x1c;
  iStack_50 = in_ECX + 0x54;
  uStack_58 = 0x84ae3c;
  FUN_006ddcc0();
  pvStack_64 = *(void **)(param_1 + 0x84);
  uStack_58 = 0;
  uStack_5c = 4;
  iStack_60 = in_ECX + 0x98;
  uStack_68 = 0x84ae52;
  FUN_006ddcc0();
  uStack_74 = *(undefined4 *)(param_1 + 0x84);
  uStack_68 = 0;
  uStack_6c = 4;
  pvStack_70 = (void *)(in_ECX + 0x9c);
  FUN_006ddcc0();
  iVar5 = *(int *)(param_1 + 0x84);
  FUN_006ddcc0(iVar5,in_ECX + 0xa4,4,0);
  uStack_74 = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_74,4,0);
  iVar7 = 0;
  if (0 < iVar5) {
    do {
      uStack_6c = 0;
      uStack_74 = 0;
      pvStack_70 = (void *)0x0;
      uStack_5c = 0;
      piVar2 = (int *)FUN_00781f20();
      piVar4 = piVar2;
      if (piVar2 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar2 + 8))();
        if (iVar3 == 0) {
          piVar4 = (int *)(**(code **)(*piVar2 + 0xc))();
        }
        piVar4[1] = piVar4[1] + 1;
      }
      FUN_0084b470();
      uStack_5c = 2;
      if (piVar4 != (int *)0x0) {
        piVar2 = piVar4 + 1;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          (**(code **)*piVar4)(1);
        }
      }
      _free(pvStack_70);
      iVar7 = iVar7 + 1;
      uStack_5c = 0xffffffff;
    } while (iVar7 < iVar5);
  }
  piVar4 = (int *)FUN_00781f20();
  puVar1 = *(undefined4 **)(in_ECX + 0x94);
  if (puVar1 != (undefined4 *)0x0) {
    piVar2 = puVar1 + 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      (**(code **)*puVar1)(1);
    }
  }
  *(int **)(in_ECX + 0x94) = piVar4;
  if (piVar4 == (int *)0x0) {
    ExceptionList = pvStack_64;
    return 1;
  }
  iVar5 = (**(code **)(*piVar4 + 8))();
  if (iVar5 == 0) {
    uVar6 = (**(code **)(**(int **)(in_ECX + 0x94) + 0xc))();
    *(undefined4 *)(in_ECX + 0x94) = uVar6;
  }
  piVar4 = (int *)(*(int *)(in_ECX + 0x94) + 4);
  *piVar4 = *piVar4 + 1;
  ExceptionList = pvStack_64;
  return 1;
}

