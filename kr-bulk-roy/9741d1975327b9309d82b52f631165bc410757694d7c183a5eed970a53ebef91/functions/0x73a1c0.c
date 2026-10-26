
void FUN_0073a1c0(undefined4 *param_1)

{
  uint uVar1;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009194a6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = Graphics::CRenderTargetTexture::vftable;
  param_1[1] = Graphics::CRenderTargetTexture::vftable;
  param_1[2] = Graphics::CRenderTargetTexture::vftable;
  local_8 = 0;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00736880(uVar1);
    _atexit(FUN_00bce6f0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  FUN_00736f40(&local_14);
  if (local_14 != DAT_00fcde34) {
    (**(code **)(*(int *)(*(int *)(local_14 + 0x28) + 8) + 8))();
    (**(code **)(*(int *)(*(int *)(local_14 + 0x28) + 4) + 8))();
    FUN_00736cb0(&DAT_00fcde30,&local_14,local_14);
  }
  FUN_0073b160();
  ExceptionList = local_10;
  return;
}

