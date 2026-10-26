
void FUN_004ff610(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  *(undefined2 *)(in_EAX + 3) = 0;
  *(undefined2 *)((int)in_EAX + 0xe) = 0;
  *(undefined2 *)(in_EAX + 4) = 0;
  *in_EAX = 0;
  *(undefined1 *)((int)in_EAX + 6) = 0;
  in_EAX[2] = 0;
  puVar1 = in_EAX + 6;
  iVar2 = 3;
  do {
    *(undefined2 *)((int)puVar1 + -6) = 0;
    *(undefined2 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 2);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(in_EAX + 0xf) = 0;
  *(undefined2 *)(in_EAX + 0x11) = 0;
  *(undefined2 *)((int)in_EAX + 0x1e) = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0x10] = 0;
  in_EAX[8] = 0;
  *(undefined1 *)(in_EAX + 9) = 0;
  *(undefined4 *)((int)in_EAX + 0x26) = 0;
  *(undefined2 *)((int)in_EAX + 0x2a) = 0;
  in_EAX[0xb] = 0;
  *(undefined2 *)(in_EAX + 0xc) = 0;
  *(undefined1 *)((int)in_EAX + 0x32) = 0;
  iVar2 = 0x10;
  puVar1 = in_EAX + 0x14;
  do {
    puVar1[-2] = 0;
    puVar1[-1] = 0;
    *(undefined2 *)puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

