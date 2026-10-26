
undefined4 FUN_00713f20(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x30))();
  (**(code **)(*in_ECX + 0x34))(0,2);
  uVar2 = (**(code **)(*in_ECX + 0x30))();
  (**(code **)(*in_ECX + 0x34))(uVar1,0);
  return uVar2;
}

