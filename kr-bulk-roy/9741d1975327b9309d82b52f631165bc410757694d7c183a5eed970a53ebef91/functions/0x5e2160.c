
void FUN_005e2160(void)

{
  int in_ECX;
  undefined4 uVar1;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX == 0) goto LAB_005e234c;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  switch(*(undefined4 *)(in_ECX + 8)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 7:
  case 0x1b:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (0 < *(int *)(in_ECX + 0x58)) {
      FUN_005e1d10(local_30);
    }
    goto switchD_005e21c5_caseD_1e;
  case 5:
    uVar1 = 0x179;
    break;
  case 6:
    uVar1 = 0x17a;
    goto LAB_005e2313;
  case 8:
  case 0xc:
  case 0xe:
    uVar1 = 0x17b;
    break;
  case 9:
  case 10:
    uVar1 = 0x336;
    goto LAB_005e2216;
  case 0xb:
    uVar1 = 0x335;
    goto LAB_005e2216;
  case 0xd:
    uVar1 = 0x17c;
    goto LAB_005e2313;
  case 0xf:
    uVar1 = 0x17d;
    goto LAB_005e2313;
  case 0x10:
  case 0x1c:
    uVar1 = *(undefined4 *)(in_ECX + 0x60);
    FUN_004034e0(uVar1,local_14);
    in_ECX = FUN_00523230(uVar1);
    if (in_ECX != 0) {
      switch(*(undefined4 *)(in_ECX + 8)) {
      case 1:
      case 2:
      case 3:
      case 4:
      case 0x1b:
      case 0x28:
      case 0x29:
      case 0x2a:
      case 0x2b:
        if (0 < *(int *)(in_ECX + 0x58)) {
          FUN_005e1d10(local_30);
        }
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x20:
      case 0x24:
      case 0x25:
        goto switchD_005e21c5_caseD_11;
      }
    }
    goto switchD_005e21c5_caseD_1e;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x19:
  case 0x20:
  case 0x24:
  case 0x25:
switchD_005e21c5_caseD_11:
    uVar1 = 0x1a7;
LAB_005e2216:
    FUN_00585620(uVar1);
    uVar1 = FUN_00585330(uVar1);
    if (0 < *(int *)(in_ECX + 0x5c)) {
      FUN_005e2060(uVar1);
    }
    goto switchD_005e21c5_caseD_1e;
  case 0x14:
    uVar1 = 0x17e;
    break;
  case 0x15:
    uVar1 = 0x17f;
    goto LAB_005e2313;
  case 0x16:
    uVar1 = 0x180;
    break;
  case 0x17:
    uVar1 = 0x181;
    break;
  case 0x18:
    uVar1 = 0x182;
    goto LAB_005e2313;
  case 0x1a:
    uVar1 = 0x17c;
    break;
  case 0x1d:
    uVar1 = 0x186;
    break;
  default:
    goto switchD_005e21c5_caseD_1e;
  case 0x1f:
    uVar1 = 0x187;
    goto LAB_005e2313;
  case 0x26:
    uVar1 = 0x183;
    break;
  case 0x27:
    uVar1 = 0x184;
    goto LAB_005e2313;
  case 0x2c:
    uVar1 = 0x185;
    goto LAB_005e2313;
  case 0x2d:
    uVar1 = 0x188;
    break;
  case 0x2e:
    uVar1 = 0x189;
LAB_005e2313:
    FUN_00585620(uVar1);
    FUN_00585330(uVar1);
    goto LAB_005e2323;
  }
  FUN_00585620(uVar1);
  FUN_00585330(uVar1);
LAB_005e2323:
  FUN_0041f490(local_30);
switchD_005e21c5_caseD_1e:
  FUN_004041f0(local_30,0,0xffffffff);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_005e234c:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

