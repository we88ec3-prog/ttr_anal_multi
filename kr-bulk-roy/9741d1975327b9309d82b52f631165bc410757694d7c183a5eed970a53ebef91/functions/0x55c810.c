
void FUN_0055c810(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar2 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090cf1b;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *(uint *)(param_1 + 0xc);
  local_14 = param_2 & 0xffff;
  iVar7 = param_1 + 8;
  puVar4 = (uint *)FUN_00826280(&local_14);
  if (*puVar4 == uVar1) {
    iVar5 = FUN_00891268(0x14,uVar3);
    local_8 = 0;
    if (iVar5 != 0) {
      FUN_0055c520(param_3);
    }
    local_8 = 0xffffffff;
    uVar6 = FUN_004ca670();
    FUN_008262f0(iVar7,uVar6);
    if (param_4 == 0) {
      param_4 = 1;
    }
    param_3 = param_4;
    param_4 = param_2 & 0xffff;
    FUN_00826280(&param_4);
    if (param_2 == *(uint *)(param_1 + 0xc)) {
      ExceptionList = local_10;
      return;
    }
    iVar7 = *(int *)(param_2 + 0x10);
    puVar8 = &param_3;
  }
  else {
    param_1 = param_4;
    param_4 = uVar2 & 0xffff;
    FUN_00826280(&param_4);
    if (param_2 == uVar1) {
      ExceptionList = local_10;
      return;
    }
    iVar7 = *(int *)(param_2 + 0x10);
    puVar8 = &param_1;
  }
  uVar6 = FUN_0055e5b0(puVar8);
  FUN_00412b40(iVar7 + 4,uVar6);
  ExceptionList = local_10;
  return;
}

