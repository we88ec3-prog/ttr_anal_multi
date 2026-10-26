
void FUN_007bbb00(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f658;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CTextureMgr::vftable;
  CloseHandle((HANDLE)in_ECX[0x19]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x10));
  FUN_007bd600(in_ECX + 0xd);
  FUN_0089120c(in_ECX[0xd],uVar1);
  local_8 = 0;
  FUN_0057ffd0(*(undefined4 *)in_ECX[10],(undefined4 *)in_ECX[10]);
  FUN_0089120c(in_ECX[10]);
  ExceptionList = local_10;
  return;
}

