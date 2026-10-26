
void FUN_00717050(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_00904858;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = Package::Node::vftable;
  local_8 = 0;
  iVar1 = in_ECX[2];
  while (iVar1 != 0) {
    iVar1 = *(int *)(in_ECX[2] + 8);
    *(undefined4 *)(in_ECX[2] + 8) = 0;
    if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[2])(1,uVar2);
      in_ECX[2] = 0;
    }
    in_ECX[2] = iVar1;
  }
  *in_ECX = Package::IPathObj::vftable;
  ExceptionList = local_10;
  return;
}

