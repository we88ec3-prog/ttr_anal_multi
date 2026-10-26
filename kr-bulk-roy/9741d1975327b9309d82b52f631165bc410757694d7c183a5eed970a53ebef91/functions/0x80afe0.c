
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080afe0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  
  piVar1 = (int *)FUN_0080e660();
  *unaff_ESI = piVar1;
  (**(code **)(*piVar1 + 0xc))(1);
  if ((_DAT_00fe33fc & 1) == 0) {
    _DAT_00fe33fc = _DAT_00fe33fc | 1;
    DAT_00fe3400 = 0;
    _DAT_00fe3404 = 0;
    _DAT_00fe3408 = 0;
    _DAT_00fe3410 = 4;
    _atexit((_func_4879 *)&LAB_00bd0c00);
  }
  FUN_0080c240(&DAT_00fe3400);
  puVar2 = (undefined4 *)FUN_00891268(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = FunctorArg0Inst<void,MoonSound::SoundManager>::vftable;
    puVar2[1] = unaff_ESI;
    puVar2[2] = FUN_0080b360;
    uVar3 = FUN_004fb770();
    unaff_ESI[0x1b] = uVar3;
    return;
  }
  uVar3 = FUN_004fb770();
  unaff_ESI[0x1b] = uVar3;
  return;
}

