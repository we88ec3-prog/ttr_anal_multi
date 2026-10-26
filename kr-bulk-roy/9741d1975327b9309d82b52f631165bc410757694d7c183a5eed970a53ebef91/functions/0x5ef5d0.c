
void FUN_005ef5d0(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  undefined4 uVar5;
  int in_ECX;
  short *psVar6;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  psVar6 = *(short **)(in_ECX + 0x180);
  if (psVar6 == (short *)0x0) {
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 0xac) < 8) {
      psVar6 = (short *)(iVar2 + 0x98);
    }
    else {
      psVar6 = *(short **)(iVar2 + 0x98);
    }
  }
  else if (7 < *(uint *)(psVar6 + 10)) {
    psVar6 = *(short **)psVar6;
  }
  local_30[0] = local_30[0] & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  psVar4 = psVar6;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  local_14 = uVar3;
  FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
  local_8 = 0;
  FUN_00757800(local_30);
  if (*(int *)(*(int *)(in_ECX + 0x184) + 8) == 0xb) {
    switch(*(undefined4 *)(*(int *)(in_ECX + 0x184) + 0x5c)) {
    case 0:
      uVar5 = 0;
      break;
    case 1:
    case 2:
    case 3:
      uVar5 = 1;
      break;
    case 4:
    case 5:
      uVar5 = 2;
      break;
    case 6:
    case 7:
      uVar5 = 3;
      break;
    case 8:
    case 9:
    case 10:
      uVar5 = 4;
      break;
    default:
      uVar5 = 5;
    }
    switch(uVar5) {
    case 0:
      *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xffffffff;
      break;
    case 1:
      *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xffffff00;
      break;
    case 2:
      *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xff5aff78;
      break;
    case 3:
      *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xff00bbdd;
      break;
    case 4:
      *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xffe243ff;
      break;
    case 5:
      *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xffb41010;
      break;
    default:
      *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xff6600;
    }
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = 0xffffffff;
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30[0],uVar3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

