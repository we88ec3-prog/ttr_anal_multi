
void FUN_00712ce0(void)

{
  int *in_EAX;
  int iVar1;
  int in_ECX;
  
  FUN_007122a0();
  switch(*in_EAX) {
  case 1:
  case 3:
    *in_EAX = 2;
    break;
  case 2:
  case 4:
  case 5:
    *in_EAX = 3;
    break;
  case 10:
    FUN_00712a50();
    break;
  case 0xb:
  case 0xc:
    FUN_007124c0();
    if (((*in_EAX == 0xc) && ((in_EAX[2] & 0x100U) == 0)) &&
       ((int)(uint)*(byte *)(in_ECX + 0x32) <= in_EAX[2])) {
      *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
    }
    iVar1 = FUN_00713370(in_EAX[2] << 0x17 | 0x13,*(undefined4 *)(*(int *)(in_ECX + 0xc) + 8));
    in_EAX[2] = iVar1;
    *in_EAX = 0xb;
  }
  iVar1 = in_EAX[4];
  in_EAX[4] = in_EAX[5];
  in_EAX[5] = iVar1;
  FUN_00711e80();
  FUN_00711e80();
  return;
}

