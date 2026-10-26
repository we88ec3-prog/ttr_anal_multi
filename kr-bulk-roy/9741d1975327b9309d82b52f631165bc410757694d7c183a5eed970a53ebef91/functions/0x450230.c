
void FUN_00450230(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00404ed0();
    *(char *)(param_1 + 0x29) = (char)in_ECX[0x29];
    (**(code **)(*param_1 + 0x34))();
  }
  return;
}

