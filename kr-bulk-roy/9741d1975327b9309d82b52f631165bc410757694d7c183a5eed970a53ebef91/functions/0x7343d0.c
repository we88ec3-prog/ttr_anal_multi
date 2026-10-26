
undefined4 FUN_007343d0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091957e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00fcde40 & 1;
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  *(undefined4 *)(in_ECX + 0x10) = unaff_EDI;
  *(undefined4 *)(in_ECX + 0x1c) = 0x15;
  if (uVar1 == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880(uVar2);
    _atexit(FUN_00bce6f0);
  }
  uVar3 = D3DXCreateTexture(DAT_00fcde2c,param_1,unaff_EDI,1,0,0x15,1,in_ECX + 0x44);
  FUN_00733f90(uVar3,0);
  ExceptionList = local_10;
  return uVar3;
}

