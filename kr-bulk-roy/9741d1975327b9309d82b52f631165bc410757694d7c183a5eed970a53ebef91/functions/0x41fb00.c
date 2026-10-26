
void FUN_0041fb00(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00405370();
    FUN_004026e0(in_ECX + 0x56,0,0xffffffff);
    (**(code **)(*param_1 + 0x34))();
  }
  return;
}

