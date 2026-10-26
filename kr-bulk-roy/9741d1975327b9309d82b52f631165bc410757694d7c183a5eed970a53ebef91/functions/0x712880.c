
void FUN_00712880(int *param_1)

{
  int in_EAX;
  uint uVar1;
  undefined4 *unaff_EDI;
  undefined4 uVar2;
  
  switch(*unaff_EDI) {
  case 6:
    if (((*param_1 == 0xc) && ((param_1[2] & 0x100U) == 0)) &&
       ((int)(uint)*(byte *)(in_EAX + 0x32) <= param_1[2])) {
      *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + -1;
    }
    FUN_00712510(param_1,unaff_EDI[2]);
    return;
  case 7:
    uVar1 = FUN_007126a0();
    uVar2 = *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8);
    uVar1 = (unaff_EDI[2] << 0x11 | uVar1) << 6 | 8;
    break;
  case 8:
    uVar1 = FUN_007126a0();
    uVar2 = *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8);
    uVar1 = (unaff_EDI[2] << 8 | uVar1) << 6 | 7;
    break;
  case 9:
    uVar1 = FUN_00712740();
    uVar2 = *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8);
    uVar1 = ((unaff_EDI[3] << 9 | uVar1) << 8 | unaff_EDI[2]) << 6 | 9;
    break;
  default:
    goto switchD_00712899_default;
  }
  FUN_00713370(uVar1,uVar2);
switchD_00712899_default:
  if (((*param_1 == 0xc) && ((param_1[2] & 0x100U) == 0)) &&
     ((int)(uint)*(byte *)(in_EAX + 0x32) <= param_1[2])) {
    *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + -1;
  }
  return;
}

