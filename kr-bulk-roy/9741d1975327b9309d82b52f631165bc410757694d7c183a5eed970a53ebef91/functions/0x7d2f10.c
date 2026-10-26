
void FUN_007d2f10(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905588;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CModel::vftable;
  local_8 = 5;
  if ((undefined4 *)in_ECX[0x1d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1d])(1,uVar2);
    in_ECX[0x1d] = 0;
  }
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
    in_ECX[4] = 0;
  }
  FUN_00797a00();
  if (in_ECX[0x2a] != 0) {
    FUN_0089120c(in_ECX[0x2a]);
  }
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  if (in_ECX[0x26] != 0) {
    FUN_0089120c(in_ECX[0x26]);
  }
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  if (in_ECX[0x22] != 0) {
    FUN_0089120c(in_ECX[0x22]);
  }
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  if (in_ECX[0x1e] != 0) {
    FUN_0089120c(in_ECX[0x1e]);
  }
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  iVar1 = in_ECX[0x19];
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  *in_ECX = IS3D::IRenderable::vftable;
  ExceptionList = local_10;
  return;
}

