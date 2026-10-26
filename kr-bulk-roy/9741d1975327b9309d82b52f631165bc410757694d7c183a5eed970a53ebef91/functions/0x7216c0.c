
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_007216c0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  undefined4 local_2070;
  undefined4 local_206c;
  undefined4 local_2068;
  undefined **local_2060 [3];
  char *local_2054;
  undefined4 local_2050;
  undefined4 local_204c;
  undefined4 local_2048;
  undefined4 local_2044;
  undefined4 local_2040;
  undefined4 local_203c;
  undefined4 local_2038 [1025];
  undefined4 local_1034 [1025];
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 **local_20;
  undefined4 **local_1c;
  uint local_18;
  undefined4 uStack_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091207d;
  local_10 = ExceptionList;
  uStack_14 = 0x7216db;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_203c = 0;
  if ((int *)*param_1 == (int *)0x0) {
    puVar1 = in_ECX + 1;
    *in_ECX = 0;
    *puVar1 = 0;
    in_ECX[2] = 0;
    in_ECX[3] = puVar1;
    in_ECX[4] = puVar1;
  }
  else {
    if (*(char *)(*(int *)*param_1 + 1) != '\x01') {
      FUN_00891010(local_18);
      local_2060[0] = pugi::xpath_exception::vftable;
      local_2054 = "Expression does not evaluate to node set";
      local_2050 = 0;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2060,&DAT_00c858e4);
    }
    local_204c = *in_EDX;
    local_2048 = in_EDX[1];
    local_30 = local_2038;
    local_28 = local_1034;
    local_20 = &local_30;
    local_1c = &local_28;
    local_2044 = 1;
    local_2040 = 1;
    local_2c = 0;
    local_24 = 0;
    local_1034[0] = 0;
    local_2038[0] = 0;
    local_8 = 1;
    FUN_0071efc0(&local_2070,&local_204c,&local_20);
    puVar1 = in_ECX + 1;
    *in_ECX = local_2070;
    *puVar1 = 0;
    in_ECX[2] = 0;
    in_ECX[3] = puVar1;
    in_ECX[4] = puVar1;
    FUN_00721450(local_206c,local_2068);
    local_203c = 1;
    local_8 = local_8 & 0xffffff00;
    FUN_0071bef0();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

