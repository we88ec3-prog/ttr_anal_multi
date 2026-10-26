
undefined4 FUN_00430c20(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  _Collvec _Var4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907ffb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar3 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    puVar1 = (undefined4 *)FUN_00891268(0x10,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      iVar2 = *(int *)(*param_2 + 0x18);
      if (iVar2 == 0) {
        iVar2 = *param_2 + 0x1c;
      }
      FUN_00431550(iVar2);
      bVar3 = true;
      puVar1[1] = 0;
      *puVar1 = std::num_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>_>_>
                ::vftable;
      _Var4 = __Getcoll();
      *(_Collvec *)(puVar1 + 2) = _Var4;
    }
    local_8 = 0xffffffff;
    *param_1 = (int)puVar1;
    if (bVar3) {
      FUN_00431620();
    }
  }
  ExceptionList = local_10;
  return 4;
}

