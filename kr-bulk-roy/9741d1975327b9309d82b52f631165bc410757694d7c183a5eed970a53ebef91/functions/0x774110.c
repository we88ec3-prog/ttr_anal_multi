
void FUN_00774110(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a5d2;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXShaderManager::vftable;
  local_8 = 1;
  FUN_007741d0(in_ECX);
  if (in_ECX[0x9a] != 0) {
    FUN_0089120c(in_ECX[0x9a],uVar1);
  }
  in_ECX[0x9a] = 0;
  in_ECX[0x9b] = 0;
  in_ECX[0x9c] = 0;
  local_8 = 2;
  FUN_0077dc90(in_ECX + 1);
  local_8 = 3;
  FUN_0057ffd0(*(undefined4 *)in_ECX[0x85],(undefined4 *)in_ECX[0x85]);
  FUN_0089120c(in_ECX[0x85],uVar1);
  ExceptionList = local_10;
  return;
}

