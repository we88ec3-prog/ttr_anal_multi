
void FUN_00703050(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_218;
  
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_006f6210(param_1);
  for (iVar3 = FUN_006f6370(param_1,2); 0 < iVar3; iVar3 = iVar3 + -1) {
    FUN_006f6c40(uVar2,local_218);
  }
  FUN_006f6af0();
  FUN_006f5bb0();
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

