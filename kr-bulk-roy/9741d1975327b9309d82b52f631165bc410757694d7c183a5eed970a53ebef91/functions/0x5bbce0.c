
void FUN_005bbce0(void)

{
  int in_EAX;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((((*(int *)(in_EAX + 0x2c0) != 0) &&
       ((*(uint *)(*(int *)(in_EAX + 0x2c0) + 0x28) >> 8 & 1) != 0)) &&
      (*(int *)(in_EAX + 0x2c4) != 0)) &&
     ((*(uint *)(*(int *)(in_EAX + 0x2c4) + 0x28) >> 8 & 1) != 0)) {
    FUN_00443da0();
    FUN_00749970(local_10,local_14);
  }
  return;
}

