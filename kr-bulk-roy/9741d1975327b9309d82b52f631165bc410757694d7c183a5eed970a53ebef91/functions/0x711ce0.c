
undefined4 FUN_00711ce0(uint param_1,uint param_2,uint param_3)

{
  int in_EAX;
  undefined4 uVar1;
  int in_ECX;
  
  FUN_00713370(((in_EAX << 9 | param_3) << 8 | param_2) << 6 | param_1,
               *(undefined4 *)(*(int *)(in_ECX + 0xc) + 8));
  *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
  uVar1 = FUN_00713370(0x7fff8016,*(undefined4 *)(*(int *)(in_ECX + 0xc) + 8));
  FUN_00711fe0();
  return uVar1;
}

