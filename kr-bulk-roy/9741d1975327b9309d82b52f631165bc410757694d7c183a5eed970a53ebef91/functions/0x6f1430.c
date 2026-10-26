
uint FUN_006f1430(int param_1,undefined4 param_2)

{
  uint uVar1;
  HMODULE pHVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918aeb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar8 = 0;
  puVar7 = &DAT_00bd6784;
  uVar6 = 0x800;
  *(undefined4 *)(param_1 + 4) = param_2;
  pHVar2 = GetModuleHandleW((LPCWSTR)0x0);
  iVar3 = DirectInput8Create(pHVar2,uVar6,puVar7,param_1,uVar8);
  if (-1 < iVar3) {
    puVar4 = (undefined4 *)FUN_00891268(0x108,uVar1);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = Input::CKeyboardDevice::vftable;
      puVar4[1] = 0;
      _memset(puVar4 + 2,0,0x100);
    }
    iVar3 = FUN_006f15e0();
    iVar5 = FUN_00891268(0x1130);
    if (iVar5 != 0) {
      FUN_006f3980();
    }
    FUN_006f15e0();
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = Input::CMouseDevice::vftable;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
    }
    FUN_006f15e0();
    iVar5 = FUN_00891268(0x11c);
    local_8 = 0;
    if (iVar5 != 0) {
      FUN_006f4080(iVar5);
    }
    local_8 = 0xffffffff;
    FUN_006f15e0();
    ExceptionList = local_10;
    return -(uint)(iVar3 != 0) & 0x80004005;
  }
  ExceptionList = local_10;
  return 0x80004005;
}

