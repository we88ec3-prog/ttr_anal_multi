
void FUN_0063a460(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  int in_ECX;
  int *piVar6;
  int iVar7;
  short *psVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946422;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb7258 == 0) {
LAB_0063a63d:
    FUN_00539af0();
    (**(code **)(**(int **)(in_ECX + 4) + 0xd4))();
    puVar4 = (undefined4 *)FUN_00891268();
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = FoxUI::FXUIEvent::vftable;
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4343;
    }
    FUN_004072a0();
    ExceptionList = local_10;
    return;
  }
  iVar7 = 0;
  iVar3 = *(int *)(DAT_00fb7258 + 0x2c) - *(int *)(DAT_00fb7258 + 0x28) >> 2;
  if (iVar3 != 0) {
    piVar6 = *(int **)(DAT_00fb7258 + 0x28);
    do {
      if (*(char *)(*piVar6 + 10) != '\0') {
        iVar7 = iVar7 + 1;
      }
      piVar6 = piVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (iVar7 == 1) goto LAB_0063a63d;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar4 = (undefined4 *)FUN_00891268();
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf443a;
    *puVar4 = FoxUI::FXUIEventI1::vftable;
    puVar4[5] = 0;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_00402160();
  local_8 = 3;
  iVar3 = FUN_005854b0();
  FUN_005740f0();
  if (in_ECX == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar8 = (short *)(in_ECX + 0x10);
  if (7 < *(uint *)(in_ECX + 0x24)) {
    psVar8 = *(short **)psVar8;
  }
  psVar5 = psVar8;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xcf);
  ExceptionList = local_10;
  return;
}

