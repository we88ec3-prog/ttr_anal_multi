
undefined4 * FUN_00730ad0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  _Locimp *p_Var3;
  int iVar4;
  _Lockit local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009067fb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = std::basic_streambuf<char,std::char_traits<char>_>::vftable;
  std::_Mutex::_Mutex((_Mutex *)(param_1 + 1));
  local_8 = 0;
  puVar2 = (undefined4 *)FUN_00891268(4,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    p_Var3 = std::locale::_Init();
    *puVar2 = p_Var3;
    iVar4 = FUN_0087ded7();
    std::_Lockit::_Lockit(local_14,0);
    if (*(int *)(iVar4 + 4) != -1) {
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + 1;
    }
    FUN_0087dd6f();
  }
  param_1[0xe] = puVar2;
  FUN_00730d00();
  ExceptionList = local_10;
  return param_1;
}

