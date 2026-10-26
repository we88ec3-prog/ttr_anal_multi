
void FUN_008f3a50(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int unaff_EDI;
  undefined1 local_d8 [12];
  int local_cc;
  int local_a8;
  int local_9c;
  int local_94;
  int local_38;
  int local_28;
  int local_24;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (((*(int *)(in_ECX + 0x70) != -1) && ((param_2 & 8) == 0)) &&
     (iVar1 = FUN_008eb600(param_1,param_2), iVar1 == 0)) {
    if ((*(byte *)(*(int *)(unaff_EDI + 4) + 8) & 1) != 0) {
      FUN_008f3840(local_d8);
      FUN_008f2630(local_d8,param_1,0,1);
      *(int *)(unaff_EDI + 0x38) = local_9c;
      *(int *)(unaff_EDI + 0x3c) = (local_a8 - local_24) + local_28;
      if ((*(int *)(unaff_EDI + 0x28) == 0) && (local_9c != 0)) {
        uVar2 = FUN_008b7f10(local_9c,*(undefined4 *)(in_ECX + 0x10));
        *(undefined4 *)(unaff_EDI + 0x28) = uVar2;
      }
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (((param_2 & 1) == 0) && (*(char *)(in_ECX + 0x6c) == '\0')) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((param_2 & 0x4000) != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar1 = FUN_008f3840(local_d8);
  if (iVar1 != 0) goto LAB_008f3c82;
  *(undefined4 *)(unaff_EDI + 0x48) = 0x6f75746c;
  *(undefined4 *)(unaff_EDI + 0x80) = 0;
  *(undefined4 *)(unaff_EDI + 0x7c) = 0;
  iVar1 = FUN_008f2630(local_d8,param_1,0,0);
  if (iVar1 == 0) {
    if (*(int *)(unaff_EDI + 0x48) == 0x636f6d70) {
      *(undefined4 *)(unaff_EDI + 0x80) = *(undefined4 *)(local_cc + 0x30);
      *(undefined4 *)(unaff_EDI + 0x84) = *(undefined4 *)(local_cc + 0x34);
    }
    else {
      *(undefined4 *)(unaff_EDI + 0x6c) = *(undefined4 *)(local_cc + 0x14);
      *(undefined4 *)(unaff_EDI + 0x70) = *(undefined4 *)(local_cc + 0x18);
      *(undefined4 *)(unaff_EDI + 0x74) = *(undefined4 *)(local_cc + 0x1c);
      *(undefined4 *)(unaff_EDI + 0x78) = *(undefined4 *)(local_cc + 0x20);
      *(undefined4 *)(unaff_EDI + 0x7c) = *(undefined4 *)(local_cc + 0x24);
      *(uint *)(unaff_EDI + 0x7c) = *(uint *)(unaff_EDI + 0x7c) & 0xfffffdff;
      if (local_94 != 0) {
        FUN_008b94d0(unaff_EDI + 0x6c,-local_94,0);
      }
    }
    if ((param_2 & 2) != 0) goto switchD_008f3c2f_caseD_1;
    if (*(char *)(local_38 + 0x151) == '\0') {
switchD_008f3c2f_caseD_2:
      *(uint *)(unaff_EDI + 0x7c) = *(uint *)(unaff_EDI + 0x7c) | 8;
    }
    else {
      switch(*(undefined4 *)(local_38 + 0x154)) {
      case 0:
        *(uint *)(unaff_EDI + 0x7c) = *(uint *)(unaff_EDI + 0x7c) | 0x20;
        break;
      case 1:
        break;
      default:
        goto switchD_008f3c2f_caseD_2;
      case 4:
        *(uint *)(unaff_EDI + 0x7c) = *(uint *)(unaff_EDI + 0x7c) | 0x30;
        break;
      case 5:
        *(uint *)(unaff_EDI + 0x7c) = *(uint *)(unaff_EDI + 0x7c) | 0x10;
      }
    }
switchD_008f3c2f_caseD_1:
    FUN_008eb3b0(param_1);
  }
  if (((param_2 & 1) == 0) && (*(ushort *)(in_ECX + 0xe) < 0x18)) {
    *(uint *)(unaff_EDI + 0x7c) = *(uint *)(unaff_EDI + 0x7c) | 0x100;
  }
LAB_008f3c82:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

