
undefined4 FUN_005c6d70(void)

{
  int iVar1;
  int in_EAX;
  int local_c;
  undefined1 local_8 [4];
  
  iVar1 = *(int *)(in_EAX + 0x4c);
  if (iVar1 != 0) {
    FUN_0082ef00(local_8);
    if (local_c != *(int *)(iVar1 + 0xc)) {
      return *(undefined4 *)(local_c + 0x10);
    }
  }
  return 0;
}

