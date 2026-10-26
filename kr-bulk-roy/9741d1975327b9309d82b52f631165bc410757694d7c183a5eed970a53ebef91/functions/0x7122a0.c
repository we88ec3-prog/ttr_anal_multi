
void FUN_007122a0(void)

{
  int in_EAX;
  undefined4 uVar1;
  uint uVar2;
  undefined4 *unaff_EDI;
  
  switch(*unaff_EDI) {
  case 6:
    *unaff_EDI = 0xc;
    return;
  case 7:
    uVar2 = unaff_EDI[2] << 0x17 | 4;
    break;
  case 8:
    uVar2 = unaff_EDI[2] << 0xe | 5;
    break;
  case 9:
    if (((unaff_EDI[3] & 0x100) == 0) && ((int)(uint)*(byte *)(in_EAX + 0x32) <= (int)unaff_EDI[3]))
    {
      *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + -1;
    }
    if (((unaff_EDI[2] & 0x100) == 0) && ((int)(uint)*(byte *)(in_EAX + 0x32) <= (int)unaff_EDI[2]))
    {
      *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + -1;
    }
    uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8);
    uVar2 = (unaff_EDI[2] << 9 | unaff_EDI[3]) << 0xe | 6;
    goto LAB_007122cb;
  default:
    return;
  case 0xd:
  case 0xe:
    FUN_00712250();
    return;
  }
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8);
LAB_007122cb:
  uVar1 = FUN_00713370(uVar2,uVar1);
  unaff_EDI[2] = uVar1;
  *unaff_EDI = 0xb;
  return;
}

