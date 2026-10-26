
undefined1 FUN_005302d0(void)

{
  int in_EAX;
  undefined4 uVar1;
  int in_ECX;
  int local_c;
  undefined1 local_8 [4];
  
  if ((*(int *)(in_EAX + 0x30) != 0) && (*(int *)(*(int *)(in_EAX + 0x30) + 4) != in_ECX)) {
    *(undefined4 *)(in_EAX + 0x30) = 0;
  }
  if (*(int *)(in_EAX + 0x30) == 0) {
    FUN_008438c0(local_8);
    if (local_c == *(int *)(in_EAX + 4)) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(local_c + 0x10);
    }
    *(undefined4 *)(in_EAX + 0x30) = uVar1;
  }
  if (*(int *)(in_EAX + 0x30) != 0) {
    return *(undefined1 *)(*(int *)(in_EAX + 0x30) + 0x25);
  }
  return 0;
}

