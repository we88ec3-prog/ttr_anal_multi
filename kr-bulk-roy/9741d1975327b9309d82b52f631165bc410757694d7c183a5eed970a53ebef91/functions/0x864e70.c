
/* WARNING: Removing unreachable block (ram,0x00864efd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00864e70(undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  undefined4 extraout_EDX;
  undefined4 uVar1;
  int **ppiVar2;
  int *local_2c;
  undefined4 local_28 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ppiVar2 = &local_2c;
  uVar1 = 0;
  local_2c = (int *)0x0;
  (**(code **)(*in_ECX + 0x98))();
  if (local_2c == (int *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar1,ppiVar2);
    return;
  }
  (**(code **)(*local_2c + 0x30))(local_2c,local_28);
  (**(code **)(*in_ECX + 0x18))();
  (**(code **)(_DAT_00000000 + 0x28))(0,0,1,local_28[0],0,param_1,param_2);
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
    local_2c = (int *)0x0;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

