
void FUN_0072e040(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_00905953;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = TiXmlNode::vftable;
  local_8 = 1;
  puVar1 = (undefined4 *)in_ECX[6];
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    puVar1 = (undefined4 *)puVar1[0x10];
    (*(code *)*puVar2)(1,uVar3);
  }
  if (0xf < (uint)in_ECX[0xd]) {
    FUN_0089120c(in_ECX[8]);
  }
  in_ECX[0xd] = 0xf;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  *in_ECX = TiXmlBase::vftable;
  ExceptionList = local_10;
  return;
}

