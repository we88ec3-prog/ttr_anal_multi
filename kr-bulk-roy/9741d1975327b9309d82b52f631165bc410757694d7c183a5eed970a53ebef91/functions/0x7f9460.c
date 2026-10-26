
void FUN_007f9460(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  undefined **local_7c;
  undefined4 local_78;
  int local_74;
  uint local_70;
  undefined4 local_60;
  uint local_5c;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009346ac;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff78);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  uVar1 = FUN_0079a5f0(&DAT_00fb76a8);
  *(undefined4 *)(in_ECX + 4) = uVar1;
  local_5c = 0xf;
  local_60 = 0;
  local_70 = local_70 & 0xffffff00;
  FUN_00402a70("Map/Particle/",0xd);
  piVar3 = (int *)(in_ECX + 8);
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  FUN_00401ed0(piVar3,0,0xffffffff);
  local_78 = *(undefined4 *)(in_ECX + 4);
  local_74 = in_ECX + 0xc4;
  local_7c = `long___cdecl_Graphics::LoadTextureFromFile(IDirect3DDevice9*,char_const*,IDirect3DTexture9**)'
             ::__l2::CreateTextureFromFileBox::vftable;
  iVar2 = FUN_00737d40();
  if (iVar2 < 0) {
    MessageBoxA((HWND)0x0,"D3DXCreateTextureFromFile() - FAILED","PSystem",0);
  }
  else {
    if (0xf < *(uint *)(in_ECX + 0x1c)) {
      piVar3 = (int *)*piVar3;
    }
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_c._0_1_ = 2;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_c._0_1_ = 1;
    }
    if (DAT_00fe3318 != 0) {
      FUN_007ed8d0(local_54,piVar3);
      local_c._0_1_ = 3;
      FUN_007edcd0();
      FUN_007ee080();
    }
    FUN_007f9280(in_ECX);
  }
  if (0xf < local_5c) {
    FUN_0089120c(local_70);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

