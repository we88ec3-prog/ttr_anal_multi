
void FUN_008563c0(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 in_ECX;
  undefined4 *unaff_EDI;
  undefined **local_28 [4];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906ac8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *param_1;
  local_18 = 0;
  uVar3 = FUN_00867d70(local_28,in_ECX);
  local_8 = 0;
  *unaff_EDI = uVar1;
  FUN_00867d70(unaff_EDI + 1,uVar3);
  local_28[0] = gbParam::vftable;
  FUN_00867f40(uVar2);
  ExceptionList = local_10;
  return;
}

