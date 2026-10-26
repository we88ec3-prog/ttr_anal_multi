
undefined4 * FUN_00611c70(undefined4 param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  int in_ECX;
  short *psVar6;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091263e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  FUN_0082ef00(&param_1);
  if ((in_ECX != DAT_00fb11b0) && (*(int *)(in_ECX + 0x10) != 0)) {
    iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + 8);
    if (iVar3 == 1) {
      param_1 = 0x2ca;
      iVar3 = FUN_00585620();
      FUN_005740f0(&param_1);
      if (in_ECX == *(int *)(iVar3 + 4)) {
        pcVar2 = (code *)swi(3);
        puVar4 = (undefined4 *)(*pcVar2)();
        return puVar4;
      }
      if (*(uint *)(in_ECX + 0x24) < 8) {
        psVar5 = (short *)(in_ECX + 0x10);
        psVar6 = psVar5;
      }
      else {
        psVar5 = *(short **)(in_ECX + 0x10);
        psVar6 = psVar5;
      }
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
    }
    else {
      if (iVar3 != 2) goto LAB_00611da8;
      param_1 = 0x2cb;
      iVar3 = FUN_00585620();
      FUN_005740f0(&param_1);
      if (in_ECX == *(int *)(iVar3 + 4)) {
        pcVar2 = (code *)swi(3);
        puVar4 = (undefined4 *)(*pcVar2)();
        return puVar4;
      }
      if (*(uint *)(in_ECX + 0x24) < 8) {
        psVar5 = (short *)(in_ECX + 0x10);
        psVar6 = psVar5;
      }
      else {
        psVar5 = *(short **)(in_ECX + 0x10);
        psVar6 = psVar5;
      }
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
    }
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
  }
LAB_00611da8:
  if ((uint)unaff_EDI[5] < 8) {
    ExceptionList = local_10;
    return unaff_EDI;
  }
  ExceptionList = local_10;
  return (undefined4 *)*unaff_EDI;
}

