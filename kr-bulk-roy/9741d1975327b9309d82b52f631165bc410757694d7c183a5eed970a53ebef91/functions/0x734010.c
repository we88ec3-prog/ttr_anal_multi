
/* WARNING: Removing unreachable block (ram,0x00734070) */

void FUN_00734010(void)

{
  uint uVar1;
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911ee8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00402160(&DAT_00bed1fc,0);
  local_8 = 0;
  FUN_0073b090(unaff_ESI);
  *unaff_ESI = Graphics::CTexture::vftable;
  unaff_ESI[1] = Graphics::CTexture::vftable;
  unaff_ESI[2] = Graphics::CTexture::vftable;
  unaff_ESI[0x11] = 0;
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

