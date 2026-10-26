
void FUN_00761150(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919152;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00769170(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *in_ECX = FoxUI::FXUIEdit::vftable;
  FUN_00757200(in_ECX + 0x42);
  local_8._0_1_ = 1;
  iVar1 = FUN_00891268(0xc);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006edf00();
  }
  in_ECX[0x52] = uVar2;
  in_ECX[0x53] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x5a] = 0;
  in_ECX[0x51] = 0x100;
  in_ECX[0x57] = 0;
  in_ECX[0x55] = 0;
  in_ECX[0x56] = 0;
  *(undefined2 *)(in_ECX + 0x50) = 0;
  *(undefined1 *)(in_ECX + 0x54) = 1;
  ExceptionList = local_10;
  return;
}

