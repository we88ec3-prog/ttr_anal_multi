
void FUN_004c8450(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  
  if (*(int *)(in_EAX + 0x368) != 0) {
    iVar1 = FUN_007b4ed0(*(int *)(in_EAX + 0x368));
    *(undefined4 *)(iVar1 + 4) = param_1;
  }
  return;
}

