
void FUN_0070e610(void)

{
  int iVar1;
  int *in_EAX;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  if (*(int *)(in_ECX + 0x20) == 0x11f) {
    uVar2 = FUN_006ffec0(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x20) = 0x11f;
  }
  FUN_0070fc00();
  iVar1 = *(int *)(in_ECX + 0x30);
  if (in_EAX[4] == in_EAX[5]) {
    FUN_007122a0();
    goto LAB_0070e6b0;
  }
  FUN_007122a0();
  if (*in_EAX == 0xc) {
    if (in_EAX[4] == in_EAX[5]) goto LAB_0070e6b0;
    if ((int)(uint)*(byte *)(iVar1 + 0x32) <= in_EAX[2]) {
      FUN_00712510();
      goto LAB_0070e6b0;
    }
  }
  FUN_00712630();
LAB_0070e6b0:
  if (*(int *)(in_ECX + 0x10) != 0x5d) {
    FUN_0070d750();
  }
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  if (*(int *)(in_ECX + 0x20) != 0x11f) {
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x20) = 0x11f;
    return;
  }
  uVar2 = FUN_006ffec0(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  return;
}

