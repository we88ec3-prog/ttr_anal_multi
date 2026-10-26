
void FUN_0054a790(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int local_c;
  undefined1 local_8 [4];
  
  if (*(int *)(in_EAX + 4 + *(int *)(in_EAX + 0x108) * 4) != 0) {
    iVar1 = *(int *)(in_EAX + 4 + *(int *)(in_EAX + 0x108) * 4);
    uVar2 = 0;
    FUN_008438c0(local_8);
    if (local_c != *(int *)(iVar1 + 4)) {
      uVar2 = *(undefined4 *)(local_c + 0x10);
    }
    FUN_00808030(uVar2);
  }
  return;
}

