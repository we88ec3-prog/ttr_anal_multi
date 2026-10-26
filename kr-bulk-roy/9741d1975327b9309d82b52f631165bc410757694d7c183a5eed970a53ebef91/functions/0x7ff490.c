
void FUN_007ff490(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907533;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CFieldObjectInstanceParticle::vftable;
  local_8 = 1;
  iVar1 = in_ECX[9];
  if (iVar1 != 0) {
    FUN_007d8890(iVar1);
    FUN_0089120c(iVar1,uVar2);
    in_ECX[9] = 0;
  }
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2],uVar2);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = IS3D::IRenderable::vftable;
  ExceptionList = local_10;
  return;
}

