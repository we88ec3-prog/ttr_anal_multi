
void FUN_0069a730(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x642) {
    if (uVar1 == 0x641) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x94) + 0x20)) {
        iVar2 = FUN_0040afc0();
        FUN_004054c0();
        FUN_0058b0a0(0xf43b9,*(undefined4 *)(iVar2 + 0x14));
        return;
      }
    }
    else if (uVar1 == 0x578) {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xbc) + 0x20)) {
        iVar2 = FUN_00891268(0x24);
        if (iVar2 == 0) {
          param_1 = 0;
        }
        else {
          param_1 = FUN_005c3c70();
        }
        piVar3 = (int *)(in_ECX + 0x9c);
        iVar2 = 8;
        do {
          if (*(int *)(*piVar3 + 0x254) != -1) {
            FUN_004a8680();
          }
          piVar3 = piVar3 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        FUN_004054c0();
        FUN_0058aa50(param_1);
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xc0) + 0x20)) {
        FUN_0069b670();
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 200) + 0x20)) {
        iVar2 = *(int *)(DAT_00fb1318 + 0xbfe8);
        *(undefined4 *)(iVar2 + 0x78) = 1;
        *(undefined1 *)(iVar2 + 0x80) = 1;
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xcc) + 0x20)) {
        iVar2 = *(int *)(DAT_00fb1318 + 0xbfe8);
        *(undefined4 *)(iVar2 + 0x78) = 2;
        *(undefined1 *)(iVar2 + 0x80) = 1;
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xd0) + 0x20)) {
        iVar2 = *(int *)(DAT_00fb1318 + 0xbfe8);
        *(undefined4 *)(iVar2 + 0x78) = 0xf;
        *(undefined1 *)(iVar2 + 0x80) = 1;
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xd4) + 0x20)) {
        *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + 1;
        if (*(int *)(in_ECX + 0xd8) == 1) {
          FUN_006dd510(0,0,0x43960000);
          *(undefined4 *)(*(int *)(extraout_ECX + 0xbfe8) + 0x7c) = 0x42340000;
        }
        if (*(int *)(in_ECX + 0xd8) == 2) {
          uVar4 = *(undefined4 *)(in_ECX + 0x120);
          FUN_00474e20(uVar4);
          FUN_00474b80(uVar4);
          FUN_006dd510(local_14,local_10,local_c);
          *(undefined4 *)(*(int *)(extraout_ECX_00 + 0xbfe8) + 0x7c) = 0x42200000;
        }
        if (*(int *)(in_ECX + 0xd8) == 3) {
          uVar4 = *(undefined4 *)(in_ECX + 0x120);
          FUN_00474e20(uVar4);
          FUN_00474c60(uVar4);
          FUN_006dd510(local_14,local_10,local_c);
          *(undefined4 *)(*(int *)(extraout_ECX_01 + 0xbfe8) + 0x7c) = 0x42200000;
          *(undefined4 *)(in_ECX + 0xd8) = 0;
          return;
        }
      }
    }
    else if (uVar1 == 0x579) {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x84) + 0x20)) {
        *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) =
             *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) - 3.0;
        FUN_006dd6f0();
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x88) + 0x20)) {
        *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) =
             *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) + 3.0;
        FUN_006dd6f0();
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x8c) + 0x20)) {
        *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) =
             *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) - 0.2;
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x90) + 0x20)) {
        *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) =
             *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) + 0.2;
        return;
      }
    }
  }
  else if ((uVar1 == 0x70a) && (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x98) + 0x20)))
  {
    FUN_0069b610();
  }
  return;
}

