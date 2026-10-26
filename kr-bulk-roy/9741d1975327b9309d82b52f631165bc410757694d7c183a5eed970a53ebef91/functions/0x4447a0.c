
undefined4 FUN_004447a0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00545ba0();
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     ((**(code **)(*(int *)**(undefined4 **)(in_ECX + 0xb4) + 8))(), *(int *)(in_ECX + 0xb8) != 0))
  {
    (**(code **)(*(int *)(*(int *)(in_ECX + 0xb8) + 0x38) + 8))();
  }
  return uVar1;
}

