
void FUN_004ef080(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (in_EAX[4] != 0) {
    do {
      puVar1 = in_EAX;
      if (7 < (uint)in_EAX[5]) {
        puVar1 = (undefined4 *)*in_EAX;
      }
      if (*(short *)((int)puVar1 + uVar2 * 2) == 0xb4) {
        puVar1 = in_EAX;
        if (7 < (uint)in_EAX[5]) {
          puVar1 = (undefined4 *)*in_EAX;
        }
        *(undefined2 *)((int)puVar1 + uVar2 * 2) = 0x27;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)in_EAX[4]);
  }
  return;
}

