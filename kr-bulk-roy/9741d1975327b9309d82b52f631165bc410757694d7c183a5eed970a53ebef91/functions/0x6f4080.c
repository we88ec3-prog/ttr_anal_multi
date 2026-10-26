
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006f4080(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905af8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = Input::CLuaDevice::vftable;
  puVar1 = param_1 + 1;
  *puVar1 = 0;
  puVar3 = (undefined4 *)FUN_00891268(8,uVar2);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar1 = puVar3;
    *puVar3 = 0;
    puVar3[1] = 0;
    *(undefined4 **)*puVar1 = puVar1;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    _memset(param_1 + 7,0,0x100);
    _DAT_00fba810 = param_1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

