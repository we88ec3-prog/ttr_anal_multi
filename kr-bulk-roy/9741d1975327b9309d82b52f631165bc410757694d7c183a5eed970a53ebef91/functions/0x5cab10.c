
void FUN_005cab10(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ab6d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CIMEManager::vftable;
  local_8 = 1;
  if ((undefined4 *)in_ECX[0xf] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xf])(1,uVar1);
    in_ECX[0xf] = 0;
  }
  if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    in_ECX[0x10] = 0;
  }
  if ((undefined4 *)in_ECX[0x11] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x11])(1);
    in_ECX[0x11] = 0;
  }
  FUN_005cac90(in_ECX);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*(undefined4 *)in_ECX[0x13],(undefined4 *)in_ECX[0x13]);
  FUN_0089120c(in_ECX[0x13]);
  *in_ECX = FoxUI::FXUIIMEManager::vftable;
  ExceptionList = local_10;
  return;
}

