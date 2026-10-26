
void FUN_005801e0(byte param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090abf8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = Graphics::CTexture::vftable;
  in_ECX[1] = Graphics::CTexture::vftable;
  in_ECX[2] = Graphics::CTexture::vftable;
  local_8 = 0;
  piVar1 = (int *)in_ECX[0x11];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
    in_ECX[0x11] = 0;
  }
  FUN_0073b160();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

