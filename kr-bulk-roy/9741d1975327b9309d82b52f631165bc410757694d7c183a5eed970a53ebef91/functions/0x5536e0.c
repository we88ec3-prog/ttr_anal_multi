
void FUN_005536e0(int param_1,int param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 4))();
  (**(code **)(*in_ECX + 0x20))(*(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58));
  in_ECX[0x10] = param_2;
  uVar1 = FUN_0057ef20();
  FUN_0082f200(param_1 + in_EAX * 0x10,uVar1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  return;
}

