
void FUN_004fabf0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x16c) != 0) {
    FUN_004fb7d0();
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  puVar1 = (undefined4 *)FUN_00891268(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FunctorArg0Inst<void,CRankingMgr>::vftable;
    puVar1[1] = param_1;
    puVar1[2] = FUN_004fa9f0;
    uVar2 = FUN_004fb770();
    *(undefined4 *)(param_1 + 0x16c) = uVar2;
    return;
  }
  uVar2 = FUN_004fb770();
  *(undefined4 *)(param_1 + 0x16c) = uVar2;
  return;
}

