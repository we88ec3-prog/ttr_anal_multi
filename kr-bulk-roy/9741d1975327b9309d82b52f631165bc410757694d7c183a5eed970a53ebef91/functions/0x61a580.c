
void FUN_0061a580(void)

{
  int in_EAX;
  int iVar1;
  
  if ((*(int *)(*(int *)(in_EAX + 0xf4) + 0xcc) == 0) ||
     (*(int *)(*(int *)(in_EAX + 0xf4) + 0xd8) == 0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_005f55a0();
  }
  if (iVar1 == 0) {
    FUN_0061b320();
  }
  else if (iVar1 == 2) {
    FUN_00618320(*(undefined4 *)(in_EAX + 0x100));
    return;
  }
  return;
}

