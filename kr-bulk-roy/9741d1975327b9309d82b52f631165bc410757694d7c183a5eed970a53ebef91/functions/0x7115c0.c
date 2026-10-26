
void FUN_007115c0(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar4 = 0;
  while( true ) {
    FUN_0070d950();
    iVar5 = *(int *)(in_ECX + 0x30);
    if (200 < (int)(*(byte *)(iVar5 + 0x32) + 1 + iVar4)) break;
    uVar1 = FUN_0070da10();
    *(undefined2 *)(iVar5 + 0xac + ((uint)*(byte *)(iVar5 + 0x32) + iVar4) * 2) = uVar1;
    iVar4 = iVar4 + 1;
    iVar5 = in_ECX;
    if (*(int *)(in_ECX + 0x10) != 0x2c) goto LAB_0071165f;
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
    if (*(int *)(in_ECX + 0x20) == 0x11f) {
      uVar3 = FUN_006ffec0(in_ECX + 0x18);
      *(undefined4 *)(in_ECX + 0x10) = uVar3;
    }
    else {
      *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
      *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
      *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
      *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
      *(undefined4 *)(in_ECX + 0x20) = 0x11f;
    }
  }
  FUN_0070d7c0();
LAB_0071165f:
  if (*(int *)(iVar5 + 0x10) == 0x3d) {
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    if (*(int *)(iVar5 + 0x20) == 0x11f) {
      uVar3 = FUN_006ffec0(iVar5 + 0x18);
      *(undefined4 *)(iVar5 + 0x10) = uVar3;
      uVar3 = FUN_0070f1c0(iVar5);
    }
    else {
      *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar5 + 0x20);
      *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar5 + 0x24);
      *(undefined4 *)(iVar5 + 0x20) = 0x11f;
      *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x28);
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x2c);
      uVar3 = FUN_0070f1c0(iVar5);
    }
  }
  else {
    uVar3 = 0;
  }
  FUN_0070dda0(iVar4,uVar3);
  FUN_0070dad0();
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

