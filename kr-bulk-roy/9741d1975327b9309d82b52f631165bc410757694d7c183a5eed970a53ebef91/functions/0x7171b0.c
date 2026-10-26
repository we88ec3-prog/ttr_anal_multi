
int FUN_007171b0(char *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ccab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = (**(code **)(*in_ECX + 0x1c))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  iVar1 = (**(code **)(*in_ECX + 0x38))(param_1);
  if (iVar1 == 0) {
    iVar2 = FUN_00891268(0x138);
    local_8 = 0;
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar1 = FUN_00717840(iVar2);
    }
    local_8 = 0xffffffff;
    _strcpy_s((char *)(iVar1 + 0xc),0x100,param_1);
    *(undefined8 *)(iVar1 + 0x110) = 0x409f640000000000;
    *(undefined4 *)(iVar1 + 0x130) = 0;
    (**(code **)(*in_ECX + 0x30))(iVar1);
  }
  ExceptionList = local_10;
  return iVar1;
}

