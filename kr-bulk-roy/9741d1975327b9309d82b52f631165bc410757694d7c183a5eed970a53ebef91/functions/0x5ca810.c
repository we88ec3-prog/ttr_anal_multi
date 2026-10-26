
undefined4 * FUN_005ca810(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a988;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = _malloc(0xa4);
  local_8 = 0;
  puVar5 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00763060(puVar2,param_1);
    *puVar2 = FUI::CFXUIImageSetAutoDestroy::vftable;
    puVar2[0x28] = in_ECX;
    puVar5 = puVar2;
  }
  local_8 = 0xffffffff;
  FUN_00763400(uVar1);
  if (*(int *)(in_ECX + 0x10) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0xc);
    FUN_0053f8a0();
    iVar3 = *(int *)(*(int *)(iVar3 + 0x10) + 0xc) + 1;
  }
  puVar5[3] = iVar3;
  uVar4 = FUN_0057ef20();
  FUN_0082f200(in_ECX + 8,uVar4);
  ExceptionList = local_10;
  return puVar5;
}

