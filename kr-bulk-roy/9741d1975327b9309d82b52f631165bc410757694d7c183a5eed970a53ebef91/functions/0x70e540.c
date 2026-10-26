
void FUN_0070e540(void)

{
  int *in_EAX;
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_14 [2];
  undefined4 local_c;
  
  iVar2 = *(int *)(in_ECX + 0x30);
  FUN_007122a0();
  if (*in_EAX == 0xc) {
    if (in_EAX[4] == in_EAX[5]) goto LAB_0070e586;
    if ((int)(uint)*(byte *)(iVar2 + 0x32) <= in_EAX[2]) {
      FUN_00712510();
      goto LAB_0070e586;
    }
  }
  FUN_00712630();
LAB_0070e586:
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  if (*(int *)(in_ECX + 0x20) == 0x11f) {
    uVar1 = FUN_006ffec0(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x10) = uVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x20) = 0x11f;
  }
  local_14[0] = FUN_0070d950();
  local_c = 4;
  FUN_00712090(*(undefined4 *)(in_ECX + 0x30),local_14);
  iVar2 = FUN_00712740();
  in_EAX[3] = iVar2;
  *in_EAX = 9;
  return;
}

