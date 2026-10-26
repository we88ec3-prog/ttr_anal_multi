
void FUN_0070de40(void)

{
  undefined4 *puVar1;
  int in_EAX;
  
  puVar1 = *(undefined4 **)(in_EAX + 0x14);
  *(undefined4 *)(in_EAX + 0x14) = *puVar1;
  FUN_0070db10();
  if (*(char *)((int)puVar1 + 9) != '\0') {
    FUN_00713370((uint)*(byte *)(puVar1 + 2) << 6 | 0x23,*(undefined4 *)(*(int *)(in_EAX + 0xc) + 8)
                );
  }
  *(uint *)(in_EAX + 0x24) = (uint)*(byte *)(in_EAX + 0x32);
  *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
  FUN_00711fe0();
  return;
}

