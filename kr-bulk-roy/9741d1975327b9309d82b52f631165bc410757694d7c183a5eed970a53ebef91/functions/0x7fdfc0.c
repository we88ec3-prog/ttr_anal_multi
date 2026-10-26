
void FUN_007fdfc0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905364;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CFieldObjectInstanceSimple::vftable;
  local_8 = 4;
  if ((undefined4 *)in_ECX[0x22] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x22])(1,uVar1);
    in_ECX[0x22] = 0;
  }
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
    in_ECX[0xb] = 0;
  }
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
    in_ECX[10] = 0;
  }
  if (in_ECX[0x1a] != 0) {
    FUN_0089120c(in_ECX[0x1a]);
  }
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  if (in_ECX[0x16] != 0) {
    FUN_0089120c(in_ECX[0x16]);
  }
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  if (in_ECX[0x12] != 0) {
    FUN_0089120c(in_ECX[0x12]);
  }
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = IS3D::IRenderable::vftable;
  ExceptionList = local_10;
  return;
}

