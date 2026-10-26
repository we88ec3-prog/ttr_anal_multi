
undefined4 * FUN_0073b090(undefined4 *param_1)

{
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ca38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = IDXDefaultObject::vftable;
  param_1[1] = IFrameworkObject::vftable;
  param_1[2] = IFrameworkObject::vftable;
  local_8 = 0;
  *param_1 = Graphics::CTextureBase::vftable;
  param_1[1] = Graphics::CTextureBase::vftable;
  param_1[2] = Graphics::CTextureBase::vftable;
  param_1[0xf] = 7;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  FUN_004026e0(in_EDX,0,0xffffffff);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  ExceptionList = local_10;
  return param_1;
}

