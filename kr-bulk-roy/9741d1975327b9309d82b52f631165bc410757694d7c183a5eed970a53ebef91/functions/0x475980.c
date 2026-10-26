
void FUN_00475980(int param_1)

{
  int iVar1;
  int in_ECX;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
      iVar1 = *(int *)(DAT_00fb1318 + 0xbfe8);
      *(undefined4 *)(iVar1 + 0x78) = 1;
      *(undefined1 *)(iVar1 + 0x80) = 1;
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
      iVar1 = *(int *)(DAT_00fb1318 + 0xbfe8);
      *(undefined4 *)(iVar1 + 0x78) = 2;
      *(undefined1 *)(iVar1 + 0x80) = 1;
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
      iVar1 = *(int *)(DAT_00fb1318 + 0xbfe8);
      *(undefined4 *)(iVar1 + 0x78) = 0xf;
      *(undefined1 *)(iVar1 + 0x80) = 1;
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
      *(int *)(in_ECX + 0x11c) = *(int *)(in_ECX + 0x11c) + 1;
      if (*(int *)(in_ECX + 0x11c) == 1) {
        FUN_006dd510(0,0,0x43960000);
        *(undefined4 *)(*(int *)(extraout_ECX + 0xbfe8) + 0x7c) = 0x42340000;
      }
      if (*(int *)(in_ECX + 0x11c) == 2) {
        uVar2 = *(undefined4 *)(in_ECX + 0x118);
        FUN_00474e20(uVar2);
        FUN_00474b80(uVar2);
        FUN_006dd510(local_10,local_c,local_8);
        *(undefined4 *)(*(int *)(extraout_ECX_00 + 0xbfe8) + 0x7c) = 0x42200000;
      }
      if (*(int *)(in_ECX + 0x11c) == 3) {
        uVar2 = *(undefined4 *)(in_ECX + 0x118);
        FUN_00474e20(uVar2);
        FUN_00474c60(uVar2);
        FUN_006dd510(local_10,local_c,local_8);
        *(undefined4 *)(*(int *)(extraout_ECX_01 + 0xbfe8) + 0x7c) = 0x42200000;
        *(undefined4 *)(in_ECX + 0x11c) = 0;
      }
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0x579) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) - 3.0;
      FUN_006dd6f0();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) + 3.0;
      FUN_006dd6f0();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) - 0.2;
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) + 0.2;
      return;
    }
  }
  return;
}

