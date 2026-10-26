
int FUN_00717120(char *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*in_ECX + 0x38))(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_00891268(0x128);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00717a00();
    }
    _strcpy_s((char *)(iVar1 + 0xc),0x100,param_1);
    *(undefined8 *)(iVar1 + 0x110) = 0x409f640000000000;
    *(undefined4 *)(iVar1 + 0x11c) = 1;
    *(undefined4 *)(iVar1 + 0x120) = 0;
    (**(code **)(*in_ECX + 0x30))(iVar1);
  }
  return iVar1;
}

