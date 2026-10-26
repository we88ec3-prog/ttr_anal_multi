
int FUN_008cc390(void)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  
  FUN_008ca950(*(uint *)(in_EAX + 0x90) & 0x100);
  uVar1 = *(uint *)(in_EAX + 0x90);
  *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0xc);
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x10) == 0) {
      *(undefined1 *)(in_EAX + 0xb4) = 0;
    }
    else {
      *(undefined1 *)(in_EAX + 0xb4) = 4;
    }
    if ((uVar1 & 0x20) == 0) {
      *(char *)(in_EAX + 0xb4) = *(char *)(in_EAX + 0xb4) + '\x01';
    }
  }
  else {
    *(undefined1 *)(in_EAX + 0xb4) = 2;
  }
  *(byte *)(in_EAX + 0xb5) = ~(byte)(uVar1 >> 9) & 1;
  *(undefined2 *)(in_EAX + 0x3c0) = 0;
  *(short *)(in_EAX + 0x3c2) = *(short *)(in_EAX + 0x68) + -1;
  *(code **)(in_EAX + 0xa4) = FUN_008cba50;
  *(code **)(in_EAX + 0xa8) = FUN_008cbaa0;
  *(code **)(in_EAX + 0xac) = FUN_008cbb80;
  *(code **)(in_EAX + 0xb0) = FUN_008cbd20;
  *(undefined4 *)(in_EAX + 0x400) = 0;
  *(undefined2 *)(in_EAX + 0x38) = *(undefined2 *)(in_EAX + 0x6c);
  *(undefined4 *)(in_EAX + 0x3c) = *(undefined4 *)(in_EAX + 0x74);
  iVar2 = FUN_008cc270(0);
  if (iVar2 == 0) {
    if ((*(char *)(in_EAX + 0xb5) != '\0') && (*(char *)(in_EAX + 0xb4) != '\x02')) {
      *(undefined4 *)(in_EAX + 0x400) = 0;
      *(undefined2 *)(in_EAX + 0x3c0) = 0;
      *(code **)(in_EAX + 0xa4) = FUN_005f5d10;
      *(code **)(in_EAX + 0xa8) = FUN_008cbd40;
      *(code **)(in_EAX + 0xac) = FUN_008cbdc0;
      *(code **)(in_EAX + 0xb0) = FUN_005f5d10;
      *(short *)(in_EAX + 0x3c2) = *(short *)(in_EAX + 0x6c) + -1;
      iVar2 = FUN_008cc270(1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}

