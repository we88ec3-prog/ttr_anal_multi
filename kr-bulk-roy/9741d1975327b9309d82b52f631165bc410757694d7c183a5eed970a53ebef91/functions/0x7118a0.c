
void FUN_007118a0(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  int local_24;
  int local_1c;
  
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar2 = *(int **)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  if (*(int *)(in_ECX + 0x20) == 0x11f) {
    uVar4 = FUN_006ffec0(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x10) = uVar4;
  }
  else {
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x20) = 0x11f;
  }
  switch(*(int *)(in_ECX + 0x10)) {
  case 0x104:
  case 0x105:
  case 0x106:
  case 0x114:
  case 0x11f:
    break;
  default:
    if (*(int *)(in_ECX + 0x10) != 0x3b) {
      iVar5 = FUN_0070f1c0();
      if ((local_24 == 0xd) || (local_24 == 0xe)) {
        FUN_007121b0(0xffffffff);
        if ((local_24 == 0xd) && (iVar5 == 1)) {
          puVar1 = (uint *)(*(int *)(*piVar2 + 0xc) + local_1c * 4);
          *puVar1 = *puVar1 & 0xffffffdd | 0x1d;
        }
        uVar6 = (uint)*(byte *)((int)piVar2 + 0x32);
        iVar5 = -1;
      }
      else if (iVar5 == 1) {
        uVar6 = FUN_007126a0();
      }
      else {
        FUN_00712630();
        uVar6 = (uint)*(byte *)((int)piVar2 + 0x32);
      }
      goto LAB_00711989;
    }
  }
  iVar5 = 0;
  uVar6 = 0;
LAB_00711989:
  FUN_00713370((iVar5 + 1) * 0x800000 | uVar6 << 6 | 0x1e,*(undefined4 *)(piVar2[3] + 8));
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

