
void FUN_004e7d40(void)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  uint local_8;
  
  iVar1 = in_EAX[0xf];
  while (iVar1 == 0) {
    uVar2 = in_EAX[1] - *in_EAX >> 2;
    local_8 = 0;
    if (uVar2 != 0) {
      do {
        iVar1 = *(int *)(*in_EAX + local_8 * 4);
        if (*(int *)(iVar1 + 0x24) != 0) {
          *(undefined4 *)(iVar1 + 0x24) = 0;
          FUN_004e7db0();
          *(undefined4 *)(iVar1 + 0x28) = 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar2);
    }
    Sleep(100);
    iVar1 = in_EAX[0xf];
  }
  in_EAX[0x10] = 1;
  return;
}

